#include "Action.h"
#include <iostream>
#include <cstdlib>

Action::Action(int idd, std::string name, int cost, std::string aType, Fonction abilities[5])
	: Royaume(idd, name, cost,aType) {
	for (int i = 0; i < 1; i++) {
		fonctions[i] = abilities[i];
	}
	aType = "Action";
}

Action::~Action() {}

Fonction* Action::getFonctions() { return fonctions; }

//
//void Action::executerFonctions() {
//
//}