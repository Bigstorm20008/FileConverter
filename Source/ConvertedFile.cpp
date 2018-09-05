#include "ConvertedFile.h"


ConvertedFile::ConvertedFile(const std::wstring& brokerConvertedFilesPath,
	                         const std::wstring& yearFolder,
	                         const std::wstring& monthFolder,
	                         const std::wstring& filename) :
							 m_brokerConvertedFilesPath( brokerConvertedFilesPath ),
							 m_yearFolder( yearFolder ),
							 m_monthFolder( monthFolder ),
							 m_filename( filename ),
							 m_stringsInFile{}
{
}


ConvertedFile::~ConvertedFile()
{
}

void ConvertedFile::addString(const ConvertedString& convertedString)
{
	m_stringsInFile.push_back(convertedString);
}


const std::wstring& ConvertedFile::getBrokerConvertedFilesPath()const
{
	return m_brokerConvertedFilesPath;
}


const std::wstring& ConvertedFile::getFilename()const
{
	return m_filename;
}


const std::wstring& ConvertedFile::getYearFolder()const
{
	return m_yearFolder;
}


const std::wstring& ConvertedFile::getMonthFolder()const
{
	return m_monthFolder;
}


void ConvertedFile::saveOnHdd()const
{
	std::wstring pathToYear{ m_brokerConvertedFilesPath + L"\\" + m_yearFolder };
	CreateDirectory(pathToYear.c_str(), NULL);
	std::wstring pathToMonth{ pathToYear + L"\\" + m_monthFolder };
	CreateDirectory(pathToMonth.c_str(), NULL);


	std::wofstream  fout;
	fout.open(pathToMonth + L"\\" + m_filename, std::ios_base::app);

	if (fout.is_open()){
		for (const auto& string : m_stringsInFile){
			fout << string.getStringForSave();
		}
	}


	fout.close();
}
