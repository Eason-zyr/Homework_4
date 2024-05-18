//use overloading operators ++ and -- to find prime numbers
#include<iostream>
#include<cstdlib>
using namespace std;

class PrimeNumber {                                       //a class named PrimeNumber
public:
	PrimeNumber() :pr_num(1) {};                          //two constructors
	PrimeNumber(int pr_num) :pr_num(pr_num) {};
	void set_pr(int pr_num) { this->pr_num = pr_num; }    //set and get functions
	int get_pr() const { return(pr_num); }
	const PrimeNumber operator ++();                      //prefix ++ and -- overloading
	const PrimeNumber operator --();
	const PrimeNumber operator ++(int);                   //postfix ++ and -- overloading
	const PrimeNumber operator --(int);
	bool is_prime(int num);                               //check is or not a prime number
private:
	int pr_num;                                           //private variable to store prime number
};

int main(void) {
	int prime;
	cout << "Set a prime number >> ";
	cin >> prime;
	PrimeNumber pr_num(prime);                                              //call constructor to build an object
	PrimeNumber next_pr(pr_num++);                                          //use overloading ++,--to build other objects
	PrimeNumber smlt_pr(pr_num--);

	cout << "Next largest prime number is " << next_pr.get_pr() << endl;    //show next largest and smallest prime numbers
	cout << "Next smallest prime number is " << smlt_pr.get_pr() << endl;

	system("pause");
	return(0);
}

const PrimeNumber PrimeNumber::operator ++() {                              //prefix ++ overloading
	do {
		pr_num++;
	} while (!is_prime(pr_num));
	return(pr_num);
}

const PrimeNumber PrimeNumber::operator ++(int) {                           //postfix ++ overloading
	int prime_temp = this->pr_num;                                          //get number then +1
	do {
		prime_temp++;
	} while (!is_prime(prime_temp));
	return(prime_temp);
}

const PrimeNumber PrimeNumber::operator --() {                              //prefix -- overloading
	do {
		pr_num--;
	} while (!is_prime(pr_num));
	return(pr_num);
}

const PrimeNumber PrimeNumber::operator --(int) {                           //postfix -- overloading
	int prime_temp = this->pr_num;                                          //get number then +1
	do {
		prime_temp--;
	} while (!is_prime(prime_temp));
	return(prime_temp);
}

bool PrimeNumber::is_prime(int num) {                                       //check prime number
	if (num < 2) {                                                          //error message
		cout << "No prime number is smaller than 2!" << endl;
		exit(0);
	}
	for (int i = 2; i < num; i++) {                                         //has factor is not a prime
		if (num % i == 0) {
			return(false);
		}
	}
	return(true);                                                           //has no factor is a prime
}