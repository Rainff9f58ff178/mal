//
// Created by rain on 23-2-28.
//

#ifndef MAL_LOG_H
#define MAL_LOG_H
#include<iostream>
#include <chrono>
#define CONSOLE_DEBUG(str) mal::ConsoleLogger::instance()->debug(str,__FILE__,__LINE__);
#define CONSOLE_INFO(str) mal::ConsoleLogger::instance()->info(str,__FILE__,__LINE__);
#define CONSOLE_WARN(str) mal::ConsoleLogger::instance()->warn(str,__FILE__,__LINE__);
#define CONSOLE_FATAL(str) mal::ConsoleLogger::instance()->fatal(str,__FILE__,__LINE__);
#define CONSOLE_ERROR(str) mal::ConsoleLogger::instance()->error(str,__FILE__,__LINE__);






namespace mal{
    class Logger {
    public:
        virtual ~Logger();
        virtual void debug(const char* str,const char* file_name,int line)=0;
        virtual void info(const char* str,const char* file_name,int line)=0;
        virtual void error(const char* str,const char* file_name,int line)=0;
        virtual void warn(const char* str,const char* file_name,int line)=0;
        virtual void fatal(const char* str,const char* file_name,int line)=0;
    };
    class FileLogger:public Logger{
    public:

    };
    class ConsoleLogger:public Logger{
    public:
        static  ConsoleLogger* logger;

        static ConsoleLogger* instance();
        ConsoleLogger();
        ~ConsoleLogger() override ;

        void debug(const char *str, const char *file_name, int line) override;

        void info(const char *str, const char *file_name, int line) override;

        void error(const char *str, const char *file_name, int line) override;

        void warn(const char *str, const char *file_name, int line) override;

        void fatal(const char *str, const char *file_name, int line) override;

    };

}

#endif //MAL_LOG_H
