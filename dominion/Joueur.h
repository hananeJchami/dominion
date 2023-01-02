#pragma once
#include "Deck.h"
#include "Action.h"
#include <string>
#include <vector>
class Joueur
{
	Deck deckInitial;
	Deck deckEnMain;
	Deck deckAPart;
	Deck deckDefausse;
	int pointsDeVictoire;
	int nbCartesTresor;
	int nbAchat;

public:
	Joueur(Deck);
	~Joueur();

	Deck getDeckInitial();
	Deck getDeckEnMain();
	Deck getDeckAPart();
	Deck getDeckDefausse();
	int getPointsDeVictoire();
	int getNbCartesTresor();
	int getNbAchat();

	void setDeckInitial(Deck);
	void setDeckEnMain(Deck);
	void setDeckAPart(Deck);
	void setDeckDefausse(Deck);
	void setPointsDeVictoire(int points);
	void setNbCartesTresor(int cartesTresor);
	void setNbAchat(int);

	void print(); // for now useless
	void diviserLesCartes();
	void piocherDeDeckD(Deck, int);
	void ajouterADeckD(Carte*, Deck, int);
	//void ajouterADeckD(Carte* deckDe[], Deck deckA, int nbCartesAAjouter);
	void jouerTour(Deck);
	void jouerPhaseAction(Action* cartesActionEnMain[]);
	void jouerPhaseAchat(Deck deckSupply, Tresor* cartesTresorEnMain[]);
	void jouerPhaseAjustement();
};

