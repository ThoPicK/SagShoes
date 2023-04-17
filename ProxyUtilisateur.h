#pragma once
#ifndef PROXY_UTILISATEUR_H
#define PROXY_UTILISATEUR_H
#include "User.h"
#include "Administrateur.h"
#include "Vendeur.h"
#include "Client.h"

class ProxyUtilisateur :
	public User
{
public:
	ProxyUtilisateur(int id, std::string name, std::string email, std::string password);
	bool login(std::string email, std::string password);
	bool isAdmin();
	bool isVendeur();
	bool isClient();
	void setAdmin(Administrateur* admin);
	void setVendeur(Vendeur* vendeur);
	void setClient(Client* client);

private:
	Administrateur* admin_;
	Vendeur* vendeur_;
	Client* client_;
};
#endif