#ifndef SOURCE_STRING_CHECKER_H
#define SOURCE_STRING_CHECKER_H

#include <string>


class SourceStringChecker
{
public:
	SourceStringChecker();
	~SourceStringChecker();

	bool isCorrectString(const std::wstring& sourceString);

	const std::wstring& getUnixTimeStamp()const;
	const std::wstring& getBid()const;
	const std::wstring& getAsk()const;

private:
	const wchar_t m_limiter;
	const size_t m_correctTimeStampLenght;
	std::wstring m_unixTimeStamp;
	std::wstring m_bid;
	std::wstring m_ask;

	bool checkTimeStamp()const;
	bool checkBidAndAsk()const;
};

#endif // !SOURCE_STRING_CHECKER_H



