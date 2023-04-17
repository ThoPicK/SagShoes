#include "ProxyUtilisateur.h"

ProxyUtilisateur::ProxyUtilisateur(int id, std::string name, std::string email, std::string password) :
	User(id, name, email, password)
{
	admin_ = nullptr;
	vendeur_ = nullptr;
	client_ = nullptr;
}

bool ProxyUtilisateur::login(std::string email, std::string password)
{
	if (admin_ && admin_->getEmail() == email && admin_->getPassword() == password)
	{
		return true;
	}
	else if (vendeur_ && vendeur_->getEmail() == email && vendeur_->getPassword() == password)
	{
		return true;
	}
	else if (client_ && client_->getEmail() == email && client_->getPassword() == password)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ProxyUtilisateur::isAdmin()
{
	return admin_ != nullptr;
}

bool ProxyUtilisateur::isVendeur()
{
	return vendeur_ != nullptr;
}

bool ProxyUtilisateur::isClient()
{
	return client_ != nullptr;
}

void ProxyUtilisateur::setAdmin(Administrateur* admin)
{
	admin_ = admin;
}

void ProxyUtilisateur::setVendeur(Vendeur* vendeur)
{
	vendeur_ = vendeur;
}

void ProxyUtilisateur::setClient(Client* client)
{
	client_ = client;
}