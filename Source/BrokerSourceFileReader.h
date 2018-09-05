#ifndef SOURCE_FILE_READER_H
#define SOURCE_FILE_READER_H

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <list>

//#include "SourceStringConverter.h"

class BrokerSourceFileReader
{
public:
	BrokerSourceFileReader();
	~BrokerSourceFileReader();

	
	
	std::list<std::wstring> getAllStringsFromFile(const std::wstring& pathToFile);
	
private:
	bool m_isOpen;
	std::wifstream m_streamToRead;
	
	void closeFile();
	bool openFile(const std::wstring& pathToFile);
	
};

#endif // !SOURCE_FILE_READER_H



