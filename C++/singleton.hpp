#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <iostream>
#include <mutex>
using namespace std;
namespace cc{
    //return pointer , baohan 
    class SingleTon
    {
    public:
        static SingleTon *getinstance();
        static void destoryInstance();
    private:
        SingleTon(){cout <<"Singleton()"<<endl;}
        ~SingleTon(){cout <<"~Singleton()"<<endl;}
        //forbid copy
        SingleTon(const SingleTon&) = delete;
        SingleTon & operator=(const SingleTon&) = delete ;
    private:
        static std::mutex m_mutex;
        static SingleTon* m_pInstance;
    };
    // return reference e han
    class Single2
    {
        public:
            static Single2 & getInstance();
        private:
            Single2(){cout <<"single2()"<<endl;}
            ~Single2(){cout <<"~single2()"<<endl;}
            Single2(const Single2&) = delete;
            Single2& operator=(const Single2&) = delete;
        private:
            static Single2 m_Instance;
    };

    // ponce_thread

template<typename T>
class Singleton
{
public:
Singleton() = delete;
~Singleton() = delete;

static T& instance()
{
    pthread_once(&ponce_, &Singleton::init);
    assert(value_ != NULL);
    return *value_;
}

private:
static void init()
{
    value_ = new T();
    // if (!detail::has_no_destroy<T>::value)
    // {
    // ::atexit(destroy);
    // }
}

static void destroy()
{
    typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
    T_must_be_complete_type dummy; (void) dummy;

    delete value_;
    value_ = NULL;
}

private:
static pthread_once_t ponce_;
static T*             value_;
};

template<typename T>
pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

template<typename T>
T* Singleton<T>::value_ = NULL;

}


#endif