#include "Statut.h"
#include <iostream>
#include <string>

class Statut {
private:
    std::string etat;

public:
    Statut() {
        etat = "En pr�paration";
    }

    void setEnPreparation() {
        etat = "En pr�paration";
    }

    void setEnLivraison() {
        etat = "En livraison";
    }

    void setLivre() {
        etat = "Livr�e";
    }

    std::string getEtat() {
        return etat;
    }

    void afficherEtat() {
        std::cout << "Statut de la commande : " << etat << std::endl;
    }
};