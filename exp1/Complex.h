#ifndef COMPLEX_H
#define COMPLEX_H
class Complex {
public:
	double real;
	double imaginary;

	Complex(double r = 0, double i = 0);
	double modulus() const;
	double operator==(const Complex& other) const;
	double operator<(const Complex& other) const;
};#pragma once
