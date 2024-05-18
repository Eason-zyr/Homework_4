//This is the implementation file Administrator.cpp
#include<iostream>
#include "Administrator.h"
#include "Security.h"
using namespace std;

bool Administrator::Login(string username, string password) {
	if (Security::validate(username, password) == 2) {    //return 2 is administrator,return true
		return(true);
	}
	else {                                                //else is not
		return(false);
	}
}