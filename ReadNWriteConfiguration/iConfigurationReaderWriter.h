#pragma once

#include "definations.h"

class iConfigurationReaderWriter
{
public:
	virtual ~iConfigurationReaderWriter() {}
	virtual bool ReadData(const std::string& filePath, 
		sLanguageData& LanguageOutput, 
		Preferences& preferencesOut, 
		std::vector<sLanguageData>& languagesOutput) = 0;
	virtual bool WriteData(const std::string& filePath,
		const sLanguageData& LanguageOutput,
		const Preferences& preferencesOut,
		const std::vector<sLanguageData>& languagesOutput) = 0;
};

