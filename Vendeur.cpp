#include "Vendeur.h"

Vendeur::Vendeur(int id, std::string name, std::string email, std::string password):
	User(id,name,email,password){}

void Vendeur::addProduct(Produit p)
{

}

Produit* Vendeur::getProducts()
{
	return nullptr;
}

void Vendeur::deleteProduct(Produit p)
{
}

void Vendeur::modifyProduct(Produit p1, Produit p2)
{
}

Produit Vendeur::getProduct(int id)
{
	return Produit();
}

int Vendeur::getCA()
{
	return 0;
}



