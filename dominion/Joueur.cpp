#include "Joueur.h"
#include "Action.h"
#include "Tresor.h"
#include "Royaume.h"
#include <iostream>
#include <cstdlib>


Joueur::Joueur(int idd, Deck deck)
	: id(idd), deckInitial(deck) {
	nbAchat = 1;
	nbAction = 1;
}

Joueur::~Joueur() {}

int Joueur::getId() { return id; }
Deck Joueur::getDeckInitial() { return deckInitial; }
Deck Joueur::getDeckEnMain() { return deckEnMain; }
Deck Joueur::getDeckAPart() { return deckAPart; }
Deck Joueur::getDeckDefausse() { return deckDefausse; }
//Deck Joueur::getDeckCartesSupprimees() { return deckCartesSupprimees; }
int Joueur::getPointsDeVictoire() { return pointsDeVictoire; }
int Joueur::getNbCartesTresor() { return nbCartesTresor; }
int Joueur::getQteMonnaie() { return qteMonnaie; }
int Joueur::getNbAchat() { return nbAchat; }
int Joueur::getNbAction() { return nbAction; }
int Joueur::getExtraCoins() { return extraCoins; }

void Joueur::setDeckInitial(Deck initial) { deckInitial = initial; }
void Joueur::setDeckEnMain(Deck enMain) { deckEnMain = enMain; }
void Joueur::setDeckAPart(Deck aPart) { deckAPart = aPart; }
void Joueur::setDeckDefausse(Deck defausse) { deckDefausse = defausse; }
//void Joueur::setDeckCartesSupprimees(Deck supprimees) { deckCartesSupprimees = supprimees; }
void Joueur::setPointsDeVictoire(int points) { pointsDeVictoire = points; }
void Joueur::setNbCartesTresor(int nbTresor) { nbCartesTresor = nbTresor; }
void Joueur::setQteMonnaie(int qte) { qteMonnaie = qte; }
void Joueur::setNbAchat(int nbAllowedPurchases) { nbAchat = nbAllowedPurchases; }
void Joueur::setNbAction(int nbAllowedActions) { nbAction = nbAllowedActions; }
void Joueur::setExtraCoins(int extra) { extraCoins = extra; }

void Joueur::printDecks() {
	std::cout << " Joueur " << this->getId()<<"\n";
	//std::cout << " Deck initial : \n";
	//for (int i = 0; i < deckInitial.getNbCartes(); i++) {
	//	std::cout << deckInitial.getCartes()[i];
	//}
	std::cout << "\n Deck en main : \n";
	for (int i = 0; i < deckEnMain.getNbCartes(); i++) {
		std::cout << deckEnMain.getCartes().at(i);
	}
	std::cout << "\n Deck a part : \n";
	for (int i = 0; i < deckAPart.getNbCartes(); i++) {
		std::cout << deckAPart.getCartes().at(i);
	}
	std::cout << "\n Deck de defausse : \n";
	if (deckDefausse.getCartes().size() != 0) {
		for (int i = 0; i < deckDefausse.getCartes().size(); i++) {
			std::cout << deckDefausse.getCartes().at(i);
		}
	}
	std::cout << "\n";
}

void Joueur::printEndDeck(Deck endDeck,int bound) {
	std::cout << "\n Decks melangees : \n";
	for (int i = 0; i < bound; i++) {
		std::cout << endDeck.getCartes().at(i);
	}
	std::cout << "\n";
}



void Joueur::diviserLesCartes() {
	deckInitial.shuffle(10);
	std::vector<Carte> listeDeCartes;
	std::vector<Carte> resteDeCartes;
	std::vector<Carte> emptyVector;

	for (int i = 0; i < 5; i++) {
		listeDeCartes.push_back(deckInitial.getCartes().at(i));
	}
	deckEnMain = (*new Deck(listeDeCartes.size(), listeDeCartes));

	for (int i = 5; i < deckInitial.getNbCartes(); i++) {
		resteDeCartes.push_back(deckInitial.getCartes().at(i));
	}
	deckAPart = (*new Deck(resteDeCartes.size(), resteDeCartes));
	deckDefausse = (*new Deck(0, emptyVector));
}

