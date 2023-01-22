#pragma once
#include "Carte.h"
#include <map>
class Deck
{
	int nbCartes;
	std::vector<Carte> cartes;
	int nbDuMemeType;
	//std::vector<Carte> pileTypes;

public:
	Deck() = default;
	Deck(int nbCartes, std::vector<Carte> cartes);
	~Deck();

	int getNbCartes();
	std::vector<Carte> getCartes();
	int getNbDuMemeType();
	//std::vector<Carte> getPileTypes();


	void ajouterCarte(Carte);
	void supprimerCarte(Carte);
	std::vector<Carte> resize(int);

	void setNbCartes(int);
	void setCartes(std::vector<Carte> cards);
	void setNbDuMemeType(int);
	void print();
	//void setPileTypes(std::vector<Carte> pileTypes);

	void shuffle(int);
};

