/**************************************************************************************************
*
* \file Accumulate.cpp
* \brief EB C++ Training - Accumulate Programming Task
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Using a std::vector with double precision floating point values, what, if anything,
*       is wrong with the following call to the 'accumulate' function?
*
**************************************************************************************************/

#include <iostream>
#include <numeric>
#include <vector>


int main()
{
    std::vector<double> vec( 4U );
    vec[0] = 1.2;
    vec[1] = 3.1;
    vec[2] = 0.4;
    vec[3] = 1.5;

    double const sum = std::accumulate( vec.begin(), vec.end(), 0.0 );

    std::cout << "\n"
              << " Sum of all values = " << sum << "\n"
              << " Expected sum      = 6.2\n\n";
}