std::vector<Carte> Joueur::piocherDeDeckD(Deck deckD, int nbCartesAPiocher) {
	// enlever elements de deck a piocher
	std::vector<Carte> itemsToFill;
	for (int i = 0; i < nbCartesAPiocher; i++) {
		//// testH
		//itemsToFill.push_back(deckD.getCartes().at(i));
		////itemsToFill.push_back(deckD.getCartes().at(0));
		//eraseFromVector(deckD.getCartes());
		//deckD.setNbCartes(deckD.getNbCartes() - 1);

		// insert mesh zabit
		itemsToFill.insert(itemsToFill.end(), deckD.getCartes().at(i));
		deckD.supprimerCarte(deckD.getCartes().at(i));
	}
	return deckD.getCartes();

}

std::vector<Carte>  Joueur::ajouterADeckD(Deck deckARemplir, std::vector<Carte> cartesAjoutees) {
	// ajouter cartes a deck en main par ex
	for (int i = 0; i < cartesAjoutees.size(); i++) {
		//deckARemplir.getCartes().push_back(cartesAjoutees.at(i));
		//deckARemplir.setNbCartes(deckARemplir.getNbCartes() + 1);
		deckARemplir.ajouterCarte(cartesAjoutees.at(i));
	}
	return deckARemplir.getCartes();
}

void Joueur::eraseFromVector(std::vector<Carte> cartes) {
	for (auto iter = cartes.begin();
		iter != cartes.end();
		++iter)
	{
		if (iter != cartes.begin())
		{
			iter = std::prev(iter);
			continue;
		}
	}
}


