#pragma once

#include <string>

class Logger
{
private:
	static void _Write(const std::string& logLevel, const std::string& message);
public:
	static bool enabled;

	static void Info(const std::string& message);
	static void Warning(const std::string& message);
	static void Error(const std::string& message);
};