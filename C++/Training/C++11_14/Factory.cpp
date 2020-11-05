/**************************************************************************************************
*
* \file Factory.cpp
* \brief EB C++ Training - C++11/14 - Smart Pointer Example
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Implement the given factory function to construct the requested type of investment.
*       Put special emphasis on the construction process and the return type of the function.
*
**************************************************************************************************/

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>


template< typename T, typename Ts... >
std::unique_ptr<T> make_unique( Ts&&... params )
{
   return std::unique_ptr<T>( new T( std::forward<Ts>( params )... ) );
}


class Investment {};

class Stock : public Investment {};

class Bond : public Investment {};

class RealEstate : public Investment {};


enum InvestmentType
{
   stock      = 0,
   bond       = 1,
   realEstate = 2
};


std::unique_ptr<Investment> createInvestment( InvestmentType investment )
{
   if( investment == stock ) {
      return make_unique<Stock>();
   }
   else if( investment == bond ) {
      return make_unique<Bond>();
   }
   else if( investment == realEstate ) {
      return make_unique<RealEstate>();
   }
   else {
      assert( false );
   }
}


int main()
{
   std::shared_ptr<Investment> sp1 = createInvestment( stock );
   
   std::shared_ptr<Investment> sp2 = createInvestment( bond );
   
   std::shared_ptr<Investment> sp3 = createInvestment( realEstate );
   
   return EXIT_SUCCESS;
}

