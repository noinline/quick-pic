#include "filemanager.h"

/*
 ** clang-format off
 *
 * @brief Constructs a FileManager object.
 *
 * Initializes the root directory to `~/.config/quick-pic/`. The home directory
 * is retrieved using `getHomeDirectory()`. If the home directory cannot be
 * retrieved, an exception is thrown.
 *
 ** clang-format on
 */

FileManager::FileManager()
{
  this->m_rootDirectory = this->getHomeDirectory() + "/.config/quick-pic/";
}

/*
 ** clang-format off
 *
 * @brief Destructs the FileManager object.
 *
 * Clears the root directory by setting it to an empty string. I felt silly and
 * did this for cleanup. Does not perform any file system operations.
 *
 ** clang-format on
 */

FileManager::~FileManager()
{
  this->m_rootDirectory = "";
}

/*
 ** clang-format off
 *
 * @brief Retrieves the home directory of the current user.
 *
 * Uses `getpwuid` and `geteuid` to retrieve the home directory. If the home
 * directory cannot be retrieved, an exception is thrown.
 *
 * @return The home directory as a `std::string`.
 *
 * @throws std::runtime_error If the home directory cannot be retrieved.
 *
 ** clang-format on
 */

std::string
FileManager::getHomeDirectory(void) const
{
  struct passwd *pwd = getpwuid(static_cast<uid_t>(geteuid()));
  return (pwd != nullptr)
             ? std::string(pwd->pw_dir)
             : throw std::runtime_error("Failed to get Home Directory.\n");
}

/*
 ** clang-format off
 *
 * @brief Retrieves the root directory configured for the FileManager.
 *
 * The root directory is set during construction and typically points to
 * `~/.config/quick-pic/`. This function provides read-only access to the
 * root directory.
 *
 * @return The root directory as a `std::string`.
 *
 ** clang-format on
 */

std::string
FileManager::getRootDirectory(void) const
{
  return this->m_rootDirectory;
}
