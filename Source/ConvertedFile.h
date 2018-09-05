#ifndef CONVERTED_FILE_H
#define CONVERTED_FILE_H

#include <list>

#include "ConvertedString.h"

class ConvertedFile
{
public:
	ConvertedFile(const std::wstring& brokerConvertedFilesPath,
		          const std::wstring& yearFolder,
		          const std::wstring& monthFolder,
		          const std::wstring& filename);

	~ConvertedFile();

	void addString(const ConvertedString& convertedString);

	const std::wstring& getBrokerConvertedFilesPath()const;
	const std::wstring& getFilename()const;
	const std::wstring& getYearFolder()const;
	const std::wstring& getMonthFolder()const;

	void saveOnHdd()const;

private:
	std::wstring m_brokerConvertedFilesPath;
	std::wstring m_yearFolder;
	std::wstring m_monthFolder;
	std::wstring m_filename;

	std::list<ConvertedString> m_stringsInFile;
};

#endif // !CONVERTED_FILE_H



