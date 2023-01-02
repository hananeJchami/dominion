#pragma once
#include "Carte.h"
class Malediction : public Carte
{
public:
	Malediction(int idd, std::string name, int cost, std::string aType, Fonction abilities[5]);
	~Malediction();
};

