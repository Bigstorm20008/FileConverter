#include "BrokersDatabase.h"


BrokersDatabase::BrokersDatabase()
{
}


BrokersDatabase::~BrokersDatabase()
{
	m_brokerDatabase.Close();
}

void BrokersDatabase::connect()
{
	if (!m_brokerDatabase.IsOpen()){
		std::wcout << "Connecting to database....." << std::endl;
		if (m_brokerDatabase.Open(L"BrokersDatasource")){
			std::wcout << "Database connected!" << std::endl;
		}
	}
}


std::vector<Broker> 
BrokersDatabase::getAllBrokers()
{
	connect();

	std::wcout << "Get data..." << std::endl;

	std::vector<std::pair<std::wstring, std::wstring>> brokersIdAndNames;
	brokersIdAndNames.swap(getAllBrokersIdAndNames());

	size_t brokersInDatabase = brokersIdAndNames.size();
	std::vector<Broker> brokers;
	brokers.reserve(brokersInDatabase);

	for (const auto& brokerName : brokersIdAndNames){
		Broker broker;
		broker.setName(brokerName.second);
		broker.setConvertedFileLocation(getConvertedFilesLocationByBrokerId(brokerName.first));
		broker.setSourceFileLocations(getSourceFileLocationsByBrokerId(brokerName.first));
		brokers.push_back(broker);
	}

	return brokers;
}


std::vector<std::pair<std::wstring, std::wstring>> 
BrokersDatabase::getAllBrokersIdAndNames()
{
	CRecordset recordset(&m_brokerDatabase);
	
	std::wstring sqlQuery{ L"SELECT [BrokerId],[BrokerName] FROM [dbo].[BrokersList]" };
	recordset.Open(CRecordset::forwardOnly, sqlQuery.c_str(), CRecordset::readOnly);
	
	long recordCount = recordset.GetRecordCount();
	std::vector<std::pair<std::wstring, std::wstring>> brokersIdAndNames;
	brokersIdAndNames.reserve(recordCount);

	CODBCFieldInfo fieldinfo;
	CDBVariant var;
	short fieldCount = recordset.GetODBCFieldCount();
	while (!recordset.IsEOF())
	{	
		std::pair<std::wstring, std::wstring> brokerIdAndName;

		for (unsigned short index = 0; index < fieldCount; ++index){
			recordset.GetFieldValue(index, var);
			recordset.GetODBCFieldInfo(index, fieldinfo);
			if (fieldinfo.m_strName == "BrokerId"){
				brokerIdAndName.first = std::to_wstring(var.m_iVal);
			}
			else if (fieldinfo.m_strName == "BrokerName"){
				brokerIdAndName.second = var.m_pstringW->GetString();
			}
		}

		brokersIdAndNames.push_back(brokerIdAndName);
		recordset.MoveNext();
	}

	recordset.Close();

	return brokersIdAndNames;
}


std::wstring 
BrokersDatabase::getConvertedFilesLocationByBrokerId(const std::wstring& brokerId)
{
	CRecordset recordset(&m_brokerDatabase);
	std::wstring sqlQuery = L"SELECT [PathToConvertedFiles] FROM [dbo].[ConvertedFiles] WHERE BrokerId = " + brokerId;

	recordset.Open(CRecordset::forwardOnly, sqlQuery.c_str(), CRecordset::readOnly);

	std::wstring pathToBrokerConvertedFiles{};
	

	CDBVariant var;
	
	recordset.GetFieldValue(short(0), var);
	pathToBrokerConvertedFiles.assign((var.m_pstringW)->GetString());
		
	recordset.Close();

	return pathToBrokerConvertedFiles;
}


std::vector<std::wstring> 
BrokersDatabase::getSourceFileLocationsByBrokerId(const std::wstring& brokerId)
{
	CRecordset recordset(&m_brokerDatabase);
	std::wstring sqlQuery = L"SELECT [PathToSourceFiles] FROM [dbo].[SourceFiles] WHERE BrokerId = " + brokerId;

	recordset.Open(CRecordset::forwardOnly, sqlQuery.c_str(), CRecordset::readOnly);

	long recordCount = recordset.GetRecordCount();
	std::vector<std::wstring> brokerSourceFilesLocations;
	brokerSourceFilesLocations.reserve(recordCount);

	CDBVariant var;

	while (!recordset.IsEOF())
	{
		recordset.GetFieldValue(short(0), var);
		brokerSourceFilesLocations.push_back((var.m_pstringW)->GetString());
		recordset.MoveNext();
	}

	recordset.Close();

	return brokerSourceFilesLocations;
}
