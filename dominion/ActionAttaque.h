#pragma once
#include "Royaume.h"
class ActionAttaque : public Royaume
{
public:
	ActionAttaque(int idd, std::string name, int cost, std::string aType, Fonction abilities[5]);
	~ActionAttaque();
};

