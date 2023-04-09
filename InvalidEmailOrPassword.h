#pragma once
#ifndef InvalidEmailOrPassword_H
#define InvalidEmailOrPassword_H
#include<exception>
#include<string>
using namespace std;
class InvalidEmailOrPassword:
	public exception
{
public:
	const char* what() const throw () {
		return "Email ou mot de passe invalide";
	}
};

#endif // !InvalidEmailOrPassword_H



