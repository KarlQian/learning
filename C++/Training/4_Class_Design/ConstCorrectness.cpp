/**************************************************************************************************
*
* \file ConstCorrectness.cpp
* \brief EB C++ Training - Programming Task about Const Correctness
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Consider the following code. Don’t comment on or change the structure of this program;
*       it’s contrived and condensed for illustration only. Just add or remove const (including
*       minor variants and related keywords) wherever appropriate.
*
**************************************************************************************************/

#include <vector>
#include <cstddef>

struct Point
{
    double x = 0.0;
    double y = 0.0;
};

class Polygon
{
public:
    Polygon() : area_(-1.0) {}

    void AddPoint( Point const pt )
    {
        InvalidateArea();
        points_.push_back(pt);
    }

    Point GetPoint( std::size_t const i ) const { return points_[i]; }

    std::size_t GetNumPoints() const { return points_.size(); }

    double GetArea() const
    {
        if ( area_ < 0.0 ) // if not yet calculated and cached
        {
            CalcArea();
        }
        return area_;
    }

private:
    void InvalidateArea() const { area_ = -1.0; }

    void CalcArea() const
    {
        area_ = 0.0;
        std::vector<Point>::const_iterator i;
        for ( i = points_.begin(); i != points_.end(); ++i )
            area_ += /* some work */ 0.0;
    }
 
    std::vector<Point> points_;
    mutable double area_;
};


Polygon operator+( Polygon const& lhs, Polygon const& rhs )
{
    Polygon ret = lhs;
    int const last = rhs.GetNumPoints();
    for ( int i = 0; i < last; ++i ) // concatenate
    {
        ret.AddPoint( rhs.GetPoint(i) );
    }
    return ret;
}


void f( Polygon& poly )
{
    poly.AddPoint( {0.0, 0.0} );
}


void g( Polygon& rPoly )
{
    rPoly.AddPoint( {1.0, 1.0} );
}


void h( Polygon* const pPoly )
{
    pPoly->AddPoint( {2.0, 2.0} );
}


int main()
{
    Polygon poly;
    Polygon const cpoly;
    f(poly);
    g(poly);
    h(&poly);

    double const area = cpoly.GetArea();
}
