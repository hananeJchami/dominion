#pragma once
#include "Deck.h"
#include "Action.h"
#include "Tresor.h"
#include <string>
#include <vector>
class Joueur
{
	int id;
	Deck deckInitial;
	Deck deckEnMain;
	Deck deckAPart;
	Deck deckDefausse;
	//Deck deckCartesSupprimees;
	int pointsDeVictoire;
	int nbCartesTresor;
	int qteMonnaie;
	int nbAchat;
	int nbAction;
	int extraCoins;

public:
	Joueur(int, Deck);
	~Joueur();

	int getId();
	Deck getDeckInitial();
	Deck getDeckEnMain();
	Deck getDeckAPart();
	Deck getDeckDefausse();
	//Deck getDeckCartesSupprimees();

	int getPointsDeVictoire();
	int getNbCartesTresor();
	int getQteMonnaie();
	int getNbAchat();
	int getNbAction();
	int getExtraCoins();

	void setDeckInitial(Deck);
	void setDeckEnMain(Deck);
	void setDeckAPart(Deck);
	void setDeckDefausse(Deck);
	//void setDeckCartesSupprimees(Deck);

	void setPointsDeVictoire(int points);
	void setNbCartesTresor(int cartesTresor);
	void setQteMonnaie(int qte);
	void setNbAchat(int);
	void setNbAction(int);
	void setExtraCoins(int);

	void printDecks();
	void printEndDeck(Deck,int);
	void diviserLesCartes();
	std::vector<Carte> piocherDeDeckD(Deck, int);
	//void piocherDeDeckD(Deck, int);
	//void ajouterADeckD(Carte*, Deck, int);
	std::vector<Carte> ajouterADeckD(Deck, std::vector<Carte>);
	//void ajouterADeckD(Carte* deckDe[], Deck deckA, int nbCartesAAjouter);
	void eraseFromVector(std::vector<Carte>);
	Deck* jouerTour(Deck);
	std::vector<Carte> carteActionAJouer();
	//void jouerTour2(Deck);
	void jouerCartes(std::vector<Carte>, std::vector<Carte>, Deck);
	//void jouerPhaseAction(Action* cartesActionEnMain[]);
	void jouerPhaseAction(std::vector<Carte> cartesActionEnMain);
	//void jouerPhaseAchat(Deck deckSupply, Tresor* cartesTresorEnMain[]);
	//void jouerPhaseAchat(Deck deckSupply, std::vector<Carte> cartesTresorEnMain);
	//std::vector<Carte> jouerPhaseAchat(Deck deckSupply, std::vector<Carte> cartesTresorEnMain);
	Deck jouerPhaseAchat(Deck deckSupply, std::vector<Carte> cartesTresorEnMain);
	void jouerPhaseAjustement();
	int collecterPointsVictoire();
};

