/**************************************************************************************************
*
* \file MySet.cpp
* \brief EB C++ Training - MySet Programming Task
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Define the class template 'MySet' based on the given class template definition of
*       'MyList'. 'MySet' should have a function called 'Add', which inserts an element into
*       the set and a function 'Get' to access a specific element in the set. Additionally,
*       'MySet' requires the function 'Size' to return the current number of elements contained
*       in the set.
*
**************************************************************************************************/

#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <set>
using std::size_t;


template< typename T >
class MyList
{
public:
class Allocator{
public:
    Allocator(size_t size):b_(size==0? nullptr: new T[size]){}
    ~Allocator(){delete []b_;}
    T*& operator*(){return b_;}
    private:
    T* b_;
};
public:
    MyList():bufsize_(0),buf_(nullptr){}
    MyList (size_t size):bufsize_(size),buf_(size==0? nullptr : new T[size]()){}
    MyList(const MyList& other){
        bufsize_ = other.bufsize_;
        Allocator tmp(other.bufsize_);
        std::copy(other.buf_,other.buf_+bufsize_,*tmp);
        std::swap(buf_, *tmp);
        }
    virtual ~MyList(){delete [] buf_;}
    bool   Insert( T const& value,size_t index )
    {
        try
        {
            Allocator tmp(bufsize_+1U);
            std::copy(buf_,buf_+bufsize_,*tmp);
            (*tmp)[bufsize_] = value;
            std::swap(buf_,*tmp);
            bufsize_++;

        }
        catch (std::exception &e)
        {return false;}
        return true;
    }
    T Access( size_t index ) const { return buf_[index];}
    size_t Size  () const{return bufsize_;}
    T* begin(){return buf_;}
    T* end(){return buf_+bufsize_;}
public:
    T*     buf_;
    size_t bufsize_;
};

template<typename T>
class MySet:private MyList<T>
{
    public:
    MySet(size_t size=0):MyList<T>(size){}; 
    bool Add(T const& value){
        MyList<T>::Insert(value,MyList<T>::Size());
    }
    T get( size_t index ){return MyList<T>::Access(index);}
    T* begin(){return MyList<T>::begin();}
    T* end(){return MyList<T>::end();}

};

std::ostream& operator<<(std::ostream&os ,  MySet<std::string>& myset){
    os<<"[";
    for (auto&v : myset)
    {
        os<<v<<" ";
    }
    return os;
}
int main()
{
    MySet<std::string> set{4};
    set.Add("one");
    set.Add("two");
    set.Add("three");
    set.Add("four");
    std::cout<<set<<std::endl;
    return 0 ;

}
// TODO: class definition of the 'MySet' class template
