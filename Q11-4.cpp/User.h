//This is the header file User.h
#ifndef USER_H
#define USER_H

#include<iostream>
using namespace std;

class User {
public:
	bool Login(string username, string password);    //returns true if a given username and password have 	                                                 
};                                                   //either user or administrator clearance

#endif