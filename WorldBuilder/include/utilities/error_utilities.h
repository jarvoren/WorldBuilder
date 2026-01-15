#include "descriptors/enums.h"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <string>

class Logger
{
  public:
	Logger(const Logger &) = delete;
	Logger &operator=(const Logger &) = delete;

	static Logger &GetInstance()
	{
		static Logger instance;
		return instance;
	}

	void Log(LogLevel level, const std::string &message);
	std::string GetTimestamp();
	std::string GetLevelString(LogLevel level);

  private:
	Logger() { logFile.open("app.log", std::ios::app); }

	~Logger()
	{
		if (logFile.is_open())
		{
			logFile.close();
		}
	}

	std::ofstream logFile;
	std::mutex logMutex;
};

static inline std::string ErrorCodeToString(ErrorCode ec)
{
	switch (ec)
	{
	case ErrorCode::Succes:
		return "Success";
	case ErrorCode::GeneralFailure:
		return "GeneralFailure";
	}

	return "Unknown";
};

static inline void LogEvent(std::string file, int line, std::string message, LogLevel level)
{
	message = std::to_string(line) + " " + file + " " + message;
	Logger::GetInstance().Log(level, message);
};

#define log_definition(message, level) LogEvent(__FILE__, __LINE__, message, level);

#define log_info(message) log_definition(message, LogLevel::INFO);
#define log_warning(message) log_definition(message, LogLevel::WARNING);
#define log_error(message) log_definition(message, LogLevel::ERROR);

#define log_error_code(error_code)                                                                 \
	if (error_code != ErrorCode::Succes)                                                           \
		log_error(ErrorCodeToString(error_code));
