#pragma once
#ifndef ARTICLE_H
#define ARTICLE_H


class Article
{
private:
	int id;
	int quantite;
	int taille;

public:
	Article();
	Article(int id, int quantite, double taille);

	int getId()const;
	void setId(int id);

	int getQuantite() const;
	void setQuantite(int quantite);

	double getTaille() const;
	void setTaille(double taille);

};

#endif

