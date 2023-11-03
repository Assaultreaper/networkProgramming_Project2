#include <iostream>
#include "definations.h"

#define USE_JSON_CONFIGURATION
//#define USE_XML_CONFIGURATION

#ifdef USE_XML_CONFIGURATION;
#include "XMLConfig.h"
#endif

#ifdef USE_JSON_CONFIGURATION
#include "JSONConfig.h"
#endif 

int main()
{
	printf("Intializing Application\n");
	
	iConfigurationReaderWriter* configReaderWriter = 0;

#ifdef USE_JSON_CONFIGURATION
	configReaderWriter = new JSONConfig();
	std::string fileName = "LanguageData.json";
#endif 


#ifdef USE_XML_CONFIGURATION;
	configReaderWriter = new XMLConfig();
	std::string fileName = "LanguageData.xml";
#endif

	Preferences preferencesOutput;
	sLanguageData languageOutput;
	std::vector<sLanguageData> LangDataOutput;

	if(configReaderWriter->ReadData(fileName, languageOutput, preferencesOutput, LangDataOutput))
	{
		printf("Success");
	}
	else
	{
		printf("Failed");
	}


	return 0;
}