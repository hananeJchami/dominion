#pragma once
#include "Royaume.h"
class ActionReaction : public Royaume
{
public:
	ActionReaction(int idd, std::string name, int cost, std::string aType, Fonction abilities[5]);
	~ActionReaction();
};

