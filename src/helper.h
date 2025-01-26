#pragma once
#include <stdexcept>
#include <string>

namespace helper {
template <typename T = bool, typename E = std::runtime_error>
void
assertCheck(T &&assertion, const char *file, int line, std::string msg = {})
{
  if constexpr (!std::is_same_v<T, bool>) {
    if (!assertion && !msg.empty())
      throw E("Assertion failed: " + msg + std::string(" At line: ") +
              std::to_string(line) + std::string(".") +
              std::string(" In file: ") + file);
    else if (!assertion && msg.empty())
      throw E("Assertion failed with unexpected error!" +
              std::string(" At line: ") + std::to_string(line) +
              std::string(".") + std::string(" In file: ") + file);
  } else {
    if (!assertion && !msg.empty())
      throw E("Assertion failed: " + msg + std::string(" At line: ") +
              std::to_string(line) + std::string(".") +
              std::string(" In file: ") + file);
    else if (!assertion && msg.empty())
      throw E("Assertion failed with unexpected error!" +
              std::string(" At line: ") + std::to_string(line) +
              std::string(".") + std::string(" In file: ") + file);
  }
}

template <typename T = bool>
void
assert(T &&assertion, const char *file = __FILE__, int line = __LINE__,
       std::string msg = {})
{
  try {
    assertCheck<T>(std::forward<T>(assertion), file, line, msg);
  } catch (const std::exception &e) {
    throw std::runtime_error(e.what());
  }
}
} // namespace helper
