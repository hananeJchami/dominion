#include "ActionReaction.h"
#include <iostream>
#include <cstdlib>

ActionReaction::ActionReaction(int idd, std::string name, int cost, std::string aType, Fonction abilities[5])
	: Royaume(idd, name, cost,aType) {
	aType = "Action-Reaction";
}

ActionReaction::~ActionReaction() {}