//Complex numbers calculate ,input and output
#ifndef Q8-3_H
#define Q8-3_H
#include<iostream>
using namespace std;

class Complex {                                                               //a class named Complex  
public:
	Complex();                                                                //default and self-defined constructors
	Complex(double real, double img);
	Complex(double realPart);
	void set_real(double real);                                               //set and get functions
	void set_imaginary(double img);
	double get_real() const;
	double get_imaginary() const;
	friend bool operator ==(const Complex& c1, const Complex& c2);            //operators overloading,+,-,==,*
	friend const Complex operator +(const Complex& c1, const Complex& c2);
	friend const Complex operator -(const Complex& c1, const Complex& c2);
	friend const Complex operator *(const Complex& c1, const Complex& c2);
	friend istream& operator >>(istream& in, Complex& c_number);              //input >> and output << overloading
	friend ostream& operator <<(ostream& out, const Complex& c_number);
private:
	double real;                                                              //private variables:real and imaginary
	double imaginary;
};

const Complex i(0, 1);

#endif