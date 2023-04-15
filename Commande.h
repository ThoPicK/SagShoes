#ifndef COMMANDE_H
#define COMMANDE_H

#include "Statut.h"
#include <iostream>
#include <vector>

class Statut;

class Commande {
private:
    int id;
    std::vector<int> items;
    double montant;
    Statut* statut;

public:
    Commande(int commandeId, std::vector<int> commandeItems, double commandeMontant);
    int getId();
    std::vector<int> getItems();
    double getMontant();
    void afficherDetails();
    void payerCommande();
    void setEnCours();
    void setLivre();
};

#endif
