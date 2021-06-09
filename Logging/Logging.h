#pragma once
#include<ostream>
#ifdef LOGGING_EXPORTS
#define API_LOGGER __declspec(dllexport)
#else 
#define API_LOGGER __declspec(dllimport)
#endif //LOGGING_ESPORTS

class API_LOGGER Logger
{
public:
	enum class Level
	{
		Debug,
		Info,
		Warning,
		Error
	};

public:
	Logger(std::ostream& out, Level minLogLevel = Level::Warning);
	void Log(const std::string& message, Level level);
private:
	std::ostream& m_out;
	Level m_mingLogLevel;

};

