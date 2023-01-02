#include "Joueur.h"
#include "Action.h"
#include "Tresor.h"
#include "Royaume.h"
#include <iostream>
#include <cstdlib>


Joueur::Joueur(Deck deck)
	: deckInitial(deck) {}

Joueur::~Joueur() {}

Deck Joueur::getDeckInitial() { return deckInitial; }
Deck Joueur::getDeckEnMain() { return deckEnMain; }
Deck Joueur::getDeckAPart() { return deckAPart; }
int Joueur::getPointsDeVictoire() { return pointsDeVictoire; }
int Joueur::getNbCartesTresor() { return nbCartesTresor; }
int Joueur::getNbAchat() { return nbAchat; }

void Joueur::setDeckInitial(Deck initial) { deckInitial = initial; }
void Joueur::setDeckEnMain(Deck enMain) { deckEnMain = enMain; }
void Joueur::setDeckAPart(Deck aPart) { deckAPart = aPart; }
void Joueur::setPointsDeVictoire(int points) { pointsDeVictoire = points; }
void Joueur::setNbCartesTresor(int nbTresor) { nbCartesTresor = nbTresor; }
void Joueur::setNbAchat(int nbAllowedPurchases) { nbAchat = nbAllowedPurchases; }

void Joueur::print() {
	std::cout << " Deck initial : " << deckInitial.getCartes()
		<< " Deck en Main : " << deckEnMain.getCartes()
		<< " Deck A Part : " << deckAPart.getCartes();
}



void Joueur::diviserLesCartes() {
	deckInitial.shuffle(5);
	Carte listeDeCartes[5];
	Carte resteDeCartes[5];
	for (int i = 0; i < 3; i++) {
		listeDeCartes[i] = deckInitial.getCartes()[i];
	}
	deckEnMain = (*new Deck(2, listeDeCartes));
	int index = 0;

	for (int i = 3; i < 5; i++) {
		resteDeCartes[index] = deckInitial.getCartes()[i];
		index++;
	}
	deckAPart = (*new Deck(1, resteDeCartes));
}

void Joueur::piocherDeDeckD(Deck deckD, int nbCartesAPiocher) {
	// enlever elements de deck a piocher
	Carte itemsToFill[5];
	for (int i = 0; i < nbCartesAPiocher; i++) {
		itemsToFill[i] = deckD.getCartes()[i];
		deckD.getCartes()[i] = deckD.getCartes()[i + 1];
		deckD.setNbCartes(deckD.getNbCartes() - 1);
	}
}

void Joueur::ajouterADeckD(Carte deckDe[], Deck deckA, int nbCartesAAjouter) {
	// ajouter cartes a deck en main par ex
	//Carte itemsToFill[5];
	for (int i = 0; i < nbCartesAAjouter; i++) {
		deckA.getCartes()[deckA.getNbCartes() + 1] = deckDe[i];
		deckA.setNbCartes(deckA.getNbCartes() + 1);
	}
}

void Joueur::jouerPhaseAction(Action* cartesActionEnMain[]) {

	// check if player can do which actions
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			int difference = cartesActionEnMain[i]->getFonctions()->getNb() - deckAPart.getNbCartes();

			// pour l'action: +X cartes
			if (cartesActionEnMain[i]->getFonctions()[j].getActe() == "cartes") {
				//cartesActionEnMain[i]->getFonctions().getActe()

				// piocher x cartes de votre deck. Si nb des cartes est suffisant
				if (cartesActionEnMain[i]->getFonctions()->getNb() <= deckAPart.getNbCartes()) {
					// cartesActionEnMain[i]->getFonctions()[j].getNb()
					//// enlever elements de deck a piocher
					//for (int i = 0; i < deckAPart.getNbCartes(); i++) {
					//	itemsToFill[i] = deckAPart.getCartes()[i];
					//	deckAPart.getCartes()[i] = deckAPart.getCartes()[i + 1];
					//	deckAPart.setNbCartes(deckAPart.getNbCartes()-1);
					//}
					piocherDeDeckD(deckAPart,cartesActionEnMain[i]->getFonctions()->getNb());
					//// ajouter cartes a deck en main
					//for (int i = 0; i < 5; i++) {
					//	deckEnMain.getCartes()[deckEnMain.getNbCartes() + 1] = itemsToFill[i];
					//	deckEnMain.setNbCartes(deckEnMain.getNbCartes() + 1);
					//}
					ajouterADeckD(deckAPart.getCartes(), deckEnMain, cartesActionEnMain[i]->getFonctions()->getNb());
				}

				// s'il ne suffit pas:
				else {
					// piochez autant
					piocherDeDeckD(deckAPart,deckAPart.getNbCartes());
					// melanger defausse
					deckDefausse.shuffle(deckDefausse.getNbCartes());
					// piocher reste
					piocherDeDeckD(deckDefausse,difference);
					// si ne suffit pas
					// piocher ce qui available
				}
				setNbAchat(1);
			}

			// pour l'action +X coins
				// setNbAchat(1);

			// pour l'action +1 achat
			if (cartesActionEnMain[i]->getFonctions()[j].getActe() == "achat") {
				//cartesActionEnMain[i]->getFonctions().getActe()
				setNbAchat(getNbAchat()+1);
			}
			
			// pour l'action defausser
				// setNbAchat(1);
				
			// pour l'action ecarter
				// setNbAchat(1);
				
			// pour l'action recevoir
				// setNbAchat(1);
				
			// pour l'action devoiler
				// setNbAchat(1);
				
			// pour l'action mettre de cote
				// setNbAchat(1);
		}
	}
	//cartesActionEnMain[0]->executerFonctions();
}

