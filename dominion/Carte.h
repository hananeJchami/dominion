#pragma once
#include <string>
#include "Fonction.h"
class Carte
{
	int id;
	std::string nom;
	int cout;
	// ba3d fi type
	Fonction fonctions[3];

public:
	Carte();
	~Carte();
};

