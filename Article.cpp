#include "Article.h"

Article::Article(int id, int quantite, double taille) : id(id), quantite(quantite), taille(taille) {}

int Article::getId() const {
	return id; 
}
void Article::setId(int id) {
	this->id = id;
}

int Article::getQuantite() const { 
	return quantite;
}
void Article::setQuantite(int quantite) {
	this->quantite = quantite;
}

double Article::getTaille() const { 
	return taille;
}
void Article::setTaille(double taille) {
	this->taille = taille;
}
