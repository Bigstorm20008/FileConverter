#ifndef BROKER_H
#define BROKER_H

#include <vector>
#include <string>

class Broker
{
public:
	Broker();
	~Broker();

	void setName(const std::wstring& brokerName);
	void setConvertedFileLocation(const std::wstring& convertedFileLocation);
	void setSourceFileLocations(std::vector<std::wstring>& sourceFilesLocations);

	const std::vector<std::wstring>& getSourceFilesLocation() const;
	const std::wstring& getConvertedFileLocation()const;
	const std::wstring& getName()const;
private:
	std::wstring m_name;
	std::vector<std::wstring> m_sourceFilesLocations;
	std::wstring m_convertedFilesLocation;
};

#endif // !BROKER_H


