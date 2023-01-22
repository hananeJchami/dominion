#include "Victoire.h"
#include <iostream>
#include <cstdlib>

Victoire::Victoire(int idd, std::string name, int cost, std::string aType, std::vector<Fonction*> abilities, int value)
	: Carte(idd, name, cost, aType, abilities, value) {
	setIsAction(false);
	setIsVictoireOrTresor(true);
	aType = "Victoire";
}

Victoire::~Victoire() {}
