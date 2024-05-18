//This is the implementation file User.cpp
#include<iostream>
#include "User.h"
#include "Security.h"
using namespace std;

bool User::Login(string username, string password) {
	if (Security::validate(username, password) == 1 || Security::validate(username, password) == 2) {
		return(true);                               //return 1 or 2 means is user
	}
	else {
		return(false);                              //else is not
	}
}