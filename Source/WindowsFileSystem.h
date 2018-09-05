#ifndef WINDOWS_FILE_SYSTEM_H
#define WINDOWS_FILE_SYSTEM_H

#include <Windows.h>

#include <vector>
#include <string>

class WindowsFileSystem
{
public:
	WindowsFileSystem();
	~WindowsFileSystem();

	const std::vector<std::wstring> getAllFilesFromPath(const std::wstring& path);
	//const std::vector<std::wstring>& getAllFilesFromFolder(const std::wstring& pathToFolder);
};


#endif // !WINDOWS_FILE_SYSTEM_H


