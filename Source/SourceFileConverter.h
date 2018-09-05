#ifndef SOURCE_FILE_CONVERTER_H
#define SOURCE_FILE_CONVERTER_H
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <iostream>
#include <algorithm>

#include "Broker.h"
#include "BrokerSourceFileReader.h"
#include "WindowsFileSystem.h"
#include "SourceFilenameChecker.h"
#include "SourceStringChecker.h"
#include "ConvertedString.h"
#include "StringsForSaveStore.h"


class SourceFileConverter
{
public:
	SourceFileConverter();
	~SourceFileConverter();

	bool convertBrokerFiles(const Broker& broker);

private:
	BrokerSourceFileReader m_sourceFileReader;
	SourceFilenameChecker m_sourceFileNameChecker;
	SourceStringChecker m_sourceStringChecker;
	StringsForSaveStore m_stringsForSaveStore;

	std::list<std::wstring> m_filePrepearedToDelete;
};

#endif // !SOURCE_FILE_CONVERTER_H



