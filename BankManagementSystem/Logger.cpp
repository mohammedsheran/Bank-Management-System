
#include <filesystem>
#include <fstream>

#include "Logger.h"
#include "Libraries/Date.h"

bool Logger::enabled{ true };

void Logger::_Write(const std::string& logLevel, const std::string& message)
{
	if (!enabled)
	{
		return;
	}

	std::filesystem::create_directories("Logs");

	std::string fileName{ "Logs/" + Date::FormatDate(Date(), "yyyy-mm-dd") + ".log" };

	std::ofstream file{ fileName, std::ios::app };

	if (!file)
	{
		return;
	}

	file << Date::GetDateTime()
		<< " | " << logLevel
		<< " | " << message
		<< '\n';
}

void Logger::Info(const std::string& message)
{
	_Write("Info", message);
}

void Logger::Warning(const std::string& message)
{
	_Write("Warning", message);
}

void Logger::Error(const std::string& message)
{
	_Write("Error", message);
}