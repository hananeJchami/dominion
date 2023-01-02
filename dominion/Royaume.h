#pragma once
#include "Carte.h"
class Royaume : public Carte
{
public:

	// Royaume(int, std::string, int, Fonction);
	Royaume(int idd, std::string name, int cost, std::string aType);
	~Royaume();
};

