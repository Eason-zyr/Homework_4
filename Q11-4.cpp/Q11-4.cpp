//include header files to complete the username and password check
#include<iostream>
#include "Administrator.h"         //header files
#include "Security.h"
#include "User.h"
using namespace std;

int main(void) {
	string username, password;                   //store user's input
	
	cout << "Login..." << endl;
	cout << "Enter your user name and password..." << endl;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	User user;                                   //build two objects
	Administrator Amtr;

	if (user.Login(username, password)) {
		if (Amtr.Login(username, password)) {    //check username and password are both correct
			cout << "Welcome back, administrator..." << endl;
		}
		else {
			cout << "Welcome back, user..." << endl;
		}
	}
	else {                                       //error message
		cout << "Your username or password are wrong..." << endl;
	}

	system("pause");
	return(0);
}