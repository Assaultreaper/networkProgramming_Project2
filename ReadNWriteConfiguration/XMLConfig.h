#pragma once
#include "iConfigurationReaderWriter.h"

// Rapid XML
#include <rapidxml/rapidxml.hpp>

class XMLConfig: public iConfigurationReaderWriter
{
public:
	virtual ~XMLConfig();

	virtual bool ReadData(const std::string& filePath,
			sLanguageData& LanguageOutput,
			Preferences& preferencesOut,
			std::vector<sLanguageData>& languagesOutput);

	virtual bool WriteData(const std::string& filePath,
		const sLanguageData& LanguageOutput,
		const Preferences& preferencesOut,
		const std::vector<sLanguageData>& languagesOutput);
};

