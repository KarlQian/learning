/**************************************************************************************************
*
* \file
* \brief EB Training Programming with C++-Advanced - 5 Exception Safety - 
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Write a RAII class taking the responsibility to lock and unlock a mutex.
*       Assume that there is a Mutex class, which provides the member functions lock() and 
*       unlock().
*
**************************************************************************************************/

#include <iostream>

// to fullfill the assumption
struct Mutex
{
    void lock() { std::cout << "Mutex::lock() called." << std::endl; };
    void unlock() { std::cout << "Mutex::unlock() called." << std::endl; };
};


class LockGuard
{
public:
    // ...
    explicit LockGuard(Mutex& mutex) : mutex(mutex)
    {
        mutex.lock();
    }

    LockGuard(LockGuard const&) = delete;
    const LockGuard operator=(LockGuard const&) = delete;

    ~LockGuard()
    {
        mutex.unlock();
    }

private:
    Mutex& mutex;
};


int main()
{
    Mutex mutex;

    // ...
    LockGuard lockGuard(mutex);
    // ensure that the LockGuard can not be copied
    //LockGuard anotherGuard(lockGuard);
}
