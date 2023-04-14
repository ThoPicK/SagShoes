#include <stdlib.h>
#include <iostream>
#include "DaoManager.h"
#include "Client.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;


int main()
{
	DaoManager* dao = DaoManager::GetInstance();
	Client c(1, "test", "test@test.ca", "password");
	//dao->addClient(c);
	vector<Client> clients = dao->getClients();
	cout << clients.front().getEmail() << endl;
}