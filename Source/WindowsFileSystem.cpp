#include "WindowsFileSystem.h"


WindowsFileSystem::WindowsFileSystem()
{
}


WindowsFileSystem::~WindowsFileSystem()
{
}


const std::vector<std::wstring> 
WindowsFileSystem::getAllFilesFromPath(const std::wstring& path)
{
	std::vector<std::wstring> directoriesOnPath;

	WIN32_FIND_DATAW wfd;

	const std::wstring pathForAllDirectories = path + L"\\*";

	HANDLE const hFind = FindFirstFileW(pathForAllDirectories.c_str(), &wfd);

	setlocale(LC_ALL, "");

	if (INVALID_HANDLE_VALUE != hFind)
	{
		do
		{
			if ((wcscmp(wfd.cFileName, L".") != 0) &&
			    (wcscmp(wfd.cFileName, L"..") != 0)){
				directoriesOnPath.push_back(path + L"\\" + wfd.cFileName);
			}
		} while (NULL != FindNextFileW(hFind, &wfd));

		FindClose(hFind);
	}

	return directoriesOnPath;
}


