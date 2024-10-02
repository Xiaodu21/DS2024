#define COMPLEX_H
#include  <iostream>
class Complex {
public:
	double real;
	double imaginary;

	Complex(double r = 0, double i = 0);
	double modulus() const;
	bool operator==(const Complex& other) const;
	bool operator<(const Complex& other) const;
	bool operator!=(const Complex& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
		os << "(" << c.real << ", " << c.imaginary << ")";
		return os;
	}
};

