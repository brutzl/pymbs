#include "Filesystem.h"

bool filesystem::exists(std::string path)
{
	// try to open file, if it exists, the handle is cast to true
    std::ifstream file(path.c_str());
	bool exists = file.is_open();
    // under Linux, directories & files are treated the same
    // under Windows, we need to check directories seperately
    #ifdef _WIN32
        DWORD folder = GetFileAttributes(path.c_str());
        if (folder == INVALID_FILE_ATTRIBUTES)
            return false;
        bool folder_exists = (folder & FILE_ATTRIBUTE_DIRECTORY) > 0;
        exists = exists || folder_exists;
    #endif
    return exists;
}

void filesystem::create_directory(std::string new_path)
{
    #ifdef _WIN32
        CreateDirectory(new_path.c_str(), NULL);
    #else
        mkdir(new_path.c_str(), 0777);
    #endif
}

void filesystem::copy(std::string src_path, std::string dst_path)
{
    std::ifstream source(src_path.c_str());
    std::ofstream destination(dst_path.c_str());
    destination << source.rdbuf();
}

void filesystem::remove(std::string path)
{
    std::remove(path.c_str());
}

bool filesystem::is_regular(std::string path)
{
    if (!exists(path))
        return false;
    else
    {
    #ifdef _WIN32
		DWORD attributes = GetFileAttributes(path.c_str());
		return (FILE_ATTRIBUTE_NORMAL & attributes) || 
               (FILE_ATTRIBUTE_ARCHIVE & attributes);
    #else
        struct stat s;
        stat(path.c_str(), &s);
        return S_IFREG & s.st_mode;
    #endif
    }
}
