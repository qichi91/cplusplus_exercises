#include <iostream>
#include "complex.hpp"

Complex::Complex(double real, double imaginary) : m_real(real), m_imaginary(imaginary)
{
}

double Complex::getReal() const
{
    return m_real;
}

double Complex::getImaginary() const
{
    return m_imaginary;
}

// m_realとm_imaginaryを出力する
void Complex::display() const
{
    std::cout << "Complex: " << m_real << ", " << m_imaginary << "i" << std::endl;
}
