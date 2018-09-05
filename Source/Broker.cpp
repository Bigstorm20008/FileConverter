#include "Broker.h"


Broker::Broker() : m_name{}, m_sourceFilesLocations{}, m_convertedFilesLocation{}
{
}


Broker::~Broker()
{
}


void Broker::setName(const std::wstring& brokerName)
{
	m_name = brokerName;
}


void Broker::setConvertedFileLocation(const std::wstring& convertedFileLocation)
{
	m_convertedFilesLocation = convertedFileLocation;
}


void Broker::setSourceFileLocations(std::vector<std::wstring>& sourceFilesLocations)
{
	m_sourceFilesLocations.swap(sourceFilesLocations);
}


const std::vector<std::wstring>& 
Broker::getSourceFilesLocation() const
{
	return m_sourceFilesLocations;
}


const std::wstring& 
Broker::getConvertedFileLocation()const
{
	return m_convertedFilesLocation;
}


const std::wstring& Broker::getName()const
{
	return m_name;
}