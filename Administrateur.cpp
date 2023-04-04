#include "Administrateur.h"

Administrateur::Administrateur(int id, std::string name, std::string email, std::string password):
	Vendeur(id,name,email,password)
{
}

Client* Administrateur::getClients()
{
	return nullptr;
}

Vendeur* Administrateur::getVendeurs()
{
	return nullptr;
}

void Administrateur::addVendeur(Vendeur v)
{

}

void Administrateur::deleteAccount(int id)
{
}
