#pragma once
#include "Carte.h"
class Victoire : public Carte
{
public:
	Victoire(int idd, std::string name, int cost, std::string aType, std::vector<Fonction*> abilities, int value);
	~Victoire();
};