void Joueur::jouerPhaseAction(std::vector<Carte> cartesActionEnMain) {
	int index = 0;
	int valeurTotal = getQteMonnaie();
	int a = getNbAction();
	int qte = 0;

	while (index < getNbAction()) {
		// check if player can do which actions
		for (int i = 0; i < cartesActionEnMain.size(); i++) { 
			std::cout << "Carte piochee d'id: "<< cartesActionEnMain.at(i).getId()<<" est de type " << cartesActionEnMain.at(i).getType() << "\n";
			std::cout << "debut de la phase action:\n";
			for (int j = 0; j < cartesActionEnMain.at(i).getFonctions().size(); j++) { //pour les fonctions de chaque carte
				std::cout << "pouvoir n"<<j+1<<" de cette carte: +"
					<< cartesActionEnMain.at(i).getFonctions().at(j)->getNb()
					<<" "<< cartesActionEnMain.at(i).getFonctions().at(j)->getActe()<<"\n";
				int nbdeLaFonction = cartesActionEnMain.at(i).getFonctions().at(j)->getNb();
				int difference = nbdeLaFonction - deckAPart.getNbCartes();


				// pour l'action: +X cartes
				if (cartesActionEnMain.at(i).getFonctions().at(j)->getActe() == "Carte(s)") {
					// piocher x cartes de votre deck. Si nb des cartes est suffisant

					if (nbdeLaFonction <= deckAPart.getCartes().size()) {
						std::cout << "nb de cartes demandees dans le pouvoir est suffisant donc joueur peut piocher de sa deck \n";
						for (int i = 0; i < nbdeLaFonction; i++) {
							deckEnMain.ajouterCarte(deckAPart.getCartes().at(i));

							if (deckAPart.getCartes().at(i).getType() == "Tresor") {
								qteMonnaie += deckAPart.getCartes().at(i).getValeur();
								//setQteMonnaie(getQteMonnaie()+1);
							}
							setQteMonnaie(qteMonnaie);
						}
						for (int i = 0; i < nbdeLaFonction; i++) {
							deckAPart.supprimerCarte(deckAPart.getCartes().at(0));
						}

						//deckDefausse.setNbCartes(cartesActionEnMain.size());
						deckDefausse.ajouterCarte(cartesActionEnMain.at(i));
						deckEnMain.supprimerCarte(cartesActionEnMain.at(i));
						std::cout << "Updated decks\n";
						printDecks();
						break;
					}
					// s'il ne suffit pas:
					else {
						std::cout << "nb de cartes demandees dans le pouvoir n'est pas suffisant\n";
						// piochez autant
						std::cout<< "Donc joueur doit piocher autant possible de sa deck. ici c'est " << deckAPart.getCartes().size() << "\n";
						for (int i = 0; i < deckAPart.getNbCartes(); i++) {
							deckEnMain.ajouterCarte(deckAPart.getCartes().at(i));
							if (deckAPart.getCartes().at(i).getType() == "Tresor") {
								qteMonnaie += deckAPart.getCartes().at(i).getValeur();
								//setQteMonnaie(getQteMonnaie() + 1);
							}
							setQteMonnaie(qteMonnaie);

						}
						deckAPart.getCartes().clear();
						// melanger defausse
						std::cout<< "puis deck de defausse should be shuffled et joueur pioche de la defausse\n";
						deckDefausse.shuffle(deckDefausse.getNbCartes());
						// piocher reste
						if (deckDefausse.getNbCartes() == 0) {
							deckDefausse.getCartes().clear();
						}
						for (int i = 0; i < difference; i++) {
							deckEnMain.ajouterCarte(deckDefausse.getCartes().at(i));
							deckDefausse.supprimerCarte(deckDefausse.getCartes().at(i));
							deckDefausse.ajouterCarte(cartesActionEnMain.at(i));
							deckEnMain.supprimerCarte(cartesActionEnMain.at(i));
							if (deckEnMain.getCartes().at(i).getType() == "Tresor") {
								setQteMonnaie(getQteMonnaie() + 1);
							}
						}
						// si ne suffit pas
						// piocher ce qui available

						deckDefausse.ajouterCarte(cartesActionEnMain.at(i));
						deckEnMain.supprimerCarte(cartesActionEnMain.at(i));
						std::cout << "Updated decks: \n";
						printDecks();
						break;
					}
					setNbAchat(1);
					setNbAction(1);
				}


				// pour l'action +X Actions
				if (cartesActionEnMain.at(i).getFonctions().at(j)->getActe() == "Action(s)") {
					// compter le nb d'actions restante a voix haute
					setNbAchat(1);
					setNbAction(cartesActionEnMain.at(i).getFonctions().at(j)->getNb() + getNbAction() - 1);
					deckDefausse.ajouterCarte(cartesActionEnMain.at(i));
					deckEnMain.supprimerCarte(cartesActionEnMain.at(i));
					std::cout << "nouveau nb d'actions restante au joueur: "<<getNbAction()<<"\n";
					std::cout << "Updated decks: \n";
					printDecks();
					break;
				}

				// pour l'action +X coins
				// avoir x pieces supp lors de la phase achat mais pas de cartes tresor supp
				if (cartesActionEnMain.at(i).getFonctions().at(j)->getActe() == "Coin(s)") {
					for (int i = 0; i < deckEnMain.getCartes().size(); i++) {
						if (deckEnMain.getCartes().at(i).getType() == "Tresor") {
							qte += deckEnMain.getCartes().at(i).getValeur();
						}
					}
						setQteMonnaie(qte);
					//setQteMonnaie(getQteMonnaie() + nbdeLaFonction);
					setNbAchat(1);
					setNbAction(1);
					deckDefausse.ajouterCarte(cartesActionEnMain.at(i));
					deckEnMain.supprimerCarte(cartesActionEnMain.at(i));
					extraCoins = nbdeLaFonction;
					std::cout << "nouvelle quantite de monnaies du joueur: " << getQteMonnaie()+extraCoins << "\n";
					std::cout << "Updated decks: \n";
					printDecks();
				}

				// pour l'action +1 achat
				// acheter une carte supp lors de l'achat
				if (cartesActionEnMain.at(i).getFonctions().at(j)->getActe() == "Achat") {
					setNbAchat(getNbAchat() + 1);
					deckDefausse.ajouterCarte(cartesActionEnMain.at(i));
					deckEnMain.supprimerCarte(cartesActionEnMain.at(i));
					std::cout << "Joueur aura le droit d'acheter une caret supp lors de la phase d'achat\n";
					std::cout << "Updated decks: \n";
					printDecks();
					break;
				}

				// pour l'action defausser
					// setNbAction(1);
					// setNbAchat(1);

				// pour l'action ecarter
					// setNbAction(1);
					// setNbAchat(1);

				// pour l'action recevoir
					// setNbAction(1);
					// setNbAchat(1);

				// pour l'action devoiler
					// setNbAction(1);
					// setNbAchat(1);

				// pour l'action mettre de cote
					// setNbAction(1);
					// setNbAchat(1);
			}
			index++;
		}
		//cartesActionEnMain[0]->executerFonctions();
	}
}

