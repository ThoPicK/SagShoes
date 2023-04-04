#ifndef VENDEUR_H
#define VENDEUR_H
#include "User.h"
#include "Produit.h"
using namespace std;

class Vendeur :
    public User
{
public:
    Vendeur(int id, std::string name, std::string email, std::string password);
    void addProduct(Produit p);
    Produit* getProducts();
    void deleteProduct(Produit p);
    void modifyProduct(Produit p1, Produit p2);
    Produit getProduct(int id);
    int getCA();
    std::string getName() { return name_; };
};

#endif
