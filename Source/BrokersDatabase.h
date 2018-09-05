#ifndef BROKERS_DATABASE_H
#define BROKERS_DATABASE_H

#include "afxdb.h"

#include <iostream>
#include <list>
#include <vector>

#include "Broker.h"

class BrokersDatabase
{
public:
	BrokersDatabase();
	~BrokersDatabase();
	std::vector<Broker> getAllBrokers();
	
private:
	CDatabase m_brokerDatabase;

	void connect();

	std::vector<std::pair<std::wstring, std::wstring>> getAllBrokersIdAndNames();
	std::wstring getConvertedFilesLocationByBrokerId(const std::wstring& brokerId);
	std::vector<std::wstring> getSourceFileLocationsByBrokerId(const std::wstring& brokerId);
	
};


#endif // !BROKERS_DATABASE_H


