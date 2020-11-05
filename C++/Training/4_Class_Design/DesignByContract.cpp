/**************************************************************************************************
*
* \file Vector.cpp
* \brief EB C++ Training - Example for Design By Contract (DBC) Design
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Implement the given 'Vector' class and apply DBC. Discuss whether a unit test would
*       still be required
*
**************************************************************************************************/

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <vector>
using std::size_t;


template< typename Element >
class Vector
{
public:
    typedef Element*        Iterator;
    typedef Element const*  ConstIterator;
   
    Vector()
        : size_    ( 0UL  )
        , capacity_( 0UL  )
        , buffer_  ( NULL )
    {
        assert( invariant() );
    }
   
    explicit Vector( size_t const size )
        : size_    ( size )
        , capacity_( size )
        , buffer_  ( new Element[size] )
    {
        assert( invariant() );
    }

    ~Vector()
    {
        assert( invariant() );
        delete[] buffer_;
    }

    size_t size    () const { assert( invariant() ); return size_;     }
    size_t capacity() const { assert( invariant() ); return capacity_; }

    Iterator      begin ()       { assert( invariant() ); return buffer_; }
    ConstIterator begin () const { assert( invariant() ); return buffer_; }
    ConstIterator cbegin() const { assert( invariant() ); return buffer_; }
    Iterator      end   ()       { assert( invariant() ); return buffer_+size_; }
    ConstIterator end   () const { assert( invariant() ); return buffer_+size_; }
    ConstIterator cend  () const { assert( invariant() ); return buffer_+size_; }

    int&       operator[]( size_t const i )       { assert( invariant() ); return buffer_[i]; }
    int const& operator[]( size_t const i ) const { assert( invariant() ); return buffer_[i]; }

    void push_back( Element const& element )
    {
        assert( invariant() );

        if( size_ == capacity_ ) {
            resize_internal();
        }

        buffer_[size_] = element;
        ++size_;

        assert( invariant() );
    }
   
    void reserve( size_t const capacity )
    {
        if ( capacity > capacity_ )
        {
            resize_internal();
        }
    }

private:
    void resize_internal()
    {
        size_t const newCapacity = capacity_ + 10UL;
        Element* newBuffer = new Element[newCapacity];
        std::copy( buffer_, buffer_+size_, newBuffer );
        std::swap( buffer_, newBuffer );
        delete[] newBuffer;
        capacity_ = newCapacity;
    }

    bool invariant() const { return size_ <= capacity_; }

    size_t size_;
    size_t capacity_;
    Element* buffer_;
};


template< typename Element >
std::ostream& operator<<( std::ostream& os, Vector<Element> const& vec )
{
    if ( vec.size() == 0UL )
        return os << "()";

    os << "(" << vec[0];
    for ( size_t i=1UL; i<vec.size(); ++i ) {
        os << "," << vec[i];
    }
    return os << ")";
}


int main()
{
    Vector<int> vec;
    vec.reserve( 5UL );

    vec.push_back( 41 );
    vec.push_back( 42 );
    vec.push_back( 43 );
    vec.push_back( 44 );
    vec.push_back( 45 );

    std::cerr << "\n" << vec << "\n\n";

    return 0;
}