void Joueur::jouerPhaseAchat(Deck deckSupply, Tresor* cartesTresorEnMain[]) {
	// badel el 5 lezim ykoun size de cartesTresorEnMain
	int index = 0;
	int valeurTotal = 0;
	while (index < getNbAchat()) {
		for (int i = 0; i < 5; i++) {
			valeurTotal += cartesTresorEnMain[i]->getValeur();
		}
		for (int i = 0; i < 5; i++) {
			if (deckSupply.getCartes()[i].getCout() <= valeurTotal) {
				// ajouter la carte a la deck en main
				deckEnMain.getCartes()[deckEnMain.getNbCartes() + 1] = deckSupply.getCartes()[i];
				deckEnMain.setNbCartes(deckEnMain.getNbCartes() + 1);

				// enlever la carte de deck supply
				deckSupply.getCartes()[i] = deckSupply.getCartes()[i + 1];
				deckSupply.setNbCartes(deckSupply.getNbCartes() - 1);

				// modifier la valeur total for future uses (si c possible de faire plusieurs achats)
				valeurTotal -= deckSupply.getCartes()[i].getCout();
			}
		}
		index++;
	}
}

void Joueur::jouerPhaseAjustement() {
	Carte listeDeCartes[5];
	Carte resteDeCartes[5];
	int difference = 5 - deckAPart.getNbCartes();
	// assemblage de toutes le cartes en main dans la defausse
	ajouterADeckD(deckEnMain.getCartes(), deckDefausse, deckEnMain.getNbCartes());

	// piocher 5 cartes et les mettre dans deck en main si suffisant
	if (deckAPart.getNbCartes() >= 5) {
		for (int i = 0; i < 5; i++) {
			listeDeCartes[i] = deckAPart.getCartes()[i];
		}
		ajouterADeckD(listeDeCartes, deckEnMain, 5);
	}
	// si pas suffisant 
	else {
		// piocher autant
		for (int i = 0; i < deckAPart.getNbCartes(); i++) {
			listeDeCartes[i] = deckAPart.getCartes()[i];
		}
		ajouterADeckD(listeDeCartes, deckEnMain, deckAPart.getNbCartes());

		// shuffle defausse
		deckDefausse.shuffle(deckDefausse.getNbCartes());

		// piocher le reste de la defausse
		int index = 0;
		for (int i= difference; i < 5 ; i++) {
			for (int i = 3; i < 5; i++) {
				resteDeCartes[index] = deckDefausse.getCartes()[i];
				index++;
			}
		}
	}

	// tour d'un autre joueur
}

void Joueur::jouerTour(Deck deckSupply) {
	int count = 0;
	bool carteActionExiste = false;
	bool carteTresorExiste = false;
	Action* cartesActionEnMain[5];
	Tresor* cartesTresorEnMain[5];
	for (int i = 0; i < deckEnMain.getNbCartes(); i++) {

		// phase 1: action
		if (deckEnMain.getCartes()[i].getType() == "Action") {
			// casting not working
			Action* action = static_cast<Action*> (&deckEnMain.getCartes()[i]);
			//Carte* carte = &deckEnMain.getCartes()[i];
			//Action* action = dynamic_cast<Action*> (carte);
			action->getFonctions();
			cartesActionEnMain[count] = action;
			carteActionExiste = true;
			count++;
		}

		// phase 2: achat
		if (deckEnMain.getCartes()[i].getType() == "Tresor") {
			// casting not working
			Tresor* tresor = static_cast<Tresor*> (&deckEnMain.getCartes()[i]);
			tresor->getValeur();
			cartesTresorEnMain[count] = tresor;
			carteTresorExiste = true;
			count++;
		}

		// phase 3: ajustement
		jouerPhaseAjustement();
	}
	if (carteActionExiste) {
		jouerPhaseAction(cartesActionEnMain);
		// si apres piochant le joueur rencontre une nouvelle carte action
		jouerTour(deckSupply);
	}

	if (carteTresorExiste) {
		jouerPhaseAchat(deckSupply, cartesTresorEnMain);
		// si apres piochant le joueur rencontre une nouvelle carte tresor
		jouerTour(deckSupply);
	}
}
