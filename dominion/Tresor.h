#pragma once
#include "Carte.h"
class Tresor : public Carte
{
public:
	Tresor(int idd, std::string name, int cost, std::string aType, std::vector<Fonction*> abilities, int value);
	~Tresor();
};

