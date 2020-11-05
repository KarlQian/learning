/**************************************************************************************************
*
* \file Faculty.cpp
* \brief EB C++ Training - C++11/14 - constexpr Example
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Implement a faculty function that can be used to compute the size of a std::array at
*       compile time.
*
**************************************************************************************************/

#include <array>
#include <cstdlib>
#include <iostream>


//=================================================================================================
// TMP version
//=================================================================================================

template< unsigned int N >
struct Faculty
{
   static unsigned int const value = N * Faculty<N-1U>::value;
};

template<>
struct Faculty<1U>
{
   static unsigned int const value = 1U;
};

template<>
struct Faculty<0U>
{
   static unsigned int const value = 0U;
};


//=================================================================================================
// C++11 version
//=================================================================================================

constexpr unsigned int faculty( unsigned int const n )
{
   return ( n < 2U )?( n ):( n * faculty( n - 1U ) );
}


//=================================================================================================
// C++14 version
//=================================================================================================

/*
constexpr unsigned int faculty( unsigned int const n )
{
   unsigned int result( 1U );
   for( unsigned int i=0U; i<n; ++i )
      result *= i;
   return result;
}
*/


int main()
{
   std::array<int,faculty(3U)> a;

   std::cerr << "\n a.size() = " << a.size() << "\n\n";
   
   return EXIT_SUCCESS;
}
