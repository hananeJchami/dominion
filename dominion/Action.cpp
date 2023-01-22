#include "Action.h"
#include <iostream>
#include <cstdlib>

Action::Action(int idd, std::string name, int cost, std::string aType, std::vector<Fonction*> abilities, int value)
	: Royaume(idd, name, cost,aType, abilities,value) {
	aType = "Action";
	value = 0;
}
Action::~Action() {}
//
//void Action::executerFonctions() {
//
//}