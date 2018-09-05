#include "SourceFileConverter.h"


SourceFileConverter::SourceFileConverter()
{
}


SourceFileConverter::~SourceFileConverter()
{
}


bool SourceFileConverter::convertBrokerFiles(const Broker& broker)
{
	std::wcout << "Convert " << broker.getName() << " source files..." << std::endl;
	const auto& sourceFilesLocations = broker.getSourceFilesLocation();

	WindowsFileSystem windowsFileSystem;
	
	for (const auto& filesLocation : sourceFilesLocations){

		const auto& filesOnLocation = windowsFileSystem.getAllFilesFromPath(filesLocation);

		for (const auto& file : filesOnLocation){

			if (m_sourceFileNameChecker.isCorrectFile(file)){

				std::list<std::wstring> stringsInFile;
				stringsInFile.swap(m_sourceFileReader.getAllStringsFromFile(file));

				std::vector<ConvertedString> convertedStringFromFile;
				convertedStringFromFile.reserve(stringsInFile.size());
				for (const auto& string : stringsInFile){
					if (m_sourceStringChecker.isCorrectString(string)){
						convertedStringFromFile.push_back(ConvertedString { m_sourceFileNameChecker.getCurrencyCode(),
							                                                m_sourceStringChecker.getUnixTimeStamp(),
							                                                m_sourceStringChecker.getBid(),
							                                                m_sourceStringChecker.getAsk(),
							                                                broker.getConvertedFileLocation() });
					}
					else{
						convertedStringFromFile.clear();
						break;
					}
				}

				if (!convertedStringFromFile.empty()){
					for (const auto& convertedString : convertedStringFromFile){
						m_stringsForSaveStore.prepeareForSave(convertedString);
					}
					m_filePrepearedToDelete.push_back(file);
				}
			}
			else{
				std::wcout << "Error!!! " << file << " is not correct" << std::endl;
			}
		}
		
	}
	std::wcout << "Saving converted files..." << std::endl;
	m_stringsForSaveStore.saveAll();

	std::wcout << "Deleting source files..." << std::endl;
	for (const auto& file : m_filePrepearedToDelete){
		DeleteFile(file.c_str());
	}

	return true;
}

