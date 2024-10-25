#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <string>

class Logger {
 public:
  static void error(const std::string &message);
  static void warn(const std::string &message);
  static void debug(const std::string &message);
};

#endif
