#include "String"

class User
{
public: 
	User(int id, std::string name, std::string email, std::string password);

private:
	int id_;
	std::string name_;
	std::string email_;
	std::string password;
};

