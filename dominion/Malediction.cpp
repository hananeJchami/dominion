#include "Malediction.h"
#include <iostream>
#include <cstdlib>

Malediction::Malediction(int idd, std::string name, int cost, std::string aType, Fonction abilities[5])
	: Carte(idd, name, cost,aType) {
	aType = "Malediction";
}

Malediction::~Malediction() {}