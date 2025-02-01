#pragma once
#include "helper.h"

#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>

class FileManager
{
public:
  FileManager();
  ~FileManager();
  std::string getHomeDirectory() const;
  std::string getRootDirectory() const;

private:
  std::string m_rootDirectory{};
};
