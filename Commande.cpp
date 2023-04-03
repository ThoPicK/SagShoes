#include "Commande.h"
#include <iostream>
#include <vector>

class Commande {
private:
    int id;
    std::vector<int> items;
    double montant;

public:
    Commande(int commandeId, std::vector<int> commandeItems, double commandeMontant) {
        id = commandeId;
        items = commandeItems;
        montant = commandeMontant;
    }

    int getId() {
        return id;
    }

    std::vector<int> getItems() {
        return items;
    }

    double getMontant() {
        return montant;
    }

    void afficherDetails() {
        std::cout << "D�tails de la commande #" << id << ":" << std::endl;
        std::cout << "Articles command�s:" << std::endl;
        for (int i = 0; i < items.size(); i++) {
            std::cout << items[i] << std::endl;
        }
        std::cout << "Montant � payer: " << montant << " EUR" << std::endl;
    }

    void payerCommande() {
        // Paiement de la commande
        std::cout << "Paiement effectu� pour la commande #" << id << std::endl;
    }
};