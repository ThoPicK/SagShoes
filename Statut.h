#ifndef STATUT_H
#define STATUT_H
#include "Commande.h"
#include <string>
class Commande;

class Statut {
private:
    std::string etat;

public:
    Statut();
    virtual void Handle(Commande& commande);
    std::string getEtat();
    void afficherEtat();
};

class EnPreparation : public Statut {
public:
    void Handle(Commande& commande) override;
};

class EnCours : public Statut {
public:
    void Handle(Commande& commande) override;
};

class Expedie : public Statut {
public:
    void Handle(Commande& commande) override;
};

class Livre : public Statut {
public:
    void Handle(Commande& commande) override;
};

#endif 