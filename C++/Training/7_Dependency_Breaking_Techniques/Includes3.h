/**************************************************************************************************
*
* \file Includes.cpp
* \brief EB C++ Training - Dependency Reduction Techniques Example
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Step 1: In the following header file, which #include directives could be immediately removed
*         without ill effect? You may not make any changes other than removing or rewriting
*         #include directives. Note that the comments are important.
*
* Step 2: What further #includes could be removed if we made some suitable changes, and how?
*         This time, you may make changes to X as long as X's base classes and its public
*         interface remain unchanged; and current code that already uses X should not be
*         affected beyond requiring a simple recompilation.
*
* Step 3: What further #includes could be removed if we made further changes to X, and how?
*         Now you may make any changes to X as long as they don't change its public interface
*         so that existing code that uses X is unaffected beyond requiring a simple
*         recompilation. Again, note that the comments are important.
*
**************************************************************************************************/

#include <iosfwd>

// None of A, B, C, D or E are templates.
// Only A and C have virtual functions.
#include "a.h"  // class A
class B;
class C;
class E;


class X : public A
{
public:
    X( C const& );

    B  f( int, char* );
    C  f( int, C );
    C& g( B );
    E  h( E );
    virtual std::ostream& print( std::ostream& ) const;

private:
    struct XImpl;
    XImpl* pimpl_;
};

inline std::ostream& operator<<( std::ostream& os, X const& x )
{
    return x.print( os );
}
