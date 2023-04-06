#include "Produit.h"
using namespace std;


Produit::Produit(int id, int stock, float prix, float prixLivraison, std::string nom, std::string description): ):
	id(id), stock(stock), prix(prix), prixlivraison(prixLivraison), nom(nom), description(description){}

Produit::Produit()
{
}

Produit::Produit(int id, int stock, float prix, float prixLivraison, std::string nom, std::string description)
{
}

int Produit::getId()const {
	return id;
}
void Produit::setId(int id) {
	this->id = id;
}
int Produit::getStock() const {
	return stock; 
}
void Produit::setStock(int stock) {
	this->stock = stock;
}

float Produit::getPrix() const {
	return prix; 
}
void Produit::setPrix(float prix) {
	this->prix = prix;
}

float Produit::getPrixlivraison() const { 
	return prixlivraison; 
}
void Produit::setPrixlivraison(float prixlivraison) { 
	this->prixlivraison = prixlivraison;
}

std::string Produit::getNom() const {
	return nom;
}
void Produit::setNom(std::string nom) {
	this->nom = nom;
}

std::string Produit::getDescription() const {
	return description;
}
void Produit::setDescription(std::string description) {
	this->description = description;
}
