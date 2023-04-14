#ifndef CLIENT_H
#define CLIENT_H
#include "User.h"
#include "Commande.h"
#include "Panier.h"
#include "Produit.h"

class Client :
    public User
{
public:
    Client(int id, std::string name, std::string email, std::string password, Panier panier);
    Client(int id, std::string name, std::string email, std::string password);
    Commande* getCommandes();
    void addToCart(Produit p,double taille,int qunatite);
    void order();
    std::string getName() { return name_; };
private:
    Panier panier_;

};

#endif 

