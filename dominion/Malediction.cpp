#include "Malediction.h"
#include <iostream>
#include <cstdlib>

Malediction::Malediction(int idd, std::string name, int cost, std::string aType, std::vector<Fonction*> abilities, int value)
	: Carte(idd, name, cost,aType, abilities, value) {
	aType = "Malediction";
}

Malediction::~Malediction() {}