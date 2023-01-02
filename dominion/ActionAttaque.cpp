#include "ActionAttaque.h"
#include <iostream>
#include <cstdlib>

ActionAttaque::ActionAttaque(int idd, std::string name, int cost, std::string aType, Fonction abilities[5])
	: Royaume(idd, name, cost,aType) {
	aType = "Action-Attaque";
}

ActionAttaque::~ActionAttaque() {}