#include "filemanager.h"

std::string
FileManager::getHomeDirectory(void) const
{
  struct passwd *pwd = getpwuid(static_cast<uid_t>(geteuid()));
  return (pwd != nullptr)
             ? std::string(pwd->pw_dir)
             : throw std::runtime_error("Failed to get Home Directory.\n");
}

std::string
FileManager::getRootDirectory(void) const
{
  return this->m_rootDirectory;
}

bool
FileManager::setRootDirectory(const std::string &dir)
{
  struct stat st
  {};
  this->m_rootDirectory += dir.c_str();
  if (stat(dir.c_str(), &st) == -1) {
    if (mkdir(dir.c_str(), 0700) == -1)
      return false;
    return true;
  }
  return false;
}
