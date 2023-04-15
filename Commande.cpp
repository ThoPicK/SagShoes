#include "Commande.h"
#include <iostream>
#include <vector>

Commande::Commande(int commandeId, std::vector<int> commandeItems, double commandeMontant) {
    id = commandeId;
    items = commandeItems;
    montant = commandeMontant;
    statut = new EnPreparation();
}

int Commande::getId() {
    return id;
}

std::vector<int> Commande::getItems() {
    return items;
}

double Commande::getMontant() {
    return montant;
}

void Commande::afficherDetails() {
    std::cout << "Détails de la commande #" << id << ":" << std::endl;
    std::cout << "Articles commandés:" << std::endl;
    for (int i = 0; i < items.size(); i++) {
        std::cout << items[i] << std::endl;
    }
    std::cout << "Montant à payer: " << montant << " EUR" << std::endl;
}

void Commande::payerCommande() {
    // Paiement de la commande
    std::cout << "Paiement effectué pour la commande #" << id << std::endl;
}

void Commande::setExpedie() {
    statut->Handle(*this); 
    delete statut; 
    statut = new Expedie(); 
}

void Commande::setLivre() {
    statut->Handle(*this); 
    delete statut; 
    statut = new Livre(); 
}
