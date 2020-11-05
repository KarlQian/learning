

#include<stdio.h>
#include "assert.h"
class Singleton
{
    public:
    static Singleton& Instance()
    {
        static Singleton instance;
        return instance;

    }
    void print()
    {
        printf("my address:%p\n",this);
    }
    private:
    Singleton(){}
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

};

int main()
{
    Singleton::Instance().print();
    Singleton::Instance().print();


}