Deck Joueur::jouerPhaseAchat(Deck deckSupply, std::vector<Carte> cartesTresorEnMain) {
	//std::vector<Carte> nouvellesCartes = {};
	int index = 0;
	int valeurTotal = getQteMonnaie();
    int achatfait = 0;
	int boundForRemovingCartesTresor = 0;
 
	while (index < getNbAchat()) {
		std::cout << "debut de la phase d'achat n" << index << " sur " << getNbAchat() << " achats permis\n";
		//for (int i = 0; i < cartesTresorEnMain.size(); i++) {
		//	valeurTotal += cartesTresorEnMain.at(i).getValeur();
		//}
		int boundDeckSupply = deckSupply.getCartes().size();
		for (int i = 0; i < boundDeckSupply; i++) {
			// pour ne pas acheter cuivre toujours (c'est gratuit), on cherche une carte de cout>=2
			if (deckSupply.getCartes().at(i).getCout() <= valeurTotal && valeurTotal >= 2 && deckSupply.getCartes().at(i).getCout() >= 2) {
				std::cout << "autre que le cuivre, le joueur peut acheter la carte: ";
				deckSupply.getCartes().at(i).print();
				// ajouter la carte a la deck en main
				deckEnMain.ajouterCarte(deckSupply.getCartes().at(i));
				// enlever les cartes utilisees pour effectuer l'achat
				
				// ici on est oblige de loop through nb de cartes tresors car il se peut qu'on a obtenue +x coins avant
				// d'apres les actions, et ils ne demandent pas de prendre des cartes tresor, seulement ajouter le nb de coins
				// donc on peut acheter la carte mais coe ettant avoir x coins invisibles
				int n = deckSupply.getCartes().at(i).getCout() - cartesTresorEnMain.size();
				// n represente aussi combien le joueur a pris des extra coins
				extraCoins -= n;
				setExtraCoins(extraCoins);
				if (n < 0) {
					boundForRemovingCartesTresor = deckSupply.getCartes().at(i).getCout();
				}
				else {
					boundForRemovingCartesTresor = cartesTresorEnMain.size();
				}
				for (int i=0; i< boundForRemovingCartesTresor;i++) {
					deckEnMain.supprimerCarte(cartesTresorEnMain.at(i));
					deckDefausse.ajouterCarte(cartesTresorEnMain.at(i));
				}
				std::cout << "Updated decks: \n";
				printDecks();
				//nouvellesCartes.insert(nouvellesCartes.begin(), deckSupply.getCartes().at(i));
 
				// modifier la valeur total for future uses (si c possible de faire plusieurs achats)
				valeurTotal -= deckSupply.getCartes().at(i).getCout();
				deckSupply.supprimerCarte(deckSupply.getCartes().at(i));

				//deckCartesSupprimees.ajouterCarte(deckSupply.getCartes().at(i));
				//for (int i = 0; i < boundDeckSupply; i++) {
				//	deckSupply.supprimerCarte(deckSupply.getCartes().at(0));
				//}
				achatfait++;

				std::cout << "fin de l'achat. Quantite de monnaie restante est: " << valeurTotal<<"\n";
				break;
			}
		}

		//si on n'a pas d'argent=on a achete rien ->on prend un cuivre ou autre carte gratuite
		if (achatfait == index) {
			std::cout << "joueur n'as pas de monnaie suffisant donc il peut prendre une carte cuivre ou une carte gratuite\n";
			for (int i = 0; i < deckSupply.getCartes().size(); i++)
			{
				if (deckSupply.getCartes().at(i).getCout() <= valeurTotal) {
					if (deckSupply.getCartes().at(i).getNom() == "Cuivre") {

						// ajouter la carte a la deck en main
						deckEnMain.ajouterCarte(deckSupply.getCartes().at(i));
						//nouvellesCartes.insert(nouvellesCartes.begin(), deckSupply.getCartes().at(i));

					// modifier la valeur total for future uses (si c possible de faire plusieurs achats)
						valeurTotal -= deckSupply.getCartes().at(i).getCout();

						// enlever la carte de deck supply
						deckSupply.supprimerCarte(deckSupply.getCartes().at(0));
						//deckCartesSupprimees.ajouterCarte(deckSupply.getCartes().at(i));
						//for (int i = 0; i < boundDeckSupply; i++) {
						//	deckSupply.supprimerCarte(deckSupply.getCartes().at(0));
						//}
						achatfait++;
					}

				}
			}
			std::cout << "Updated decks: \n";
			printDecks();
			std::cout << "fin de l'achat. Quantite de monnaie restante est: " << valeurTotal;
		}
		index += achatfait;

	}
	setQteMonnaie(valeurTotal);
	return deckSupply;
	//return nouvellesCartes;
}

