#pragma once

#ifndef COMMANDE_H
#define COMMANDE_H

#include <vector>

class Commande {
private:
    int id;
    std::vector<int> items;
    double montant;

public:
    Commande(int commandeId, std::vector<int> commandeItems, double commandeMontant);
    int getId();
    std::vector<int> getItems();
    double getMontant();
    void afficherDetails();
    void payerCommande();
};

#endif
