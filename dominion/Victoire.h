#pragma once
#include "Carte.h"
class Victoire : public Carte
{
	int valeur;
public:
	// Victoire(int, std::string, int, Fonction, int);
	Victoire(int idd, std::string name, int cost, std::string aType,Fonction abilities[5], int value);
	~Victoire();

	int getValeur();

	void setValeur(int);
	void print();


};