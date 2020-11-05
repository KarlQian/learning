/**************************************************************************************************
*
* \file RemoveErase.cpp
* \brief EB C++ Training - Remove-Erase Idiom Programming Task
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Write a program to strip the punctuation from a std::string. The input to the
*       program should be a string of characters including punctuation. The output should
*       be a std::string in which the punctuation is removed.
*
**************************************************************************************************/

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>


int main()
{
    std::string s1;

    std::cout << "\n Enter a string: ";
    std::cin >> s1;

    s1.erase( std::remove_if( s1.begin(), s1.end(), ispunct ), s1.end() );

    std::cout << " The string without punctuation: '" << s1 << "'\n\n";
}

