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

void draw( std::string const& s )
{
   std::cout << "string: " << s << std::endl;
}




class Drawable
{
 public:
   template< typename T >
   Drawable( T const& x ) : pimpl( new Model<T>( x ) ) {}

   ~Drawable() { delete pimpl; }
   Drawable( Drawable const& rr ) : pimpl( rr.pimpl->clone() ) {}
   Drawable& operator=( Drawable rr ) { std::swap( pimpl, rr.pimpl ); }

 private:
   friend void draw( Drawable const& drawable )
   {
      drawable.pimpl->do_draw();
   }

   struct Concept
   {
      virtual ~Concept() {}
      virtual void do_draw() const = 0;
      virtual Concept* clone() const = 0;
   };

   template< typename T >
   struct Model : Concept
   {
      Model( T const& value ) : object( value ) {}
      void do_draw() const { draw( object ); }
      Concept* clone() const { return new Model( object ); }
      T object;
   };

   Concept* pimpl;
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
   shapes.push_back( std::string( "Hello World" ) );

   draw( shapes );

   return EXIT_SUCCESS;
}

