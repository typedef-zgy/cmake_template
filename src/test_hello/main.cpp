/*
 * main.cpp
 *
 *  Created on: 四 12/12 00:35:59 2019
 *      Author: zhangguangyu
 */

#include "hello/hello.h"
#include <thread>
#include <mutex>
#include "zmutex.h"
#include <iostream>

using namespace zlib::zthread;

ZMutex *gMutex = NULL;
int gCount = 0;

void func1() {
  while(gCount < 10)
  {
      ZLockGuard guard(*gMutex);
      std::cout << std::this_thread::get_id() << "--" << ++gCount << std::endl;
      //sleep(10);
  }
}

void func2() {
  while(gCount < 10)
  {
      ZLockGuard guard(*gMutex);
      std::cout << std::this_thread::get_id() << "--" << ++gCount << std::endl;
      //sleep(10);
  }
}

int main() {
    ZMutex mutex;
    gMutex = &mutex;
    hello::say_hello();
    std::thread t1(func1);
    std::thread t2(func2);

    t1.join();
    t2.join();

    return 0;
}
