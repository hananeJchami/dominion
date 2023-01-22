#pragma once
#include "Royaume.h"
class Action : public Royaume
{
public:

	Action(int idd, std::string name, int cost, std::string aType, std::vector<Fonction*> abilities, int value);
	~Action();

};

