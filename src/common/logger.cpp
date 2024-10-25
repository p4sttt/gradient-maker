#include "common/logger.hpp"

void Logger::error(const std::string &message) {
  std::cerr << "=== Runtime Program Error ===" << std::endl;
  std::cerr << message << std::endl;
}

void Logger::warn(const std::string &message) {
  std::cerr << "* Warning Be Caption *" << std::endl;
  std::cerr << message << std::endl;
}

void Logger::debug(const std::string &message) {
  std::cerr << "[DEBUG] " << message << std::endl;
}