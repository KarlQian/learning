/**************************************************************************************************
*
* \file DrawAllShapes.cpp
* \brief EB C++ Training - Programming Task for Non-Intrusive Design
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
**************************************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


void draw( int const value )
{
   std::cout << "int: " << value << std::endl;
}

void draw(  const std::string value )
{
   std::cout << "string: " << value << std::endl;
}



class Drawable
{
public:
   template<typename T>
   Drawable(T const&x):pimpl(new Model<T>(x)){}
   ~Drawable() {delete pimpl;}
   Drawable(Drawable const&rhs):pimpl(rhs.pimpl->clone()){}
   //Drawable& operator=(Drawable rhs){std::swap(pimpl,rhs.pimpl);}
private:
struct Concept
{
   virtual ~Concept(){};
   virtual void do_draw() const = 0;
   virtual Concept* clone()  const = 0;
};

template<typename T>
struct Model: public Concept
{
   Model(T const& value):object(value){}

    void do_draw() const override {draw(object);}
    Concept* clone() const override {return new Model(object);}
   T object;
};
   Concept* pimpl;
   friend void  draw(Drawable const& drawable)
   {drawable.pimpl->do_draw();}
};


typedef std::vector<Drawable> Shapes;

void draw( Shapes const& shapes )
{
   for( Shapes::const_iterator it = shapes.begin();
        it != shapes.end(); ++it )
   {
      draw(*it);
   }
}

int main()
{
   std::vector<Drawable> shapes;

   shapes.push_back( 1 );
   shapes.push_back( 2 );
   shapes.push_back( std::string("hello") );

   draw( shapes );

   return EXIT_SUCCESS;
}
