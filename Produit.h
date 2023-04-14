#ifndef PRODUIT_H
#define PRODUIT_H
#include "String"
#include "Map"

class Produit
{
private :
	int id;
	std::map<int,int> stock; 
	float prix;
	float prixlivraison; 
	std::string nom;
	std::string description;

public:
	Produit();
	Produit(int id, std::map<int,int> stock, float prix, float prixLivraison, std::string nom, std::string description);

	int getId() const;
	void setId(int id);

	std::map<int, int> getStock() const;
	int getStock(int taille) const;
	void setStock(std::map<int,int> stock);
	void setStock(int taille, int stock);

	float getPrix() const;
	void setPrix(float prix);

	float getPrixlivraison() const;
	void setPrixlivraison(float prixlivraison);

	std::string getNom()const;
	void setNom(std::string nom);

	std::string getDescription()const;
	void setDescription(std::string description);

};
#endif

