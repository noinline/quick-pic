#include "flag.h"

/*
 ** clang-format off
 *
 * @brief Adds a boolean flag to the flag registry.
 *
 * @param name The long name of the flag (e.g., "--help").
 * @param shortName The short name of the flag (e.g., "-h").
 * @param description A description of the flag for help output.
 *
 ** clang-format on
 */

void
Flag::addBool(const std::string &name, char shortName,
                     const std::string &description)
{
  this->boolFlags[name] = {shortName, description, false};
}

/*
 ** clang-format off
 *
 * @brief Adds a string flag to the flag registry.
 *
 * @param name The long name of the flag (e.g., "--file").
 * @param shortName The short name of the flag (e.g., "-f").
 * @param description A description of the flag for help output.
 *
 ** clang-format on
 */

void
Flag::addString(const std::string &name, char shortName,
                       const std::string &description)
{
  this->stringFlags[name] = {shortName, description, ""};
}

/*
 ** clang-format off
 *
 * @brief Parses command-line arguments into flags and positional arguments.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line argument strings.
 *
 ** clang-format on
 */

void
Flag::parse(int argc, char *argv[])
{
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg[0] == '-') {
      if (arg[1] == '-')
        this->handleLong(arg.substr(2), i, argc, argv);
      else
        this->handleShort(arg.substr(1), i, argc, argv);
    } else
      this->positionalArgs.push_back(arg);
  }
}

/*
 ** clang-format off
 *
 * @brief Checks if a boolean flag is set.
 *
 * @param name The long name of the flag to check.
 *
 * @return True if the flag is set, false otherwise.
 *
 * @throws std::invalid_argument If the flag is not found in the registry.
 *
 ** clang-format on
 */

bool
Flag::isSet(const std::string &name, int line, const std::string &file) const
{
  return (this->boolFlags.find(name) != this->boolFlags.end())
             ? this->boolFlags.at(name).value
             : throw std::invalid_argument(
                   "Unknown flag: " + name +
                   ". At line: " + std::to_string(line) + ". In file: " + file);
}

/*
 ** clang-format off
 *
 * @brief Retrieves the value of a string flag.
 *
 * @param name The long name of the flag to retrieve.
 *
 * @return The value of the flag as a string.
 *
 * @throws std::invalid_argument If the flag is not found in the registry.
 *
 ** clang-format on
 */

std::string
Flag::getValue(const std::string &name, int line,
                  const std::string &file) const
{
  return (this->stringFlags.find(name) != this->stringFlags.end())
             ? this->stringFlags.at(name).value
             : throw std::invalid_argument(
                   "Unknown flag: " + name +
                   ". At line: " + std::to_string(line) + ". In file: " + file);
}

/*
 ** clang-format off
 *
 * @brief Retrieves the list of positional arguments.
 *
 * @return A const reference to the vector of positional arguments.
 *
 ** clang-format on
 */

const std::vector<std::string> &
Flag::getPositionalArgs() const
{
  return this->positionalArgs;
}

/*
 ** clang-format off
 *
 * @brief Prints a help message listing all registered flags.
 *
 * @param argv The array of command-line argument strings
 *             (used to display the program name).
 *
 ** clang-format on
 */

void
Flag::printHelp(char *argv[]) const
{
  std::cout << "Usage: " << argv[0] << " [options] [arguments]" << '\n';
  std::cout << "Options:" << '\n';
  for (const auto &[name, flag] : this->boolFlags)
    std::cout << "\t-" << flag.shortName << ", --" << name << "\t\t"
              << flag.description << '\n';

  for (const auto &[name, flag] : this->stringFlags)
    std::cout << "\t-" << flag.shortName << ", --" << name << " <value>\t"
                << flag.description << '\n';
}

/*
 ** clang-format off
 *
 * @brief Handles long-form flags (e.g., "--help").
 *
 * @param flag The flag name without the leading "--".
 * @param i The current index in the argv array.
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line argument strings.
 *
 ** clang-format on
 */

void 
Flag::handleLong(const std::string &flag, int &i, int argc, char *argv[])
{
  if (this->boolFlags.find(flag) != this->boolFlags.end())
    this->boolFlags[flag].value = true;
  else if (this->stringFlags.find(flag) != this->stringFlags.end()) {
    if (i + 1 < argc && argv[i + 1][0] != '-')
      this->stringFlags[flag].value = argv[++i];
    else
      std::cerr << "Error: Missing value for flag: --" << flag << '\n';
  } else
    std::cerr << "Error: Unknown flag: --" << flag << '\n';
}

/*
 ** clang-format off
 *
 * @brief Handles short-form flags (e.g., "-h").
 *
 * @param flag The flag name without the leading "-".
 * @param i The current index in the argv array.
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line argument strings.
 *
 ** clang-format on
 */

void
Flag::handleShort(const std::string &flag, int &i, int argc,
                         char *argv[])
{
  for (unsigned long int f = 0; f < flag.length(); ++f) {
    char c = flag[f];
    bool found = false;
    for (const auto &[name, boolFlag] : this->boolFlags) {
      if (boolFlag.shortName == c) {
        this->boolFlags[name].value = true;
        found = true;
        break;
      }
    }
    if (!found)
      for (const auto &[name, stringFlag] : this->stringFlags) {
        if (stringFlag.shortName == c) {
          if (i + 1 < argc && argv[i + 1][0] != '-')
            this->stringFlags[name].value = argv[++i];
          else
            std::cerr << "Error: Missing value for flag: -" << c << '\n';
          found = true;
          break;
        }
      }
    if (!found)
      std::cerr << "Error: Unknown flag: -" << c << '\n';
  }
}
