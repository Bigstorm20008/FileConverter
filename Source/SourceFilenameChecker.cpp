#include "SourceFilenameChecker.h"

const size_t SourceFilenameChecker::m_correctLenght               { 21 };
const unsigned short SourceFilenameChecker::m_currencyCodeLenght  { 6 };
const unsigned short SourceFilenameChecker::m_unixTimeStampLenght { 10 };
const size_t SourceFilenameChecker::m_timeStampStartPosition      { 7 };
const wchar_t SourceFilenameChecker::m_limiter                    { '_' };
const size_t SourceFilenameChecker::m_limiterPosition             { 6 };
const std::wstring SourceFilenameChecker::m_extention             { L".tck" };

SourceFilenameChecker::SourceFilenameChecker() : m_currencyCode{}
{
}


SourceFilenameChecker::~SourceFilenameChecker()
{
}


bool SourceFilenameChecker::isCorrectFile(const std::wstring& filename)
{
	bool isCorrect = false;

	const auto fileNameStartPos = filename.rfind('\\');
	if (fileNameStartPos != std::wstring::npos){
		const std::wstring fileNameWithoutPath{ filename, fileNameStartPos + 1, filename.length() - fileNameStartPos - 1 };
		isCorrect = isCorrectLenght(fileNameWithoutPath) &&
			        isCorrectExtention(fileNameWithoutPath) &&
			        isCorrectLimiterPosition(fileNameWithoutPath) &&
			        isCorrectCurrencyCode(fileNameWithoutPath) &&
			        isCorrectUnixTimeStamp(fileNameWithoutPath);
	}

	if (!isCorrect)
		m_currencyCode.clear();

	return isCorrect;
}


bool SourceFilenameChecker::isCorrectLenght(const std::wstring& filename) const
{
	return filename.length() == m_correctLenght;
}


bool SourceFilenameChecker::isCorrectExtention(const std::wstring& filename) const
{
	bool isCorrectExtention = false;

	const size_t dotPosition = filename.rfind('.');
	if (dotPosition != std::wstring::npos){
		std::wstring currentFileExtention{ filename, dotPosition, filename.length() - dotPosition };
		if (currentFileExtention.compare(m_extention) == 0){
			isCorrectExtention = true;
		}
	}
	
	return isCorrectExtention;
}


bool SourceFilenameChecker::isCorrectLimiterPosition(const std::wstring& filename) const
{
	return filename[m_limiterPosition] == m_limiter;
}


bool SourceFilenameChecker::isCorrectCurrencyCode(const std::wstring& filename)
{
	bool isCorrect = false;

	auto pos = std::find_if(filename.cbegin(), 
		                    filename.cbegin() + m_currencyCodeLenght,
		                    [](wchar_t c)->bool{ return !iswalpha(c) && !iswupper(c); });

	if (pos >= filename.cbegin() + m_currencyCodeLenght){
		isCorrect = true;
	}

	if (isCorrect){
		m_currencyCode.clear();
		m_currencyCode = { filename, 0, m_currencyCodeLenght };
	}

	return isCorrect;
}


bool SourceFilenameChecker::isCorrectUnixTimeStamp(const std::wstring& filename) const
{
	bool isCorrect = false;
	const auto timeStampBeginPosition = filename.cbegin() + m_timeStampStartPosition;
	const auto timeStampEndPosition = timeStampBeginPosition + m_unixTimeStampLenght;

	auto pos = std::find_if(timeStampBeginPosition,
		                    timeStampEndPosition,
		                    [](wchar_t c)->bool{ return !iswdigit(c); });

	if (pos >= timeStampEndPosition){
		isCorrect = true;
	}

	return isCorrect;
}


const std::wstring& SourceFilenameChecker::getCurrencyCode()const
{
	return m_currencyCode;
}
