#include "Client.h"
#include "Article.h"

Client::Client(int id, std::string name, std::string email, std::string password, Panier panier):
	User(id,name,email,password)
{
	panier_ = panier;
}

Client::Client(int id, std::string name, std::string email, std::string password) :
	User(id, name, email, password){}


Commande* Client::getCommandes()
{
	return nullptr;
}

void Client::addToCart(Produit p,double taille, int quantite)
{
	/*Article* a = new Article(p, taille, quantite);
	panier_.ajouterItem(*a);*/
}

void Client::order()
{
	panier_.commander();
}
