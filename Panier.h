#pragma once
#ifndef PANIER_H
#define PANIER_H

#include <vector>

class Panier {
private:
    std::vector<int> items;

public:
    void ajouterItem(int itemId);
    void retirerItem(int itemId);
    void vider();
    void commander();
};

#endif