#include "ActionReaction.h"
#include <iostream>
#include <cstdlib>

ActionReaction::ActionReaction(int idd, std::string name, int cost, std::string aType, std::vector<Fonction*> abilities, int value)
	: Royaume(idd, name, cost,aType, abilities,value) {
	aType = "Action-Reaction";
	value = 0;
}

ActionReaction::~ActionReaction() {}