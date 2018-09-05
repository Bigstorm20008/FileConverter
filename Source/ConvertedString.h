#pragma once

#include <fstream>
#include <string>
#include <ctime>
#include <Windows.h>

class ConvertedString
{
public:
	explicit ConvertedString(const std::wstring& currencyCode,
		                     const std::wstring& unixTimeStamp,
					         const std::wstring& bid,
					         const std::wstring& ask,
							 const std::wstring& brokerConvertedFilesPath);

	~ConvertedString();

	const std::wstring& getBrokerConvertedFilesPath()const;
	const std::wstring& getFilenameForSave()const;
	const std::wstring& getYear()const;
	const std::wstring& getMonth()const;

	const std::wstring getStringForSave()const;
private:
	std::wstring m_currencyCode;
	std::wstring m_bid;
	std::wstring m_ask;
	std::wstring m_year;
	std::wstring m_month;
	std::wstring m_day;
	std::wstring m_hours;
	std::wstring m_minutes;
	std::wstring m_seconds;

	std::wstring m_brokerConvertedFilesPath;
	std::wstring m_filenameForSave;

	void setDateTime(const std::wstring& unixTimeStamp);
	
};

