#include "utilities/error_utilities.h"

std::string Logger::GetLevelString(LogLevel level)
{
	switch (level)
	{
	case LogLevel::INFO:
		return "INFO";
	case LogLevel::WARNING:
		return "WARNING";
	case LogLevel::ERROR:
		return "ERROR";
	default:
		return "UNKNOWN";
	}
}

std::string Logger::GetTimestamp()
{
	auto now = std::chrono::system_clock::now();
	auto time = std::chrono::system_clock::to_time_t(now);
	std::stringstream ss;
	ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
	return ss.str();
}

void Logger::Log(LogLevel level, const std::string &message)
{
	std::lock_guard<std::mutex> lock(logMutex);

	std::string levelStr = GetLevelString(level);
	std::string timestamp = GetTimestamp();

	std::string formated = "[" + timestamp + "] [" + levelStr + "] " + message;

	std::cout << formated << '\n';

	if (logFile.is_open())
	{
		logFile << "[" << timestamp << "] [" << levelStr << "] " << message << std::endl;
	}
}
