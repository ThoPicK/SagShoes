#ifndef DAO_H
#define DAO_H
#include <stdlib.h>
#include <iostream>

#include "User.h"
#include "Panier.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;
using namespace sql;

class DaoManager
{
private:
	DaoManager();

	static DaoManager* instance_;
	Driver* driver_;
	Connection* connection_;
	User* connectedUser_;

public:
	static DaoManager* getInstance();
	void connect(string email, string password);
	void disconnect();
	User* getConnectedUser();
	Panier* getPanier(int id);

};

#endif
