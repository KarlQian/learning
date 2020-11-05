/**************************************************************************************************
*
* \file BadCopy.cpp
* \brief EB C++ Training - Idiomatic C++ Programming Task
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Explain the error in the following program.
*
**************************************************************************************************/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>


int main()
{
    std::vector<int> vec;
    std::list<int> lst;
    int i( 0 );

    while ( std::cin >> i ) {
        lst.push_back( i );
    }

    std::copy( lst.begin(), lst.end(), std::back_inserter( vec ) );

    std::copy( vec.begin(), vec.end(), std::ostream_iterator<int>( std::cout, "\n" ) );
}

