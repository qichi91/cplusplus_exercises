#include "calculator.hpp"
#include "complex.hpp"

Complex Calculator::multiply(const Complex &c1, const Complex &c2) const
{
    double real = c1.m_real * c2.m_real - c1.m_imaginary * c2.m_imaginary;
    double imaginary = c1.m_real * c2.m_imaginary + c1.m_imaginary * c2.m_real;
    return Complex(real, imaginary);
}