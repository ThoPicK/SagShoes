#include "Statut.h"
#include "Commande.h"
#include <iostream>
#include <string>

class Statut {
public:
    virtual void Handle(Commande& commande) = 0;
    virtual std::string getEtat() = 0;
    virtual void afficherEtat() = 0;
};

class EnPreparation : public Statut {
public:
    void Handle(Commande& commande) override {
        commande.afficherDetails();
        std::cout << "Statut de la commande : En pr�paration" << std::endl;
    }

    std::string getEtat() override {
        return "En pr�paration";
    }

    void afficherEtat() override {
        std::cout << "Statut de la commande : En pr�paration" << std::endl;
    }
};

class EnCours : public Statut {
public:
    void Handle(Commande& commande) override {
        commande.payerCommande();
        std::cout << "Statut de la commande : En cours" << std::endl;
    }

    std::string getEtat() override {
        return "En cours";
    }

    void afficherEtat() override {
        std::cout << "Statut de la commande : En cours" << std::endl;
    }
};

class Expedie : public Statut {
public:
    void Handle(Commande& commande) override {
        std::cout << "Statut de la commande : Exp�di�e" << std::endl;
    }

    std::string getEtat() override {
        return "Exp�di�e";
    }

    void afficherEtat() override {
        std::cout << "Statut de la commande : Exp�di�e" << std::endl;
    }
};

class Livre : public Statut {
public:
    void Handle(Commande& commande) override {
        std::cout << "Statut de la commande : Livr�e" << std::endl;
    }

    std::string getEtat() override {
        return "Livr�e";
    }

    void afficherEtat() override {
        std::cout << "Statut de la commande : Livr�e" << std::endl;
    }
};