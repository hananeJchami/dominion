#include "Victoire.h"
#include <iostream>
#include <cstdlib>

Victoire::Victoire(int idd, std::string name, int cost, std::string aType, Fonction abilities[5], int value)
	: Carte(idd, name, cost, aType), valeur(value) {
	aType = "Victoire";
}

Victoire::~Victoire() {}

int Victoire::getValeur() { return valeur; }
void Victoire::setValeur(int value) { valeur = value; }

void Victoire::print() {
	Carte::print();
	std::cout << "Valeur : " << valeur;
}