#pragma once

#include "calculator.hpp"

class Complex
{
private:
    double m_real;
    double m_imaginary;

public:
    Complex(double real = 0.0, double imaginary = 0.0);

    void output() const;
};