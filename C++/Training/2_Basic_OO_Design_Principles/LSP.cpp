/**************************************************************************************************
*
* \file LSP.cpp
* \brief EB C++ Training - Example for the Liskov Substitution Principle
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Evaluate the following program in the context of the Liskov Substitution Principle
*
**************************************************************************************************/

#include <cassert>
#include <vector>


//--Point.h----------------------------------------------------------------------------------------

struct Point
{
    double x = 0.0;  // C++11 NSDMI, C++<11 requires
    double y = 0.0;  // default c'tor to achieve similar effect.
};


//--LinearObject.h---------------------------------------------------------------------------------

class LinearObject
{
public:
    LinearObject( Point const& p1, Point const& p2 );

    double       GetSlope() const;
    Point const& GetP1()    const;
    Point const& GetP2()    const;

    virtual bool IsOn( Point const& p ) const;

private:
    Point m_p1;
    Point m_p2;
};


//--Line.h-----------------------------------------------------------------------------------------

class Line : public LinearObject
{
public:
    Line( Point const& p1, Point const& p2 );

    Point GetYIntersection() const;

    virtual bool IsOn( Point const& p ) const;
};

void testLineInvariants( Line const& line )
{
    assert( line.IsOn( line.GetYIntersection() ) );
}


//--LineSegment.h----------------------------------------------------------------------------------

class LineSegment : public LinearObject
{
public:
    LineSegment( Point const& p1, Point const& p2 );

    double GetLength() const;

    virtual bool IsOn( Point const& ) const;
};


//--Main.cpp---------------------------------------------------------------------------------------

int main()
{
    Line const line( Point{ 1.0, 1.0 }, Point{ 2.0, 2.0 } );

    testLineInvariants( line );
    
    
    LineSegment const segment( Point{ 1.0, 1.0 }, Point{ 2.0, 2.0 } );

    testLineInvariants( segment );  // Compilation error!
}

