//This is the implementation file Security.cpp
#include<iostream>
#include "Security.h"
using namespace std;

int Security::validate(string username, string password)
{
	if ((username == "abbott") && (password == "monday")) {            //user is normal user return 1
		return(1);
	}
	else if ((username == "costello") && (password == "tuesday")) {    //user is administrator return 2
		return(2);
	}
	return 0;                                                          //false return 0
}