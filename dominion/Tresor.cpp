#include "Tresor.h"
#include <iostream>
#include <cstdlib>

Tresor::Tresor(int idd, std::string name, int cost, std::string aType, Fonction abilities[5], int value)
	: Carte(idd, name, cost, aType) {
	aType = "Tresor";
	if (name == "Cuivre") { value = 1; }
	if (name == "Argent") { value = 2; }
	if (name == "Or") { value = 3; }

}

Tresor::~Tresor() {}
int Tresor::getValeur() { return valeur; }
void Tresor::setValeur(int value) { valeur = value; }

void Tresor::print() {
	Carte::print();
	std::cout << "Valeur : " << valeur;
}