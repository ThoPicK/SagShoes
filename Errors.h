#pragma once
#ifndef Errors_H
#define Errors_H
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

class SQLError :
	public exception
{
public:
	const char* what() const throw () {
		return "Erreur SQL";
	}
};

class InvalidIdProduit :
	public exception
{
public:
	const char* what() const throw () {
		return "Id de produit invalide";
	}
};



#endif 



