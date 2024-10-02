#define COMPLEX_H
class Complex {
public:
	double real;
	double imaginary;

	Complex(double r = 0, double i = 0);
	double modulus() const;
	bool operator==(const Complex& other) const;
	bool operator<(const Complex& other) const;
};
