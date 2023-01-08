#ifndef HYDROMOTION_LOG_H
#define HYDROMOTION_LOG_H
#include <iostream>
struct LOG
{
public:
    enum Level
    {
        LevelError = 0, LevelWarning, LevelInfo
    };
private:
    Level m_LogLevel;
public:
    LOG();
    void setLevel(Level level);
    void getLog(Level level, const char* Message, const char* ErrorCode);
};
#endif //HYDROMOTION_LOG_H
