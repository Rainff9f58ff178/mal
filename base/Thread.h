//
// Created by rain on 2022/6/18.
//

#ifndef LINUXNETWORKPROGRAMCHENSHUO_THREAD_H
#define LINUXNETWORKPROGRAMCHENSHUO_THREAD_H
#include<functional>
#include<string>
#include<thread>
namespace mal{

    typedef std::function<void()> ThreadFunc;

    class Thread {
    public:
        Thread(const ThreadFunc& cb,std::string name);
        void start();

        auto get_id();
    private:
        ThreadFunc threadFunc_;
        std::string name_;
        std::jthread t_;
    };
}


#endif //LINUXNETWORKPROGRAMCHENSHUO_THREAD_H
