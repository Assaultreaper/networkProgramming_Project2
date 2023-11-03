#pragma once
#include <string>
#include <vector>
#include <map>

struct sLanguageData
{
	std::string PrefenceFile;
	std::vector < std::string> LanguageFiles;
};

struct sLanguage
{
	std::string LanguageName;
	std::map<std::string, std::string> keyValues;
};

struct Preferences
{

};