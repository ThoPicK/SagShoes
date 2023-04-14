#include "Panier.h"
#include <iostream>
#include <vector>


void Panier::ajouterItem(int itemId) {
    items.push_back(itemId);
}

void Panier::retirerItem(int itemId) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == itemId) {
            items.erase(items.begin() + i);
            break;
        }
    }
}

void Panier::vider() {
    items.clear();
}

void Panier::commander() {
    std::cout << "Commande passée pour les articles suivants:" << std::endl;
    for (int i = 0; i < items.size(); i++) {
        std::cout << items[i] << std::endl;
    }
    vider();
}
