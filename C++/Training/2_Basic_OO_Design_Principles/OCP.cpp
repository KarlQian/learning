/**************************************************************************************************
*
* \file OCP.cpp
* \brief EB C++ Training - Example for the Open-Closed Principle
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Evaluate the following problem in the context of the Open-Closed Principle
*
**************************************************************************************************/

#include <iostream>
#include <vector>


//--Point.h----------------------------------------------------------------------------------------

struct Point
{
    double x = 0.0;
    double y = 0.0;
};


//--Shape.h----------------------------------------------------------------------------------------

struct Shape
{
    Shape()
    {}
    virtual ~Shape() {}
    virtual void Draw() const = 0;
};


//--Circle.h---------------------------------------------------------------------------------------

struct Circle : public Shape
{
    Circle( double const rad )
        : Shape()
        , radius( rad )
        , center()
     {}

    virtual void Draw() const;

    double radius;
    Point center;
};


//--Circle.cpp-------------------------------------------------------------------------------------

void Circle::Draw() const
{
    std::cout << " Drawing a circle\n";
}

std::vector<std::string> source

//--Square.h---------------------------------------------------------------------------------------

struct Square : public Shape
{
    Square( double const s )
        : Shape()
        , side( s )
        , center()
    {}

    virtual void Draw() const;

    double side;
    Point center;
};


//--Square.cpp-------------------------------------------------------------------------------------

void Square::Draw() const
{
    std::cout << " Drawing a square\n";
}


//--DrawAllShapes.h--------------------------------------------------------------------------------

void DrawAllShapes( std::vector<Shape*> const& shapes );


//--DrawAllShapes.cpp------------------------------------------------------------------------------

void DrawAllShapes( std::vector<Shape*> const& shapes )
{
    for ( std::vector<Shape*>::const_iterator it=shapes.begin(); it!=shapes.end(); ++it )
    {
        (*it)->Draw();
    }
}


//--Main.cpp---------------------------------------------------------------------------------------

int main()
{
    typedef std::vector<Shape*>  Shapes;

    // Creating some shapes
    Shapes shapes;
    shapes.push_back( new Circle( 2.0 ) );
    shapes.push_back( new Square( 1.5 ) );
    shapes.push_back( new Circle( 4.2 ) );

    // Drawing all shapes
    DrawAllShapes( shapes ); 

    // Deleting all shapes
    for ( Shapes::iterator it=shapes.begin(); it!=shapes.end(); ++it ) {
       delete *it;
    }
}

