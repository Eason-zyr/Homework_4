//use [] overloading to find the digit value of an integer
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

class MyInteger {                                             //a class named MyInteger
public:                                                       //constructors ,set, and get functions
	MyInteger() :integer(0) {};
	MyInteger(int integer) :integer(integer) {};
	void set_int(int integer) { this->integer = integer; }
	int get_int() const { return(integer); }
	int operator[](int index);                                //overloading operator []
private:
	int integer;                                              //private variable integer
};

int main(void) {
	int integer, index = 0;                                   //store an integer and index
	cout << "Enter an integer >> ";
	cin >> integer;
	MyInteger Int(integer);                                   //build an object by constructor

	while (true) {                                            //find digit until the end
		cout << "integer[" << index << "] is >> " << Int[index] << endl;
		index++;
		integer /= 10;
		if (integer == 0) {                                   //no other digit then return -1 and break
			cout << "integer[" << index << "] is >> " << Int[index] << endl;
			break;
		}
	}

	system("pause");
	return(0);
}

int MyInteger::operator[](int index) {                                    //overloading operator []
	if ((integer / int(pow(10, index))) == 0) {                           //the end return -1
		return(-1);
	}
	if (index == 0) {                                                     //the first directly return %10
		return(integer % 10);
	}
	return((integer % int(pow(10, index + 1)) / int(pow(10, index))));    //other digits use this way  
}