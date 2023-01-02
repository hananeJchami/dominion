#include "Royaume.h"
#include <iostream>
#include <cstdlib>

Royaume::Royaume(int idd, std::string name, int cost, std::string aType)
	: Carte(idd, name, cost, aType) {
	aType = "Royaume";
}
// Royaume::~Royaume() { this->~Carte(); }
Royaume::~Royaume() {}

