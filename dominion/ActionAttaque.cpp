#include "ActionAttaque.h"
#include <iostream>
#include <cstdlib>

ActionAttaque::ActionAttaque(int idd, std::string name, int cost, std::string aType, std::vector<Fonction*> abilities, int value)
	: Royaume(idd, name, cost,aType, abilities,value) {
	aType = "Action-Attaque";
	value = 0;
}

ActionAttaque::~ActionAttaque() {}