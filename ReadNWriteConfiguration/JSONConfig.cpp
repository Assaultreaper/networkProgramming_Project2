#include "JSONConfig.h"

JSONConfig::~JSONConfig()
{
}

bool JSONConfig::ReadData(const std::string& filePath, sLanguageData& LanguageOutput, Preferences& preferencesOut, std::vector<sLanguageData>& languagesOutput)
{
	using namespace rapidjson;

	FILE* fp = 0;
	fopen_s(&fp, filePath.c_str(), "rb");

	Document Doc;
	char readBuffer[65536];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	Doc.ParseStream(is);

	ParseJSONData(Doc, LanguageOutput);

	fclose(fp);

	return true;
}

bool JSONConfig::WriteData(const std::string& filePath, const sLanguageData& LanguageOutput, const Preferences& preferencesOut, const std::vector<sLanguageData>& languagesOutput)
{
	return true;
}

bool JSONConfig::SetValue(const rapidjson::Value& jsonValue, std::string& stringOut)
{
	if (!jsonValue.IsString())
	{
		return false;
	}
	else
	{
		stringOut = jsonValue.GetString();
		return true;
	}
}

bool JSONConfig::ParseJSONData(const rapidjson::Value& languageObject, sLanguageData& languageOutput)
{
	using namespace rapidjson;

	if (!languageObject.IsObject())
	{
		return false;
	}

	bool result = true;

	if (!SetValue(languageObject["Preference"], languageOutput.PrefenceFile))
	{
		result = false;
	}

	const Value& preferencefileValue = languageObject["Preference"];

	if (preferencefileValue.IsString())
	{
		languageOutput.PrefenceFile = preferencefileValue.GetString();
	}
	else
	{
		result = false;
	}

	const Value& LanguageFilesValue = languageObject["LanguageFiles"];

	if (LanguageFilesValue.IsArray())
	{
		int numLanguages = LanguageFilesValue.Size();
		for (int index = 0; index < numLanguages; index++)
		{
			const Value& languageValue = LanguageFilesValue[index];
			if (languageValue.IsString())
			{
				languageOutput.LanguageFiles.push_back(languageValue.GetString());
			}
		}
	}
	return result;
}
