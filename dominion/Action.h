#pragma once
#include "Royaume.h"
class Action : public Royaume
{
	Fonction fonctions[5];
public:
	Fonction* getFonctions();
	void setFonctions(Fonction);

	Action(int idd, std::string name, int cost, std::string aType, Fonction abilities[5]);
	~Action();

};

