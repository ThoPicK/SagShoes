#include "DaoManager.h"
#include"Administrateur.h"
#include "InvalidEmailOrPassword.h"

DaoManager* DaoManager::getInstance()
{
	if (instance_ == nullptr) {
		instance_ = new DaoManager();
	}
	return instance_;
}

DaoManager::DaoManager() {
	const string server = "tcp://127.0.0.1:3306";
	const string username = "root";
	const string password = "password";

	try {
		driver_ = get_driver_instance();
		connection_ = driver_->connect(server, username, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
	connection_->setSchema("sagshoes");
}

void DaoManager::connect(string email, string password) {
	PreparedStatement* pstmt = connection_->prepareStatement("select * from users where email= ? and password= ?");
	pstmt->setString(1, email);
	pstmt->setString(2, password);
	ResultSet* res=pstmt->executeQuery();
	if (res == nullptr) {
		throw InvalidEmailOrPassword();
	}
	else {
		switch (res->getInt("statut")) {
		case 0: //admin
			connectedUser_ = new Administrateur(
				res->getInt("id"),
				res->getString("name").asStdString(),
				res->getString("email").asStdString(),
				res->getString("password").asStdString());
			break;
		case 1: //vendeur
			connectedUser_ = new Vendeur(
				res->getInt("id"),
				res->getString("name").asStdString(),
				res->getString("email").asStdString(),
				res->getString("password").asStdString());
			break;
		case 2: //client
			Panier * panier = getPanier(res->getInt("id"));
			connectedUser_ = new Client(
				res->getInt("id"),
				res->getString("name").asStdString(),
				res->getString("email").asStdString(),
				res->getString("password").asStdString(),
				*panier);
			break;
		default:
			break;
		}
	}
	delete pstmt;
	delete res;
}

Panier* DaoManager::getPanier(int id) {
	//récupération des articles du panier sur la base de données
}