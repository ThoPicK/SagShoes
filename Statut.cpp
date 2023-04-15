#include "Statut.h"
#include "Commande.h"
#include <iostream>
#include <string>


void Statut::Handle(Commande& commande) {
    commande.afficherDetails();
    std::cout << "Statut de la commande : " << etat << std::endl;
}

std::string Statut::getEtat() {
    return etat;
}

void Statut::afficherEtat() {
    std::cout << "Statut de la commande : " << etat << std::endl;
}

EnPreparation::EnPreparation() {
    etat = "En pr�paration";
}

void EnPreparation::Handle(Commande& commande) {
    commande.afficherDetails();
    std::cout << "Statut de la commande : " << etat << std::endl;
}

EnCours::EnCours() {
    etat = "En cours";
}

void EnCours::Handle(Commande& commande) {
    commande.payerCommande();
    std::cout << "Statut de la commande : " << etat << std::endl;
}

Livre::Livre() {
    etat = "Livr�e";
}

void Livre::Handle(Commande& commande) {
    std::cout << "Statut de la commande : " << etat << std::endl;
}

