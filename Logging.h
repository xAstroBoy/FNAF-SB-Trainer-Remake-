#pragma once

#include <string>
#include "Utilities/Logger.h"

class Logging
{
public:
  std::string modName;

  void SetModName(std::string _modName) { modName = _modName; }
  void Info(std::string message);
  void Error(std::string message);
  void Print(std::string message);
  void Warn(std::string message);
};

void Logging::Info(std::string message)
{
  Log::Info("[" + modName + "][Core] " + message);
}

void Logging::Error(std::string message)
{
  Log::Error("[" + modName + "][Core] " + message);
}

void Logging::Print(std::string message)
{
  Log::Print("[" + modName + "][Core] " + message);
}

void Logging::Warn(std::string message)
{
  Log::Warn("[" + modName + "][Core] " + message);
}
