#ifndef STATUT_H
#define STATUT_H
#include "Commande.h"
#include <string>

class Commande;

class Statut {
protected: 
    std::string etat;

public:
    Statut();
    virtual void Handle(Commande& commande);
    std::string getEtat();
    void afficherEtat();
};

class EnPreparation : public Statut {
public:
    EnPreparation();
    void Handle(Commande& commande) override;
};

class EnCours : public Statut {
public:
    EnCours();
    void Handle(Commande& commande) override;
};

class Livre : public Statut {
public:
    Livre();
    void Handle(Commande& commande) override;
};


#endif 