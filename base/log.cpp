//
// Created by rain on 23-2-28.
//

#include "log.h"
mal::ConsoleLogger* mal::ConsoleLogger::logger= nullptr;

mal::ConsoleLogger::ConsoleLogger():Logger(){
    if(this->logger== nullptr){
        logger=this;
    }
}
mal::ConsoleLogger::~ConsoleLogger() {
    if(logger!= nullptr){
        logger= nullptr;
    }
}
mal::ConsoleLogger* mal::ConsoleLogger::instance() {
    if(logger== nullptr)
        return new mal::ConsoleLogger();
    return mal::ConsoleLogger::logger;
}

void mal::ConsoleLogger::debug(const char *str, const char *file_name, int line) {
    if(this->logger){
        auto now = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(now);

        std::cout << "DEBUG-> " <<" "<<str<<" "<<file_name<<":"<<line <<" "<<  std::ctime(&end_time);

    }
}

void mal::ConsoleLogger::info(const char *str, const char *file_name, int line) {
    if(this->logger){
        auto now = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(now);

        std::cout << "INFO-> " <<" "<<str<<" "<<file_name<<":"<<line <<" "<<  std::ctime(&end_time);

    }
}

void mal::ConsoleLogger::error(const char *str, const char *file_name, int line) {
    if(this->logger){
        auto now = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(now);
        std::cout << "ERROR->" <<" "<<str<<" "<<file_name<<":"<<line <<" "<<  std::ctime(&end_time);
    }
}

void mal::ConsoleLogger::warn(const char *str, const char *file_name, int line) {
    if(this->logger){
        auto now = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(now);

        std::cout << "WARN-> " <<" "<<str<<" "<<file_name<<":"<<line <<" "<<  std::ctime(&end_time);

    }
}

void mal::ConsoleLogger::fatal(const char *str, const char *file_name, int line) {
    if(this->logger){
        auto now = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(now);

        std::cout << "FATAL->" <<" "<<str<<" "<<file_name<<":"<<line <<" "<<  std::ctime(&end_time);

    }
}

mal::Logger::~Logger() {

}
