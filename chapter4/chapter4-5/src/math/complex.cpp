#include "complex.hpp"
#include <iostream>

Complex::Complex(double real, double imaginary)
    : m_real(real), m_imaginary(imaginary)
{
}

void Complex::output() const
{
    std::cout << "Complex: " << m_real << ", " << m_imaginary << "i" << std::endl;
}