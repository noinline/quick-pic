#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

namespace helper {
/*
 ** clang-format off
 *
 * @brief Checks an assertion and throws an exception if the assertion fails.
 *
 * @tparam T The type of the assertion. Can be a boolean or any type that can be
 *           evaluated in a boolean context.
 *
 * @tparam E The type of exception to throw. Defaults to `std::runtime_error`.
 *
 * @param assertion The assertion to check. If false or evaluates to false, an
 *                  exception is thrown.
 *
 * @param msg An optional error message to include in the exception. If empty,
 *            a generic error message is used.
 *
 * @throws E If the assertion fails, an exception of type `E` is thrown with a
 *           detailed error message.
 *
 ** clang-format on
 */

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

/*
 ** clang-format off
 *
 * @brief A wrapper for `assertCheck`.
 *
 * @tparam T The type of the assertion. Can be a boolean or any type that can be
 *           evaluated in a boolean context.
 *
 * @param assertion The assertion to check. If false or evaluates to false, an
 *                  exception is thrown.
 *
 * @param msg An optional error message to include in the exception. If empty,
 *            a generic error message is used.
 *
 * @throws std::runtime_error If the assertion fails, an exception is thrown
 *                            with a detailed error message.
 *
 ** clang-format on
 */

template <typename T = bool>
void
assert(T &&assertion, std::string msg = {}, const char *file = __FILE__,
       int line = __LINE__)
{
  assertCheck<T>(std::forward<T>(assertion), file, line, msg);
}
} // namespace helper
