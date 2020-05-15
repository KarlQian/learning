#include <iostream>
#include<string>
#include<stdio.h>
#include <memory>
using namespace std;
class A
{
    public:
     ~A(){cout<<"~A"<<endl;}
};

class B:public A
{
    public:
    ~B(){cout<<"~B"<<endl;}
};
class C:public B
{
    public:
    ~C(){cout<<"~C"<<endl;}
};
void test()
{
    unique_ptr<B> pt_b(new C());

}
int main()
{
    test();
}