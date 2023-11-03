#pragma once

#include "iConfigurationReaderWriter.h"

//Rapid JSON 
#include <rapidjson/filewritestream.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/document.h>

class JSONConfig:public iConfigurationReaderWriter
{
public:
	virtual ~JSONConfig();
	virtual bool ReadData(const std::string& filePath,
		sLanguageData& LanguageOutput,
		Preferences& preferencesOut,
		std::vector<sLanguageData>& languagesOutput);
	virtual bool WriteData(const std::string& filePath,
		const sLanguageData& LanguageOutput,
		const Preferences& preferencesOut,
		const std::vector<sLanguageData>& languagesOutput);
private:
	bool SetValue(const rapidjson::Value& jsonValue, std::string& stringOut);
	bool ParseJSONData(const rapidjson::Value& languageObject, sLanguageData& languageOutput);
};