void Joueur::jouerPhaseAjustement() {
	std::cout << "debut de phase ajustement\n";
	std::cout << "le joueur assemmble toutes les cartes en main et le remet dans la defausse\n";
	std::vector<Carte> listeDeCartes;
	std::vector<Carte> resteDeCartes;
	std::vector<Carte> emptyVector;
	int difference = 5 - deckAPart.getNbCartes();
	// assemblage de toutes le cartes en main dans la defausse
	
	//std::vector<Carte> cartesAjoutees = piocherDeDeckD(deckEnMain, deckEnMain.getNbCartes());
	//ajouterADeckD(deckDefausse, cartesAjoutees);
	int boundAssemblage = deckEnMain.getCartes().size();
	for (int i=0; i< boundAssemblage;i++) {
		deckDefausse.ajouterCarte(deckEnMain.getCartes().at(i));
	}
	for (int i = 0; i < boundAssemblage; i++) {
		deckEnMain.supprimerCarte(deckEnMain.getCartes().at(0));
	}
	//deckEnMain.setNbCartes(0);
	//deckEnMain.setCartes(emptyVector);
	//deckEnMain.getCartes().clear();

	std::cout << "Updated decks: \n";
	printDecks();

	// piocher 5 cartes et les mettre dans deck en main si suffisant
	std::cout << "On pioche 5 cartes et le mettre en main.\n";
	int boundDeckAPart = deckAPart.getCartes().size();
	if (boundDeckAPart >= 5) {
		std::cout << "la deck a part est suffisante pour piocher 5 cartes.\n";
		for (int i = 0; i < 5; i++) {
			deckEnMain.ajouterCarte(deckAPart.getCartes().at(i));
		}
		for (int i = 0; i < 5; i++) {
			deckAPart.supprimerCarte(deckAPart.getCartes().at(0));
		}

		//ajouterADeckD(deckEnMain, listeDeCartes);
		std::cout << "Updated decks: \n";
		printDecks();
	}
	// si pas suffisant 
	else {
		std::cout << "la deck a part n'est pas suffisante pour piocher 5 cartes.\n";
		std::cout << "Donc on pioche autant.\n";
		// piocher autant
		int boundDeckAPart = deckAPart.getCartes().size();
		for (int i = 0; i < boundDeckAPart; i++) {
			deckEnMain.ajouterCarte(deckAPart.getCartes().at(i));
		}
		for (int i = 0; i < boundDeckAPart; i++) {
			deckAPart.supprimerCarte(deckAPart.getCartes().at(0));
		}
		//deckAPart.getCartes().clear();

		//ajouterADeckD(deckEnMain, listeDeCartes);

		// shuffle defausse
		std::cout << "on shuffle la defausse.\n";
		deckDefausse.shuffle(deckDefausse.getNbCartes());

		// piocher le reste de la defausse
		//deplacer dans resteDeCartes combien des cartes on a encore besoin dans la main du deckDefausse
		std::cout << "on pioche le reste de la defausse.\n";
		for (int i = 0; i < difference; i++) {
			deckEnMain.ajouterCarte(deckDefausse.getCartes().at(i));
		}
		for (int i = 0; i < difference; i++) {
			deckDefausse.supprimerCarte(deckDefausse.getCartes().at(0));
		}

		std::cout << "Updated decks: \n";
		printDecks();
		//ajouterADeckD(deckEnMain, resteDeCartes);
	}

	// tour d'un autre joueur
}

