/**************************************************************************************************
*
* \file Faculty.cpp
* \brief EB C++ Training - C++11/14 - function/bind Example
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Extend the given Subject/Observer implementation such that an Observer is notified
*       about state changes via a generalized std::function callback.
*
**************************************************************************************************/

#include <functional>
#include <iostream>
#include <list>


class Subject
{
 public:
   using Callback   = std::function<void(int)>;
   using Callbacks  = std::list<Callback>;
   using CallbackID = Callbacks::const_iterator;

   explicit Subject()
      : state_( 0 )
      , callbacks_()
   {}

   CallbackID add( Callback callback )
   {
      callback( state_ );
      return callbacks_.insert( callbacks_.end(), callback );
   }

   void remove( CallbackID callback )
   {
      callbacks_.erase( callback );
   }
   
   void changeState( int const newState )
   {
      state_ = newState;
      notifyAll();
   }
   
 private:
   void notifyAll() const
   {
      for( auto const& callback : callbacks_ ) {
         callback( state_ );
      }
   }

   int state_;
   Callbacks callbacks_;
};


class Observer
{
 public:
   Observer( Subject& subject )
   {
      using namespace std::placeholders;
      subject.add( std::bind( &Observer::Update, this, _1 ) );
   }

 private:
   void Update( int const state )
   {
      std::cerr << "\n Received an update from subject. New state = " << state << "\n";
   }
};


int main()
{
   Subject subject;
   Observer observer( subject );
   
   subject.changeState( 2 );
}
