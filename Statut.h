#ifndef STATUT_H
#define STATUT_H

#include <string>

class Statut {
private:
    std::string etat;

public:
    Statut();
    void setEnPreparation();
    void setEnLivraison();
    void setLivre();
    std::string getEtat();
    void afficherEtat();
};

#endif 