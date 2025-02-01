#pragma once
#include "helper.h"

class Flag
{
public:
  void addBool(const std::string &name, char shortName,
               const std::string &description);
  void addString(const std::string &name, char shortName,
                 const std::string &description);
  void parse(int argc, char *argv[]);
  bool isSet(const std::string &name, int line, const std::string &file) const;
  std::string                     getValue(const std::string &name, int line,
                                           const std::string &file) const;
  const std::vector<std::string> &getPositionalArgs() const;
  void                            printHelp(char *argv[]) const;

private:
  struct Bool
  {
    char        shortName;
    std::string description;
    bool        value;
  };

  struct String
  {
    char        shortName;
    std::string description;
    std::string value;
  };
  std::unordered_map<std::string, Bool>   boolFlags;
  std::unordered_map<std::string, String> stringFlags;
  std::vector<std::string>                positionalArgs;

  void handleLong(const std::string &flag, int &i, int argc, char *argv[]);
  void handleShort(const std::string &flag, int &i, int argc, char *argv[]);
};

#define ADD_BOOL(flag, name, description)                                      \
  do {                                                                         \
    flag.addBool(name, name[0], description);                                  \
  } while (0)

#define ADD_STRING(flag, name, description)                                    \
  do {                                                                         \
    flag.addString(name, name[0], description);                                \
  } while (0)

#define IS_SET(flag, name)    flag.isSet(name, __LINE__, __FILE__)
#define GET_VALUE(flag, name) flag.getValue(name, __LINE__, __FILE__)
