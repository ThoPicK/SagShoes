#include "Panier.h"
#include <iostream>
#include <vector>

class Panier {
private:
    std::vector<int> items;

public:
    void ajouterItem(int itemId) {
        items.push_back(itemId);
    }

    void retirerItem(int itemId) {
        for (int i = 0; i < items.size(); i++) {
            if (items[i] == itemId) {
                items.erase(items.begin() + i);
                break;
            }
        }
    }

    void vider() {
        items.clear();
    }

    void commander() {
        std::cout << "Commande passée pour les articles suivants:" << std::endl;
        for (int i = 0; i < items.size(); i++) {
            std::cout << items[i] << std::endl;
        }
        vider();
    }
};