std::vector<Carte> Joueur::carteActionAJouer(){
	int qtte = 0;
	std::vector<Carte> cartesActionEnMain;
	for (int i = 0; i < deckEnMain.getNbCartes(); i++) {
		if (deckEnMain.getCartes().at(i).getType() == "Tresor") {
			qtte += deckEnMain.getCartes().at(i).getValeur();
		}
		setQteMonnaie(qtte);
		// phase 1: action
		if (deckEnMain.getCartes().at(i).getType() == "Action") {
			cartesActionEnMain.push_back(deckEnMain.getCartes().at(i));
		}
	}
	return cartesActionEnMain;
}

Deck* Joueur::jouerTour(Deck deckSupply) {
	int count = 0;
	bool carteActionExiste = false;
	bool carteTresorExiste = false;
	bool unlockAjustement = false;
	Deck updatedDeck;
	int qtte = 0;

	std::vector<Carte> cartesTresorEnMain;
	std::vector<Carte> cartesActionEnMain;

	for (int i = 0; i < deckEnMain.getNbCartes(); i++) {
		if (deckEnMain.getCartes().at(i).getType() == "Tresor") {
			qtte += deckEnMain.getCartes().at(i).getValeur();
			//qteMonnaie = getQteMonnaie() + deckEnMain.getCartes().at(i).getValeur();
		}
		setQteMonnaie(qtte);
		// phase 1: action
		if (deckEnMain.getCartes().at(i).getType() == "Action") {
			cartesActionEnMain.push_back(deckEnMain.getCartes().at(i));
			carteActionExiste = true;
			count++;
		}

		// phase 2: achat
		if (deckEnMain.getCartes().at(i).getType() == "Tresor") {
			cartesTresorEnMain.push_back(deckEnMain.getCartes().at(i));
			carteTresorExiste = true;
			count++;
		}
	}
	qteMonnaie = qtte + extraCoins;

	//std::vector<Carte> cartesActionAJouer = carteActionAJouer();
	//while (cartesActionAJouer.size() > 0) {
	//	jouerPhaseAction(cartesActionEnMain);
	//	cartesActionAJouer = carteActionAJouer();
	//}
	if (carteActionExiste) {
		carteTresorExiste = false;
		// si apres piochant le joueur rencontre une nouvelle carte action
		jouerTour(deckSupply);
	}

	if (carteTresorExiste) {
		updatedDeck = jouerPhaseAchat(deckSupply, cartesTresorEnMain);
		unlockAjustement = true;
	}

	// phase 3: ajustement
	if (unlockAjustement) {
		jouerPhaseAjustement();
		unlockAjustement = false;
	}
	return &updatedDeck;
}

