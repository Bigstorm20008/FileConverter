#include "StringsForSaveStore.h"


StringsForSaveStore::StringsForSaveStore()
{
}


StringsForSaveStore::~StringsForSaveStore()
{
}


void StringsForSaveStore::prepeareForSave(const ConvertedString& convertedString)
{
	if (m_filesForSave.empty()){
		addFileForConvertedString(convertedString);
	}
	else{
		auto pred = [&](const ConvertedFile & convertedFile) {
					return convertedFile.getBrokerConvertedFilesPath() == convertedString.getBrokerConvertedFilesPath() &&
						   convertedFile.getFilename() == convertedString.getFilenameForSave() &&
						   convertedFile.getYearFolder() == convertedString.getYear() &&
						   convertedFile.getMonthFolder() == convertedString.getMonth(); };

		auto founded = std::find_if(m_filesForSave.begin(), m_filesForSave.end(), pred);

		if (founded != m_filesForSave.cend()){
			founded->addString(convertedString);
		}
		else{
			addFileForConvertedString(convertedString);
		}
	}
}


void StringsForSaveStore::addFileForConvertedString(const ConvertedString& convertedString)
{
	ConvertedFile convertedFile{ convertedString.getBrokerConvertedFilesPath(),
		                         convertedString.getYear(),
		                         convertedString.getMonth(),
		                         convertedString.getFilenameForSave() };

	convertedFile.addString(convertedString);
	m_filesForSave.push_back(convertedFile);
}


void StringsForSaveStore::saveAll()
{
	for (const auto& file : m_filesForSave){
		file.saveOnHdd();
	}
	
}