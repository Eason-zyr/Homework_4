//Complex numbers calculate ,input and output
#include<iostream>
using namespace std;

class Complex {                                                               //a class named Complex  
public:
	Complex() :real(0), imaginary(0) {};                                      //default and self-defined constructors
	Complex(double real, double img) :real(real), imaginary(img) {};
	Complex(double realPart) :real(realPart), imaginary(0) {};
	void set_real(double real) { this->real = real; }                         //set and get functions
	void set_imaginary(double img) { this->imaginary = img; }
	double get_real() const { return(real); }
	double get_imaginary() const { return(imaginary); }
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

int main(void) {
	Complex c1(2.6, 3.7), c2(4.8, 3.7);                                       //use constructor to build two complex numbers

	cout << "Two complex numbers (i means square root of -1): ";              //output informations
	cout << "C1: " << c1 << " ,C2: " << c2 << endl;
	if (c1 == c2) {                                                           //testing operators: ==, +, -, *
		cout << "C1 is equal to C2..." << endl << endl;
	}
	else {
		cout << "C1 is not equal to C2..." << endl << endl;
	}

	Complex Add = c1 + c2;
	cout << "Add: " << c1 << " + " << c2 << " = " << Add << endl << endl;

	Complex Subtract = c1 - c2;
	cout << "Subtract: " << c1 << " - " << c2 << " = " << Subtract << endl << endl;

	Complex Times = c1 * c2;
	cout << "Times: " << c1 << " * " << c2 << " = " << Times << endl << endl;

	system("pause");
	return(0);
}

bool operator ==(const Complex& c1, const Complex& c2) {                       //== overloading
	return((c1.real == c2.real) && (c1.imaginary == c2.imaginary));
}

const Complex operator +(const Complex& c1, const Complex& c2) {               //+ overloading
	return(Complex((c1.real + c2.real), (c1.imaginary + c2.imaginary)));
}

const Complex operator -(const Complex& c1, const Complex& c2) {               //- overloading
	return(Complex((c1.real - c2.real), (c1.imaginary - c2.imaginary)));
}

const Complex operator *(const Complex& c1, const Complex& c2) {               //* overloading
	return(Complex((c1.real * c2.real - c1.imaginary * c2.imaginary), (c1.real * c2.imaginary + c1.imaginary * c2.real)));
}

istream& operator >>(istream& in, Complex& c_number) {                         //>> overloading
	double real, img;
	in >> real >> img;
	c_number.set_real(real);
	c_number.set_imaginary(img);
	return(in);
}

ostream& operator <<(ostream& out, const Complex& c_number) {                  //<< overloading
	out << c_number.real;
	if (c_number.imaginary > 0) {
		out << " + ";
	}
	else if (c_number.imaginary < 0) {
		out << " - ";
	}
	else {
		return(out);
	}
	out << c_number.imaginary << "*i";
	return(out);
}
