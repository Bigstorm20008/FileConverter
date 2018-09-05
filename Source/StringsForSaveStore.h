#ifndef STRINGS_FOR_SAVE_STORE_H
#define STRINGS_FOR_SAVE_STORE_H

#include <vector>
#include <algorithm>
#include <fstream>

#include "ConvertedFile.h"
#include "ConvertedString.h"

class StringsForSaveStore
{
public:
	StringsForSaveStore();
	~StringsForSaveStore();

	void prepeareForSave(const ConvertedString& convertedString);
	void saveAll();
private:
	std::vector<ConvertedFile> m_filesForSave;

	void addFileForConvertedString(const ConvertedString& convertedString);



};


#endif // !STRINGS_FOR_SAVE_STORE_H



