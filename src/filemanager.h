#pragma once
#include "helper.h"

#include <pwd.h>
#include <sys/stat.h>
#include <unistd.h>

class FileManager
{
public:
  std::string getHomeDirectory() const;
  std::string getRootDirectory() const;
  bool        setRootDirectory(const std::string &dir);

private:
  std::string m_rootDirectory{};
};
