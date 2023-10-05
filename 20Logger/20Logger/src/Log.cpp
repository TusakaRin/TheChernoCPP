#include "Log.h"
#include <iostream>


void Log::SetLevel(Level level){
	m_LogLevel = level;
}
void Log::Error(const char* message){
    if (m_LogLevel  >= LevelError)
	    std::cout << "[ERROR]: " << message << std::endl;
}
void Log::Warn(const char* message){
    if (m_LogLevel  >= LevelWarning)
	    std::cout << "[WARNING]: " << message << std::endl;
}
void Log::Info(const char* message){
    if (m_LogLevel  >= LevelInfo)
	    std::cout << "[INFO]: " << message << std::endl;
}

