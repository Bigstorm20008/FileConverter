#include "ConvertedString.h"


ConvertedString::ConvertedString(const std::wstring& currencyCode,
	                             const std::wstring& unixTimeStamp,
	                             const std::wstring& bid,
	                             const std::wstring& ask,
								 const std::wstring& brokerConvertedFilesPath)
{
	m_currencyCode = currencyCode;
	m_bid = bid;
	m_ask = ask;
	m_brokerConvertedFilesPath = brokerConvertedFilesPath;
	
	setDateTime(unixTimeStamp);

	m_filenameForSave = m_currencyCode + L"_" + m_year + m_month + m_day + L".tck";
}


ConvertedString::~ConvertedString()
{
}


void ConvertedString::setDateTime(const std::wstring& unixTimeStamp)
{
	std::time_t time_t = (std::stoi(unixTimeStamp));
	struct tm tm_struct;
	gmtime_s(&tm_struct, &time_t);

	m_year = std::move(std::to_wstring(tm_struct.tm_year + 1900));
	
	
	if (tm_struct.tm_mon < 10){
		m_month = std::move(L"0" + std::to_wstring(tm_struct.tm_mon + 1));
	}
	else{
		m_month = std::move(std::to_wstring(tm_struct.tm_mon + 1));
	}

	
	if (tm_struct.tm_mday < 10){
		m_day = std::move(L"0" + std::to_wstring(tm_struct.tm_mday));
	}
	else{
		m_day = std::move(std::to_wstring(tm_struct.tm_mday));
	}


	
	if (tm_struct.tm_hour < 10){
		m_hours = std::move(L"0" + std::to_wstring(tm_struct.tm_hour));
	}
	else{
		m_hours = std::move(std::to_wstring(tm_struct.tm_hour));
	}

	
	if (tm_struct.tm_min < 10){
		m_minutes = std::move(L"0" + std::to_wstring(tm_struct.tm_min));
	}
	else{
		m_minutes = std::move(std::to_wstring(tm_struct.tm_min));
	}


	
	if (tm_struct.tm_sec < 10){
		m_seconds = std::move(L"0" + std::to_wstring(tm_struct.tm_sec));
	}
	else{
		m_seconds = std::move(std::to_wstring(tm_struct.tm_sec));
	}

}


const std::wstring& ConvertedString::getBrokerConvertedFilesPath()const
{
	return m_brokerConvertedFilesPath;
}


const std::wstring& ConvertedString::getFilenameForSave()const
{
	return m_filenameForSave;
}


const std::wstring& ConvertedString::getYear()const
{
	return m_year;
}


const std::wstring& ConvertedString::getMonth()const
{
	return m_month;
}


const std::wstring ConvertedString::getStringForSave()const
{
	return m_currencyCode + L"," + m_year + m_month + m_day + L"," + m_hours + m_minutes + m_seconds + L"," + m_ask + L"," + m_bid + L'\n';
}