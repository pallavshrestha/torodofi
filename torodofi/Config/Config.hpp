#pragma once

#include <fstream>
#include <stdexcept>
#include <string>

#include "../logic.hpp"
#include "../types.hpp"

namespace toro {
namespace config {

const std::string var_delimiter = ": ";

class Config {
protected:
  types::config _config;
  std::string _filename;

  // Check if line is a valid config line and set specified values
  bool _validate_and_pass_line(std::string aline);

public:
  // Constructor
  Config();
  // Constructor gets file name to read config from it
  Config(std::string afilename);

  // Read configuration from afilename
  void readFile(std::string afilename);

  // Getters
  types::config getConfig();
};

} // namespace config
} // namespace toro