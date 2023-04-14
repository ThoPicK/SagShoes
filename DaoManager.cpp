#include "DaoManager.h"
#include"User.h"
#include "Client.h"
#include "Vendeur.h"
#include "Administrateur.h"
#include "Errors.h"

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
	//r�cup�ration des articles du panier sur la base de donn�es
}

vector<Vendeur> DaoManager::getVendeurs() {
	Statement* stmt = connection_->createStatement();
	ResultSet* res = stmt->executeQuery("select * from users where statut= 1");
	vector<Vendeur> vendeurs;
	if (res == nullptr) {
		throw SQLError();
	}
	else {
		while (res->next()) {
			Vendeur v(
				res->getInt("id"),
				res->getString("name"),
				res->getString("email"),
				res->getString("password")
			);
			vendeurs.push_back(v);
		}
	}
	return vendeurs;
}

vector<Produit> DaoManager::getProduits() {
	Statement* stmt = connection_->createStatement();
	ResultSet* res = stmt->executeQuery("select * from produit");
	vector<Produit> produits;
	if (res == nullptr) {
		throw SQLError();
	}
	else {
		while (res->next()) {
			int id = res->getInt("id");
			int stock = getStock(id);
			Produit p(
				id,
				stock,
				res->getDouble("prix"),
				res->getDouble("prixLivraison"),
				res->getString("name"),
				res->getString("descrpiption")
			);
			produits.push_back(p);
		}
	}
	return produits;
}