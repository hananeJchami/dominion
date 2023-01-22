#pragma once
#include "Carte.h"
class Royaume : public Carte
{
public:
	Royaume(int idd, std::string name, int cost, std::string aType, std::vector<Fonction*> abilities, int value);
	~Royaume();
};

