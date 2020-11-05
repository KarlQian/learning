/**************************************************************************************************
*
* \file UniquePtr.cpp
* \brief EB C++ Training - C++11/14 - unique_ptr Example
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Implement a (simplified) std::unique_ptr class template.
*
**************************************************************************************************/

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <utility>


template< typename T >
class unique_ptr
{
 public:
   typedef T*  pointer;
 
   constexpr unique_ptr();
             unique_ptr( T* ptr );
             unique_ptr( unique_ptr const& u ) = delete;
             unique_ptr( unique_ptr&& u );

   unique_ptr& operator=( unique_ptr const& u ) = delete;
   unique_ptr& operator=( unique_ptr&& u );

   T&      operator* () const;
   pointer operator->() const;
   
 private:
   T* ptr_;
};


template< typename T >
constexpr unique_ptr<T>::unique_ptr()
   : ptr_( nullptr )
{}


template< typename T >
unique_ptr<T>::unique_ptr( T* ptr )
   : ptr_( ptr )
{}


template< typename T >
unique_ptr<T>::unique_ptr( unique_ptr&& u )
   : ptr_( u.ptr )
{
   u.ptr_ = nullptr;
}


template< typename T >
unique_ptr<T>& unique_ptr<T>::operator=( unique_ptr&& u )
{
   delete ptr_;
   ptr_ = u.ptr_;
   u.ptr_ = nullptr;
}


template< typename T >
T& unique_ptr<T>::operator*() const
{
   return *ptr_;
}


template< typename T >
typename unique_ptr<T>::pointer unique_ptr<T>::operator->() const
{
   return ptr_;
}


template< typename T, typename Ts... >
unique_ptr<T> make_unique( Ts&&... params )
{
   return unique_ptr<T>( new T( std::forward<Ts>( params )... ) );
}


int main()
{
   unique_ptr<int> a = make_unique<int>( 2 );

   std::cerr << "\n *a = " << *a << "\n\n";
   
   return EXIT_SUCCESS;
}
