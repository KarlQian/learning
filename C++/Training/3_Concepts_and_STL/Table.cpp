/**************************************************************************************************
*
* \file Table.cpp
* \brief EB C++ Training - STL Programming Task
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Implement the empty functions to perform the following operations on the Simpson characters:
*       1. Print all characters to the screen
*       2. Randomize their order ('r')
*       3. Order them by first name ('f')
*       4. Order them by last name without affecting the order of first names ('l')
*       5. Order them by age without affecting the order of first and last names ('a')
*       6. Put all Simpsons first without affecting the general order of characters ('s')
*       7. Determine the third oldest character as quickly as possible ('3')
*
**************************************************************************************************/

#include <algorithm>
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




struct SortByFirstName
{
    bool operator()(Entry const& lhs, Entry const& rhs) const
    {
        return lhs.firstname < rhs.firstname;
    }
};

struct SortByLastName
{
    bool operator()(Entry const& lhs, Entry const& rhs) const
    {
        return lhs.lastname < rhs.lastname;
    }
};

struct SortByAge
{
    bool operator()(Entry const& lhs, Entry const& rhs) const
    {
        return lhs.age < rhs.age;
    }
};

struct PartitionBySimpson
{
    bool operator()( Entry const& entry ) const
    {
        return entry.lastname == "Simpson";
    }
};

struct ReverseSortByAge
{
    bool operator()( Entry const& lhs, Entry const& rhs ) const
    {
        return rhs.age < lhs.age;
    }
};




template<typename Table>
void print(Table const& table)
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
    std::stable_sort(table.begin(), table.end(), SortByFirstName());
}

template<typename Table>
void order_by_lastname(Table& table)
{
    std::stable_sort( table.begin(), table.end(), SortByLastName() );
}

template<typename Table>
void order_by_age(Table& table)
{
    std::stable_sort( table.begin(), table.end(), SortByAge() );
}

template<typename Table>
void simpsons_first(Table& table)
{
    std::stable_partition( table.begin(), table.end(), PartitionBySimpson() );
}

template<typename Table>
void third_oldest(Table& table)
{
    std::nth_element( table.begin(), table.begin()+2, table.end(), ReverseSortByAge() );
}




int main()
{
  std::vector<Entry> table;
  table.push_back( Entry( "Homer",      "Simpson",    38 ) );
  table.push_back( Entry( "Marge",      "Simpson",    34 ) );
  table.push_back( Entry( "Bart",       "Simpson",    10 ) );
  table.push_back( Entry( "Lisa",       "Simpson",     8 ) );
  table.push_back( Entry( "Maggie",     "Simpson",     1 ) );
  table.push_back( Entry( "Hans",       "Moleman",    33 ) );
  table.push_back( Entry( "Ralph",      "Wiggum",      8 ) );
  table.push_back( Entry( "Jeff",       "Albertson",  45 ) );
  table.push_back( Entry( "Montgomery", "Burns",     104 ) );

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
      simpsons_first(table);
      break;
    
    case '3':
        third_oldest(table);
        break;

    default:
            return 0;
    }

    print(table);
  }
}
