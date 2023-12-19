#include "calculator.hpp"
#include "complex.hpp"

Complex Calculator::multiply(const Complex &c1, const Complex &c2) const
{
    return Complex(c1.getReal() * c2.getReal() - c1.getImaginary() * c2.getImaginary(),
                   c1.getReal() * c2.getImaginary() + c1.getImaginary() * c2.getReal());
}
