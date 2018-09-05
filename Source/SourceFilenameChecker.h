#ifndef SOURCE_FILENAME_CHECKER_H
#define SOURCE_FILENAME_CHECKER_H

#include <string>
#include <algorithm>

class SourceFilenameChecker
{
public:
	SourceFilenameChecker();
	~SourceFilenameChecker();

	bool isCorrectFile(const std::wstring& filename);
	const std::wstring& getCurrencyCode()const;
private:
	const static size_t m_correctLenght;
	const static unsigned short m_currencyCodeLenght;
	const static unsigned short m_unixTimeStampLenght;
	const static size_t m_timeStampStartPosition;
	const static wchar_t m_limiter;
	const static size_t m_limiterPosition;
	const static std::wstring m_extention;

	std::wstring m_currencyCode;

	bool isCorrectLenght(const std::wstring& filename) const;
	bool isCorrectExtention(const std::wstring& filename) const;
	bool isCorrectLimiterPosition(const std::wstring& filename) const;
	bool isCorrectCurrencyCode(const std::wstring& filename);
	bool isCorrectUnixTimeStamp(const std::wstring& filename) const;
};

#endif // !SOURCE_FILENAME_CHECKER_H



