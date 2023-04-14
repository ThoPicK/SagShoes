#ifndef USER_H
#define USER_H

#include "String"

class User
{
public: 
	User(int id, std::string name, std::string email, std::string password);
	virtual std::string getName() = 0;
	std::string getEmail() { return email_; };
	std::string getPassword() { return password_; };
	int getID() { return id_; };

protected:
	int id_;
	std::string name_;
	std::string email_;
	std::string password_;
};

#endif

