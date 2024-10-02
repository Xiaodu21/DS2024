#include "Complex.h"
#include <cmath>
Complex::Complex(double r, double i) : real(r),imaginary(i) {}
double Complex::modulus() const {
	return sqrt(real * real+ imaginary * imaginary);
}
bool Complex::operator==(const Complex& other) const {
	return real == other.real && imaginary == other.imaginary;
}
bool Complex::operator<(const Complex& other) const {
	double thisModulus = modulus();  // 先保存当前对象的模
	double otherModulus = other.modulus();  // 保存其他对象的模
	return thisModulus < otherModulus || (thisModulus == otherModulus && real < other.real);  // 使用逻辑或
}