#pragma once
#include "Carte.h"
class Tresor : public Carte
{
	int valeur;
public:
	Tresor(int idd, std::string name, int cost, std::string aType, Fonction abilities[5], int value);
	~Tresor();

	int getValeur();

	void setValeur(int);
	void print();
};

