#include "SourceStringChecker.h"


SourceStringChecker::SourceStringChecker() : m_limiter { ';' },
											 m_correctTimeStampLenght{ 10 },
											 m_unixTimeStamp{},
											 m_bid{},
											 m_ask{}
{
}


SourceStringChecker::~SourceStringChecker()
{
}


bool SourceStringChecker::isCorrectString(const std::wstring& sourceString)
{
	bool isCorrect = false;

	const auto firstLimiterPosition = sourceString.find_first_of(m_limiter);
	const auto lastLimiterPosition = sourceString.rfind(m_limiter);

	m_unixTimeStamp = { sourceString, 0, firstLimiterPosition };
	m_ask = { sourceString, firstLimiterPosition + 1, lastLimiterPosition - firstLimiterPosition - 1};
	m_bid = { sourceString, lastLimiterPosition + 1, sourceString.length() - lastLimiterPosition };

	if (checkTimeStamp() && checkBidAndAsk())
		isCorrect = true;

	if (!isCorrect){
		m_unixTimeStamp.clear();
		m_ask.clear();
		m_bid.clear();
	}

	return isCorrect;
}


bool SourceStringChecker::checkTimeStamp()const
{
	bool isCorrect = false;
	std::wstring correctSymbolsInTimeStamp = { L"01234567890" };

	if (m_unixTimeStamp.length() == m_correctTimeStampLenght){
		const auto founded = m_unixTimeStamp.find_first_not_of(correctSymbolsInTimeStamp);
		if (founded == std::wstring::npos){
			isCorrect = true;
		}
	}

	return isCorrect;
}

bool SourceStringChecker::checkBidAndAsk()const
{
	bool isCorrect = false;
	std::wstring correctSymbolsInBidAndAsk = { L"01234567890." };

	const auto foundedInBid = m_bid.find_first_not_of(correctSymbolsInBidAndAsk);
	const auto foundedInAsk = m_ask.find_first_not_of(correctSymbolsInBidAndAsk);

	if (foundedInAsk == std::wstring::npos &&
		foundedInBid == std::wstring::npos){
		isCorrect = true;
	}

	return isCorrect;
}


const std::wstring& SourceStringChecker::getUnixTimeStamp()const
{
	return m_unixTimeStamp;
}


const std::wstring& SourceStringChecker::getBid()const
{
	return m_bid;
}


const std::wstring& SourceStringChecker::getAsk()const
{
	return m_ask;
}