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
        std::cout << "Statut de la commande : En préparation" << std::endl;
    }

    std::string getEtat() override {
        return "En préparation";
    }

    void afficherEtat() override {
        std::cout << "Statut de la commande : En préparation" << std::endl;
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
        std::cout << "Statut de la commande : Expédiée" << std::endl;
    }

    std::string getEtat() override {
        return "Expédiée";
    }

    void afficherEtat() override {
        std::cout << "Statut de la commande : Expédiée" << std::endl;
    }
};

class Livre : public Statut {
public:
    void Handle(Commande& commande) override {
        std::cout << "Statut de la commande : Livrée" << std::endl;
    }

    std::string getEtat() override {
        return "Livrée";
    }

    void afficherEtat() override {
        std::cout << "Statut de la commande : Livrée" << std::endl;
    }
};