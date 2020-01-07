/*!
 * -------------------------------------------
 * Copyright (c) 2019, Horizon Robotics, Inc.
 * All rights reserved.
 * \File     test.cpp
 * \Author   zhuo.wang
 * \Mail     zhuo.wang@horizon.ai
 * \Version  0.0.0.1
 * \Date     2019/12/29
 * \Brief    implement of test.cpp
 * \DO NOT MODIFY THIS COMMENT, \
 * \WHICH IS AUTO GENERATED BY EDITOR
 * -------------------------------------------
 */

#include <iostream>
#include <thread>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>

using namespace std;


class ThreadTest {
public:
    ThreadTest()
    {
        sem_init(&sendSem, 0, 0);
    }

    void thread1()
    {
        int i = 0;
        while (true) {
            cout << "thread1: " << i++ << endl;
            sem_post(&sendSem);
            usleep(1000000);
        }
    }

    void thread2()
    {
        int i = 0;
        while (true) {
            sem_wait(&sendSem);
            cout << "thread2: " << i++ << endl;
        }
    }

private:
    sem_t sendSem;
};

int main()
{
//    ThreadTest test;
//
//    thread t1(&ThreadTest::thread1, &test);
//    thread t2(&ThreadTest::thread2, &test);
//
//    t1.join();
//    t2.join();

//    auto test1 = new ThreadTest;
//
//    auto t3 = new thread(&ThreadTest::thread1, test1);
//    auto t4 = new thread(&ThreadTest::thread2, test1);
//
//
//    t3->join();
//    t4->join();

//以下用法不通
//    ThreadTest test;
//
//    thread t1(&ThreadTest::thread1, &test);
//    thread t2(&ThreadTest::thread2, &test);
//
//    t1.detach();
//    t2.detach();

//    int ccc = 0;
//    sem_t sendSem;
//    sem_init(&sendSem, 0, 0);
//    thread t5([&]() {
//        while(true) {
//            cout<<"thread5: "<<ccc++<<endl;
//            sem_post(&sendSem);
//            usleep(1000000);
//        }
//    });
//
//    thread t6([&]() {
//        while(true) {
//            sem_wait(&sendSem);
//            cout<<"thread6: "<<ccc++<<endl;
//        }
//    });
//
//    t5.join();
//    t6.join();

    string test1("qwererasdf");
    auto sp = "er";

    cout << test1 << endl;

    cout << test1.find(sp) << endl;

    cout << test1.substr(0, test1.find(sp)) << endl;
    cout << test1.substr(test1.find(sp)) << endl;

    cout << test1.substr(0, test1.find(sp) + strlen(sp)) << endl;

    cout << "length: " << test1.length() << endl;

    test1 = test1.substr(test1.find(sp) + strlen(sp));

    cout << "length: " << test1.length() << endl;

    cout << test1 << endl;

    return 0;
}