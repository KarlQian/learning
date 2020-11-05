/**************************************************************************************************
*
* \file SiameseTwins.cpp
* \brief EB C++ Training - Siamese Twins Programming Task
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: In case you need to derive (publicly or non-publicly) from several base clases, you may
*       be faced with the problem that two base classes require you to override a function with
*       the same signature. Both base classes are clearly intended to be used as base classes,
*       but they are otherwise unrelated. Their 'Compute()' functions are intended to do different
*       things. Show how this problem can be solved.
*
**************************************************************************************************/

#include <cmath>
#include <iostream>
#include <memory>


class BaseA
{
public:
    // Compute the square root of the given value
    virtual double Compute( double ) = 0;
};


class BaseA2 : public BaseA
{
public:
    virtual double BaseACompute( double ) = 0;
private:
    virtual double Compute( double const d )
    {
        return BaseACompute( d );
    }
};


class BaseB
{
public:
    // Quadrupling the given value
    virtual double Compute( double ) = 0;
};


class BaseB2 : public BaseB
{
public:
    virtual double BaseBCompute( double ) = 0;
private:
    virtual double Compute( double const d )
    {
        return BaseBCompute( d );
    }
};


class Derived : public BaseA2
              , public BaseB2
{
public:
    virtual double BaseACompute( double const d )
    {
        return std::sqrt( d );
    }

    virtual double BaseBCompute( double const d )
    {
        return 4.0 * d;
    }
};


int main()
{
    std::auto_ptr<Derived> d( new Derived() );
    BaseA* pba = d.get();
    BaseB* pbb = d.get();

    // Computing the square root of 2
    double const sqr = pba->Compute( 2.0 );
    std::cerr << "\n The square root of 2 is " << sqr << "\n";

    // Quadrupling the value 2
    double const quad = pbb->Compute( 2.0 );
    std::cerr << "\n Quadrupling 2 is " << quad << "\n\n";
}

