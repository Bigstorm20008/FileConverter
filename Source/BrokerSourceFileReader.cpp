#include "BrokerSourceFileReader.h"


BrokerSourceFileReader::BrokerSourceFileReader() : m_isOpen{ false }
{
}


BrokerSourceFileReader::~BrokerSourceFileReader()
{
	closeFile();
}

bool BrokerSourceFileReader::openFile(const std::wstring& pathToFile)
{
	if (m_isOpen){
		m_streamToRead.close();
		m_isOpen = false;
	}

	m_streamToRead.open(pathToFile);

	return m_isOpen = m_streamToRead.is_open();
}


void BrokerSourceFileReader::closeFile()
{
	if (m_isOpen){
		m_streamToRead.close();
		m_isOpen = false;
	}
}


std::list<std::wstring> BrokerSourceFileReader::getAllStringsFromFile(const std::wstring& pathToFile)
{
	openFile(pathToFile);

	std::wstring sourceLine;
	std::list<std::wstring> allLines;

	while (std::getline(m_streamToRead, sourceLine))
	{
		allLines.push_back(sourceLine);
	}
		
	closeFile();
	return allLines;
}