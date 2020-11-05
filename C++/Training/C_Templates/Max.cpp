/**************************************************************************************************
*
* \file Max.cpp
* \brief EB C++ Training - Function Template C++ Example
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Rewrite the max function, but use two template parameters instead of one (one for each
*       parameter).
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>


// Definition of the max function
template< typename T1, typename T2 >
inline auto max( T1 const& a, T2 const& b ) -> decltype( a + b )
{
    return ( a < b ) ? b : a;
}


// Specialization of the max function template
template<>
inline int max( int const& a, int const& b )
{
    return ( a < b ) ? b : a;
}


int main()
{
   std::cout << "\n"
                " max(1  , 5  ) = " << max( 1  ,  5   ) << "\n"
                " max(3  , 2  ) = " << max( 3  ,  2   ) << "\n"
                " max(1.2,-4  ) = " << max( 1.2, -4   ) << "\n"
                " max(1  , 2.8) = " << max( 1  ,  2.8 ) << "\n"
                "\n";
   
   return EXIT_SUCCESS;
}
