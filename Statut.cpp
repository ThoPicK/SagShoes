#include "Statut.h"
#include <iostream>
#include <string>

class Statut {
private:
    std::string etat;

public:
    Statut() {
        etat = "En préparation";
    }

    void setEnPreparation() {
        etat = "En préparation";
    }

    void setEnLivraison() {
        etat = "En livraison";
    }

    void setLivre() {
        etat = "Livrée";
    }

    std::string getEtat() {
        return etat;
    }

    void afficherEtat() {
        std::cout << "Statut de la commande : " << etat << std::endl;
    }
};