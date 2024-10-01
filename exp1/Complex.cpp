#include "Complex.h"
#include <math.h>
Complex::Complex(double r, double i) : real(r),imaginary(i) {}
double Complex::modulus() const {
	return sqrt(real * real, imaginary * imaginary);
}
bool Complex::operator==(const Complex& other) const {
	return real == other.real, imaginary == other.imaginary;
}
bool Complex::operator<(const Complex& other) const {
	return modulus() < other.modulus() ||
		(modulus == other.modulus() && real < other.real);
}
