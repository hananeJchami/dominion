#pragma once
#include "Royaume.h"
class ActionAttaque : public Royaume
{
public:
	ActionAttaque(int idd, std::string name, int cost, std::string aType, std::vector<Fonction*> abilities, int value);
	~ActionAttaque();
};

