/**************************************************************************************************
*
* \file Simpsons.cpp
* \brief EB C++ Training - C++11/14 Lambda Example
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Replace the functors in the following program by lambdas to perform the following
*       operations on the Simpsons characters:
*       - Print all characters to the screen
*       - Randomize their order ('r')
*       - Order them by first name ('f')
*       - Order them by last name without affecting the order of first names ('l')
*       - Order them by age without affecting the order of first and last names ('a')
*       - Put all Simpsons first without affecting the general order of characters ('s')
*       - Determine the third oldest character as quickly as possible ('3')
*
**************************************************************************************************/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <string>
#include <vector>


struct Entry
{
    Entry( std::string const& first
         , std::string const& last
         , int const a )
        : firstname( first )
        , lastname ( last  )
        , age      ( a     )
    {}

    std::string firstname;
    std::string lastname;
    int age;
};

std::ostream& operator<<( std::ostream& os, Entry const& entry )
{
    return os << std::setw(11) << std::left  << entry.firstname
              << std::setw(10) << std::left  << entry.lastname
              << std::setw(3)  << std::right << entry.age;
}

template<typename Table>
void print(Table& table)
{
    std::copy( table.begin()
             , table.end()
             , std::ostream_iterator<Entry>( std::cout, "\n" ) );
}

template<typename Table>
void random_order(Table& table)
{
    std::random_shuffle( table.begin(), table.end() );
}

template<typename Table>
void order_by_firstname(Table& table)
{
    std::stable_sort( table.begin(), table.end(), []( Entry const& lhs, Entry const& rhs )
                                                  {
                                                     return lhs.firstname < rhs.firstname;
                                                  } );
}

template<typename Table>
void order_by_lastname(Table& table)
{
    std::stable_sort( table.begin(), table.end(), []( Entry const& lhs, Entry const& rhs )
                                                  {
                                                     return lhs.lastname < rhs.lastname;
                                                  } );
}

template<typename Table>
void order_by_age(Table& table)
{
    std::stable_sort( table.begin(), table.end(), []( Entry const& lhs, Entry const& rhs )
                                                  {
                                                     return lhs.age < rhs.age;
                                                  } );
}

template<typename Table>
void lastname_first(Table& table, std::string const& name)
{
    std::stable_partition( table.begin(), table.end(), [&]( Entry const& entry )
                                                       {
                                                          return entry.lastname == name;
                                                       } );
}

template<typename Table>
void third_oldest(Table& table)
{
    std::nth_element( table.begin(), table.begin()+2, table.end()
                    , []( Entry const& lhs, Entry const& rhs )
                      {
                         return rhs.age < lhs.age;
                      } );
}




int main()
{
   std::vector<Entry> table = { { "Homer",      "Simpson",    38 }
                              , { "Marge",      "Simpson",    34 }
                              , { "Bart",       "Simpson",    10 }
                              , { "Lisa",       "Simpson",     8 }
                              , { "Maggie",     "Simpson",     1 }
                              , { "Hans",       "Moleman",    33 }
                              , { "Ralph",      "Wiggum",      8 }
                              , { "Jeff",       "Albertson",  45 }
                              , { "Montgomery", "Burns",     104 } };

   char command;
   while (std::cout << "Enter command: " && std::cin >> command)
   {
      switch (command)
      {
         case 'r':
            random_order(table);
            break;

         case 'f':
            order_by_firstname(table);
            break;

         case 'l':
            order_by_lastname(table);
            break;

         case 'a':
            order_by_age(table);
            break;

         case 's':
            lastname_first(table, "Burns");
            break;
    
         case '3':
            third_oldest(table);
            break;

         default:
            return EXIT_SUCCESS;
      }

      print(table);
   }
}
