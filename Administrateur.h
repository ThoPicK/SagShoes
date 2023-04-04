#ifndef ADMIN_H
#define ADMIN_H
#include "Vendeur.h"
#include "Client.h"

class Administrateur :
    public Vendeur
{
public:
    Administrateur(int id, std::string name, std::string email, std::string password);
    Client* getClients();
    Vendeur* getVendeurs();
    void addVendeur(Vendeur v);
    void deleteAccount(int id);
};

#endif

