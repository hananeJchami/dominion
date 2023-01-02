#pragma once
#include "Carte.h"
class Deck
{
	int nbCartes;
	Carte cartes[5];
public:
	Deck() = default;
	Deck(int, Carte(&cards)[5]);
	~Deck();

	int getNbCartes();
	Carte* getCartes();

	void setNbCartes(int);
	void setCartes(Carte[]);

	void shuffle(int);
};

