#include "Royaume.h"
#include <iostream>
#include <cstdlib>
#include <vector>

Royaume::Royaume(int idd, std::string name, int cost, std::string aType, std::vector<Fonction*> abilities,int value)
	: Carte(idd, name, cost, aType, abilities, value) {
	setIsAction(true);
	setIsVictoireOrTresor(false);
	aType = "Royaume";
}

// Royaume::~Royaume() { this->~Carte(); }
Royaume::~Royaume() {}

