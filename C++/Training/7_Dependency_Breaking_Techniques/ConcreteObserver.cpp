/**************************************************************************************************
*
* \file ConcreteObserver.cpp
* \brief EB C++ Training - Code example for Observer Pattern vs. Command Pattern
* 
* Copyright (c) 2016 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
**************************************************************************************************/

#include <functional>
#include <iostream>
#include <vector>

#include <boost/config.hpp>

struct Subject
{
    #if defined(BOOST_NO_CXX11_TEMPLATE_ALIASES)
    typedef std::function<void()>  Callback;
    #else
    using Callback = std::function<void()>;
    #endif
    void Register(Callback const callback)
    {
        this->callback = callback;
    }

    void Trigger()
    {
        callback();
    }

private:
    Callback callback;
};

class ConcreteObserver
{
public:
    ConcreteObserver(Subject& subject) :
        concreteSubject(subject)
    {}

    // ...
    void Update()
    {
        std::cout << "Update() in the ConcreteObserver!" << std::endl;
    }
    // ...

    // ...
    void RegisterCallback()
    {
        concreteSubject.Register(std::bind(&ConcreteObserver::Update, this));
        //concreteSubject.Register([] {std::cout << "Lambda in the ConcreteObserver!" << std::endl; });
    }
    // ...

private:
    Subject& concreteSubject;
};


int main()
{
    Subject subject;
    ConcreteObserver observer(subject);
    observer.RegisterCallback();
    subject.Trigger();
}
