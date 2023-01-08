#include "../include/Log.h"

LOG::LOG()
    : m_LogLevel(LOG::LevelError) {};

void LOG::setLevel(Level level)
{
m_LogLevel = level;
};

void LOG::getLog(Level level, const char *Message, const char *ErrorCode)
{
    if(m_LogLevel >= level)
    {
        std::cout << Message << ErrorCode << std::endl;
    }
}
