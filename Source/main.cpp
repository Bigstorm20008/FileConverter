

#include <iostream>
#include <chrono>

#include "BrokersDatabase.h"
#include "SourceFileConverter.h"

int main()
{
	BrokersDatabase brokersDatabase;

	std::vector<Broker> brokersInDatatabase;
	brokersInDatatabase.swap( brokersDatabase.getAllBrokers() );
	
	std::chrono::high_resolution_clock::time_point startTimePont = std::chrono::high_resolution_clock::now();
	SourceFileConverter sourceFileConverter;
	for (const auto& broker : brokersInDatatabase){
		sourceFileConverter.convertBrokerFiles(broker);
	}
	
	std::chrono::high_resolution_clock::time_point endTimePont = std::chrono::high_resolution_clock::now();

	std::chrono::milliseconds elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTimePont - startTimePont);
	std::wcout << "Complete in " << elapsedTime.count() << " milliseconds" << std::endl;
	
	return 0;
}