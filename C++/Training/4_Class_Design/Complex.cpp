/**************************************************************************************************
*
* \file Complex.cpp
* \brief EB C++ Training - Complex Class Design Example
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: You are doing a code review. A programmer has written the following class, which shows
*       some poor style and has some real errors. How many can you find, and how would you fix
*       them?
*
**************************************************************************************************/

#include <iostream>


class Complex
{
public:
    Complex(double const real, double const imaginary = 0)
        : m_real     (real)
        , m_imaginary(imaginary)
    {
    }

    double Real() const
    {
        return m_real;
    }

    double Imag() const
    {
        return m_imaginary;
    }

    double ToDouble() const
    {
        return m_real;
    }

    Complex& operator+=( Complex const& other )
    {
        m_real      += other.m_real;
        m_imaginary += other.m_imaginary;
        return *this;
    }

    Complex& operator++()
    {
        ++m_real;
        return *this;
    }

    Complex operator++(int)
    {
        Complex const temp(*this);
        ++(*this);
        return temp;
    }

private:
    double m_real;
    double m_imaginary;
};


Complex operator+(Complex const& a, Complex const& b)
{
    return Complex(a.Real() + b.Real(), a.Imag() + b.Imag());
}


std::ostream& operator<<(std::ostream& os, Complex const& c)
{
    return os << "(" << c.Real() << "," << c.Imag() << ")";
}


int main()
{
    Complex c1(0.0, 2.0);
    Complex c2(2.0, 4.0);

    ++c1;

    std::cout << " c1 = " << c1 << std::endl;

    c2 += c1;

    std::cout << " c2 = " << c2 << std::endl;

    Complex c3 = c1 + c2;

    std::cout << " c3 = " << c3 << std::endl;

    Complex c4 = 1.0 + c1;

    std::cout << " c4 = " << c4 << std::endl;
}