//void Joueur::jouerTour2(Deck deckSupply) {
//	int count = 0;
//	bool carteActionExiste = false;
//	bool carteTresorExiste = false;
//	std::vector<Carte> cartesTresorAJouer;
//	std::vector<Carte> cartesActionAJouer;
//	for (int i = 0; i < deckEnMain.getNbCartes(); i++) {
//
//		std::cout << "Carte piochee: " << i + 1 << " est de type " << deckEnMain.getCartes().at(i).getType() << "\n";
//		// phase 1: action
//		if (deckEnMain.getCartes().at(i).getType() == "Action") {
//			cartesActionAJouer.push_back(deckEnMain.getCartes().at(i));
//			carteActionExiste = true;
//			count++;
//		}
//
//		// phase 2: achat
//		if (deckEnMain.getCartes().at(i).getType() == "Tresor") {
//			cartesTresorAJouer.push_back(deckEnMain.getCartes().at(i));
//			carteTresorExiste = true;
//			count++;
//		}
//
//	}
//	
//
//	jouerCartes(cartesActionAJouer, cartesTresorAJouer, deckSupply);
//
//
//
//
//	//if (carteActionExiste) {
//	//	jouerPhaseAction(cartesActionAJouer);
//	//	// si apres piochant le joueur rencontre une nouvelle carte action
//	//	jouerTour(deckSupply);
//	//}
//
//	//if (carteTresorExiste) {
//	//	jouerPhaseAchat(deckSupply, cartesTresorAJouer);
//	//	// si apres piochant le joueur rencontre une nouvelle carte tresor
//	//	jouerTour(deckSupply);
//	//}
//	//// phase 3: ajustement
//	//jouerPhaseAjustement();
//}

//void Joueur::jouerCartes(std::vector<Carte> cartesAction, std::vector<Carte> cartesTresor, Deck deckSupply) {
//	std::vector<Carte> nouvellesCartesAchetees;
//	std::vector<Carte> nouvellesCartesAction;
//	if (cartesAction.size() > 0) {
//		 jouerPhaseAction(cartesAction);
//	}
//	if (cartesTresor.size() > 0) {
//		nouvellesCartesAchetees = jouerPhaseAchat(deckSupply, cartesTresor);
//	}
//	if (nouvellesCartesAchetees.size() > 0 || nouvellesCartesAction.size() > 0) {
//		jouerCartes(nouvellesCartesAction, nouvellesCartesAchetees, deckSupply);
//	}
//}

int Joueur::collecterPointsVictoire() {
	// merge deck en main with deck a part with deck de defausse
	Deck nouvelleDeckInitiale;
	int boundEnMain = deckEnMain.getCartes().size();
	int boundAPart = deckAPart.getCartes().size();
	int boundDefausse = deckDefausse.getCartes().size();

	std::cout << "calcul des point de victoire du joueur" << getId() << "\n";
	std::cout << "toutes les decks se melangent ensemble\n";
	if (boundEnMain != 0) {
		for (int i = 0; i < boundEnMain; i++) {
			nouvelleDeckInitiale.ajouterCarte(deckEnMain.getCartes().at(i));
		}
		for (int i = 0; i < boundEnMain; i++) {
			deckEnMain.supprimerCarte(deckEnMain.getCartes().at(0));
		}
	}
	if (boundAPart) {
		for (int i = 0; i < boundAPart; i++) {
			nouvelleDeckInitiale.ajouterCarte(deckAPart.getCartes().at(i));
		}
		for (int i = 0; i < boundAPart; i++) {
			deckAPart.supprimerCarte(deckAPart.getCartes().at(0));
		}
	}
	if (boundDefausse) {
		for (int i = 0; i < boundDefausse; i++) {
			nouvelleDeckInitiale.ajouterCarte(deckDefausse.getCartes().at(i));
		}
		for (int i = 0; i < boundDefausse; i++) {
			deckDefausse.supprimerCarte(deckDefausse.getCartes().at(0));
		}
	}
	std::cout << "Updated decks: \n";
	printEndDeck(nouvelleDeckInitiale,nouvelleDeckInitiale.getCartes().size());
	// iterate through cartes victoire
	int nbTotalPointsVictoire = 0;
	for (int i = 0; i < nouvelleDeckInitiale.getCartes().size(); i++) {
		if (nouvelleDeckInitiale.getCartes().at(i).getType() == "Victoire") {
			nbTotalPointsVictoire += nouvelleDeckInitiale.getCartes().at(i).getValeur();
		}
	}
	std::cout << "nb de victoire du joueur est: " << nbTotalPointsVictoire <<"\n";
	// save nb
	return nbTotalPointsVictoire;
}
