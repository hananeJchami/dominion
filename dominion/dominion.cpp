// dominion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Deck.h"
#include "Joueur.h"
#include "Action.h"
#include<vector>
#include "Victoire.h"
#include "Malediction.h"
#include <set>

void trouverGagnant(Joueur j1, Joueur j2)
{
    if (j1.collecterPointsVictoire() > j2.collecterPointsVictoire())
    {
        std::cout << "Le joueur1 a gagne :)";
    }
    else if (j1.collecterPointsVictoire() < j2.collecterPointsVictoire())
    {
        std::cout << "Le joueur2 a gagne :)";
    }
    else
    {
        std::cout << "c'est egalite";
    }
}

bool isProvinceVide(Deck deckSupply) {
    for (int i = 0; i < deckSupply.getCartes().size(); i++) {
        if (deckSupply.getCartes().at(i).getNom() == "Province") {
            return false;
        }
    }
    return true;
}

int nbPiles(Deck deck) {
    std::set<std::string> piles;
    for (int i = 0; i < deck.getCartes().size(); i++) {
        piles.insert(deck.getCartes().at(i).getNom());
    }
    return piles.size();

}
int main()
{
    // empty vector fonctions
    std::vector<Fonction*> emptyFonctions;


    // test Hanane
    //Fonction* fonction2CartesH = new Fonction(2, "Carte(s)");
    //Fonction* fonction2PiecesH = new Fonction(2, "Coin(s)");
    //std::vector<Fonction*> abilitiesBucheronH = { fonction2CartesH };
    //std::vector<Fonction*> abilitiesRoyaumeForgeron1 = {fonction2PiecesH };

    //Royaume* royaumeBucheron1H = new Royaume(55, "Bucheron", 3, "Action", abilitiesBucheronH, NULL);
    //Royaume* royaumeBucheron2H = new Royaume(56, "Forgeron", 4, "Action", abilitiesRoyaumeForgeron1, NULL);
    //Royaume* royaumeBucheron3H = new Royaume(57, "Bucheron", 3, "Action", abilitiesBucheronH, NULL);
    

    //les cartes initiales du premier joueur:
    Tresor* ctresor1 = new Tresor(1, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor2 = new Tresor(2, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor3 = new Tresor(3, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor4 = new Tresor(4, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor5 = new Tresor(5, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor6 = new Tresor(6, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor7 = new Tresor(7, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Victoire* v1 = new Victoire(8, "Domaine", 2, "Victoire", emptyFonctions, 1);
    Victoire* v2 = new Victoire(9, "Domaine", 2, "Victoire", emptyFonctions, 1);
    Victoire* v3 = new Victoire(10, "Domaine", 2, "Victoire", emptyFonctions, 1);
    std::vector<Carte> cartes1 = { *ctresor1,*ctresor2,*ctresor3,*ctresor4,*ctresor5,*ctresor6,*ctresor7,
                                *v1,*v2,*v3 };
    Deck* deck1 = new Deck(10, cartes1);


    //les cartes initiales du second joueur:
    Tresor* ctresor8 = new Tresor(8, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor9 = new Tresor(9, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor10 = new Tresor(10, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor11 = new Tresor(11, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor12 = new Tresor(12, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor13 = new Tresor(13, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor14 = new Tresor(14, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Victoire* v4 = new Victoire(15, "Domaine", 2, "Victoire", emptyFonctions, 1);
    Victoire* v5 = new Victoire(16, "Domaine", 2, "Victoire", emptyFonctions, 1);
    Victoire* v6 = new Victoire(17, "Domaine", 2, "Victoire", emptyFonctions, 1);
    std::vector<Carte> cartes2 = { *ctresor8,*ctresor9,*ctresor10,*ctresor11,*ctresor12,*ctresor13,*ctresor14,
                                *v4,*v5,*v6 };
    Deck* deck2 = new Deck(10, cartes2);


    //on construit les cartes pour decksupply: (the next 100000 lines could be a function builddecksupply)
    //Cartes Victoires: Domaine, Duche, Province (pour 2 joueurs->8 cartes victoire de chaque type)
    Victoire* vicdomaine1 = new Victoire(1, "Domaine", 2, "Victoire", emptyFonctions, 1);
    Victoire* vicdomaine2 = new Victoire(2, "Domaine", 2, "Victoire", emptyFonctions, 1);
    Victoire* vicdomaine3 = new Victoire(3, "Domaine", 2, "Victoire", emptyFonctions, 1);
    Victoire* vicdomaine4 = new Victoire(4, "Domaine", 2, "Victoire", emptyFonctions, 1);
    Victoire* vicdomaine5 = new Victoire(5, "Domaine", 2, "Victoire", emptyFonctions, 1);
    Victoire* vicdomaine6 = new Victoire(6, "Domaine", 2, "Victoire", emptyFonctions, 1);
    Victoire* vicdomaine7 = new Victoire(7, "Domaine", 2, "Victoire", emptyFonctions, 1);
    Victoire* vicdomaine8 = new Victoire(8, "Domaine", 2, "Victoire", emptyFonctions, 1);
    int nbCartesVictoireDomaine = 8;

    Victoire* vicduche1 = new Victoire(9, "Duche", 5, "Victoire", emptyFonctions, 3);
    Victoire* vicduche2 = new Victoire(10, "Duche", 5, "Victoire", emptyFonctions, 3);
    Victoire* vicduche3 = new Victoire(11, "Duche", 5, "Victoire", emptyFonctions, 3);
    Victoire* vicduche4 = new Victoire(12, "Duche", 5, "Victoire", emptyFonctions, 3);
    Victoire* vicduche5 = new Victoire(13, "Duche", 5, "Victoire", emptyFonctions, 3);
    Victoire* vicduche6 = new Victoire(14, "Duche", 5, "Victoire", emptyFonctions, 3);
    Victoire* vicduche7 = new Victoire(15, "Duche", 5, "Victoire", emptyFonctions, 3);
    Victoire* vicduche8 = new Victoire(16, "Duche", 5, "Victoire", emptyFonctions, 3);
    int nbCartesVictoireDuche = 8;

    Victoire* vicprovince1 = new Victoire(17, "Province", 8, "Victoire", emptyFonctions, 6);
    Victoire* vicprovince2 = new Victoire(18, "Province", 8, "Victoire", emptyFonctions, 6);
    Victoire* vicprovince3 = new Victoire(19, "Province", 8, "Victoire", emptyFonctions, 6);
    Victoire* vicprovince4 = new Victoire(20, "Province", 8, "Victoire", emptyFonctions, 6);
    Victoire* vicprovince5 = new Victoire(21, "Province", 8, "Victoire", emptyFonctions, 6);
    Victoire* vicprovince6 = new Victoire(22, "Province", 8, "Victoire", emptyFonctions, 6);
    Victoire* vicprovince7 = new Victoire(23, "Province", 8, "Victoire", emptyFonctions, 6);
    Victoire* vicprovince8 = new Victoire(24, "Province", 8, "Victoire", emptyFonctions, 6);
    int nbCartesVictoireProvence = 8;

    //Cartes Malediction: 10 cartes pour 2 joueurs
    Malediction* mal1 = new Malediction(25, "Malediction", 0, "Malediction" , emptyFonctions, NULL);
    Malediction* mal2 = new Malediction(26, "Malediction", 0, "Malediction" , emptyFonctions, NULL);
    Malediction* mal3 = new Malediction(27, "Malediction", 0, "Malediction" , emptyFonctions, NULL);
    Malediction* mal4 = new Malediction(28, "Malediction", 0, "Malediction" , emptyFonctions, NULL);
    Malediction* mal5 = new Malediction(29, "Malediction", 0, "Malediction" , emptyFonctions, NULL);
    Malediction* mal6 = new Malediction(30, "Malediction", 0, "Malediction" , emptyFonctions, NULL);
    Malediction* mal7 = new Malediction(31, "Malediction", 0, "Malediction" , emptyFonctions, NULL);
    Malediction* mal8 = new Malediction(32, "Malediction", 0, "Malediction" , emptyFonctions, NULL);
    Malediction* mal9 = new Malediction(33, "Malediction", 0, "Malediction" , emptyFonctions, NULL);
    Malediction* mal10 = new Malediction(34, "Malediction", 0, "Malediction", emptyFonctions, NULL);
    int nbCartesMalediction = 10;


    //Marche:+1 Carte,+1 Action,+1Achat,+1 Piece(donne une piece supplementaire utilisable dans la phase achat)
    Fonction* fonction1Carte = new Fonction(1, "Carte(s)");
    Fonction* fonction1Action = new Fonction(1, "Action(s)");
    Fonction* fonction1Achat = new Fonction(1, "Achat(s)");
    Fonction* fonction1Piece = new Fonction(1, "Piece(s)");
    std::vector<Fonction*> abilitiesMarche = { fonction1Carte,fonction1Action,fonction1Achat,fonction1Piece };

    Royaume* royaumeMarche1 = new Royaume(35, "Marche", 5, "Action", abilitiesMarche, NULL);
    Royaume* royaumeMarche2 = new Royaume(36, "Marche", 5, "Action", abilitiesMarche, NULL);
    Royaume* royaumeMarche3 = new Royaume(37, "Marche", 5, "Action", abilitiesMarche, NULL);
    Royaume* royaumeMarche4 = new Royaume(38, "Marche", 5, "Action", abilitiesMarche, NULL);
    Royaume* royaumeMarche5 = new Royaume(39, "Marche", 5, "Action", abilitiesMarche, NULL);
    Royaume* royaumeMarche6 = new Royaume(40, "Marche", 5, "Action", abilitiesMarche, NULL);
    Royaume* royaumeMarche7 = new Royaume(41, "Marche", 5, "Action", abilitiesMarche, NULL);
    Royaume* royaumeMarche8 = new Royaume(42, "Marche", 5, "Action", abilitiesMarche, NULL);
    Royaume* royaumeMarche9 = new Royaume(43, "Marche", 5, "Action", abilitiesMarche, NULL);
    Royaume* royaumeMarche10 = new Royaume(44, "Marche", 5, "Action", abilitiesMarche, NULL);
    int nbCartesRoyaumeMarche = 10;

    //Village: +1Carte,+1Action
    std::vector<Fonction*> abilitiesVillage = { fonction1Carte,fonction1Action };
    Royaume* royaumeVillage1 = new Royaume(45, "Village", 3, "Action", abilitiesVillage, NULL);
    Royaume* royaumeVillage2 = new Royaume(46, "Village", 3, "Action", abilitiesVillage, NULL);
    Royaume* royaumeVillage3 = new Royaume(47, "Village", 3, "Action", abilitiesVillage, NULL);
    Royaume* royaumeVillage4 = new Royaume(48, "Village", 3, "Action", abilitiesVillage, NULL);
    Royaume* royaumeVillage5 = new Royaume(49, "Village", 3, "Action", abilitiesVillage, NULL);
    Royaume* royaumeVillage6 = new Royaume(50, "Village", 3, "Action", abilitiesVillage, NULL);
    Royaume* royaumeVillage7 = new Royaume(51, "Village", 3, "Action", abilitiesVillage, NULL);
    Royaume* royaumeVillage8 = new Royaume(52, "Village", 3, "Action", abilitiesVillage, NULL);
    Royaume* royaumeVillage9 = new Royaume(53, "Village", 3, "Action", abilitiesVillage, NULL);
    Royaume* royaumeVillage10 = new Royaume(54, "Village", 3, "Action", abilitiesVillage, NULL);
    int nbCartesRoyaumeVillage = 10;

    //Bucheron: +1Achat,+2 Pieces
    Fonction* fonction2Pieces = new Fonction(2, "Piece(s)");
    std::vector<Fonction*> abilitiesBucheron = { fonction1Achat,fonction2Pieces };
    Royaume* royaumeBucheron1 = new Royaume(55, "Bucheron", 3, "Action", abilitiesBucheron, NULL);
    Royaume* royaumeBucheron2 = new Royaume(56, "Bucheron", 3, "Action", abilitiesBucheron, NULL);
    Royaume* royaumeBucheron3 = new Royaume(57, "Bucheron", 3, "Action", abilitiesBucheron, NULL);
    Royaume* royaumeBucheron4 = new Royaume(58, "Bucheron", 3, "Action", abilitiesBucheron, NULL);
    Royaume* royaumeBucheron5 = new Royaume(59, "Bucheron", 3, "Action", abilitiesBucheron, NULL);
    Royaume* royaumeBucheron6 = new Royaume(60, "Bucheron", 3, "Action", abilitiesBucheron, NULL);
    Royaume* royaumeBucheron7 = new Royaume(61, "Bucheron", 3, "Action", abilitiesBucheron, NULL);
    Royaume* royaumeBucheron8 = new Royaume(62, "Bucheron", 3, "Action", abilitiesBucheron, NULL);
    Royaume* royaumeBucheron9 = new Royaume(63, "Bucheron", 3, "Action", abilitiesBucheron, NULL);
    Royaume* royaumeBucheron10 = new Royaume(64, "Bucheron", 3, "Action", abilitiesBucheron, NULL);
    int nbCartesRoyaumeBucheron = 10;

    //Cave: +1Action, +Discard any number of cards, than draw that many (?)
    std::vector<Fonction*> abilitiesCave = { fonction1Action };
    Royaume* royaumeCave1 = new Royaume(65, "Cave", 2, "Action", abilitiesCave, NULL);
    Royaume* royaumeCave2 = new Royaume(66, "Cave", 2, "Action", abilitiesCave, NULL);
    Royaume* royaumeCave3 = new Royaume(67, "Cave", 2, "Action", abilitiesCave, NULL);
    Royaume* royaumeCave4 = new Royaume(68, "Cave", 2, "Action", abilitiesCave, NULL);
    Royaume* royaumeCave5 = new Royaume(69, "Cave", 2, "Action", abilitiesCave, NULL);
    Royaume* royaumeCave6 = new Royaume(70, "Cave", 2, "Action", abilitiesCave, NULL);
    Royaume* royaumeCave7 = new Royaume(71, "Cave", 2, "Action", abilitiesCave, NULL);
    Royaume* royaumeCave8 = new Royaume(72, "Cave", 2, "Action", abilitiesCave, NULL);
    Royaume* royaumeCave9 = new Royaume(73, "Cave", 2, "Action", abilitiesCave, NULL);
    Royaume* royaumeCave10 = new Royaume(74, "Cave", 2, "Action", abilitiesCave, NULL);
    int nbCartesRoyaumeCave = 10;

    //Forgeron: +3 Cartes
    Fonction* fonctionTroisCartes = new Fonction(3, "Carte(s)");
    std::vector<Fonction*> abilitiesForgeron = { fonctionTroisCartes };
    Royaume* royaumeForgeron1 = new Royaume(75, "Forgeron", 4, "Action", abilitiesForgeron, NULL);
    Royaume* royaumeForgeron2 = new Royaume(76, "Forgeron", 4, "Action", abilitiesForgeron, NULL);
    Royaume* royaumeForgeron3 = new Royaume(77, "Forgeron", 4, "Action", abilitiesForgeron, NULL);
    Royaume* royaumeForgeron4 = new Royaume(78, "Forgeron", 4, "Action", abilitiesForgeron, NULL);
    Royaume* royaumeForgeron5 = new Royaume(79, "Forgeron", 4, "Action", abilitiesForgeron, NULL);
    Royaume* royaumeForgeron6 = new Royaume(80, "Forgeron", 4, "Action", abilitiesForgeron, NULL);
    Royaume* royaumeForgeron7 = new Royaume(81, "Forgeron", 4, "Action", abilitiesForgeron, NULL);
    Royaume* royaumeForgeron8 = new Royaume(82, "Forgeron", 4, "Action", abilitiesForgeron, NULL);
    Royaume* royaumeForgeron9 = new Royaume(83, "Forgeron", 4, "Action", abilitiesForgeron, NULL);
    Royaume* royaumeForgeron10 = new Royaume(84, "Forgeron", 4, "Action", abilitiesForgeron, NULL);
    int nbCartesRoyaumeForgeron = 10;

    // I swapped 1st carte with last card
    std::vector<Carte> cartesSupply = { *vicdomaine1, *vicdomaine2,*vicdomaine3,*vicdomaine4,*vicdomaine5,
        *vicdomaine6,*vicdomaine7,*vicdomaine8,*vicduche1,*vicduche2,*vicduche3,*vicduche4,*vicduche5,
        *vicduche6,*vicduche7,*vicduche8,*vicprovince1,*vicprovince2,*vicprovince3,*vicprovince4,
        *vicprovince5,*vicprovince6,*vicprovince7,*vicprovince8,*mal1,*mal2,*mal3,*mal4,*mal5,
        *mal6,*mal7,*mal8,*mal9,*mal10,*royaumeMarche1,*royaumeMarche2,*royaumeMarche3,
        *royaumeMarche4,*royaumeMarche5,*royaumeMarche6,*royaumeMarche7,*royaumeMarche8,
        *royaumeMarche9,*royaumeMarche10,*royaumeVillage1,*royaumeVillage2,*royaumeVillage3,
        *royaumeVillage4,*royaumeVillage5,*royaumeVillage6,*royaumeVillage7,*royaumeVillage8,
        *royaumeVillage9,*royaumeVillage10,*royaumeBucheron1,*royaumeBucheron2,*royaumeBucheron3,
        *royaumeBucheron4,*royaumeBucheron5,*royaumeBucheron6,*royaumeBucheron7,*royaumeBucheron8,
        *royaumeBucheron9,*royaumeBucheron10,*royaumeCave1,*royaumeCave2,*royaumeCave3,*royaumeCave4,
        *royaumeCave5,*royaumeCave6,*royaumeCave7,*royaumeCave8,*royaumeCave9,*royaumeCave10,
        *royaumeForgeron1,*royaumeForgeron2,*royaumeForgeron3,*royaumeForgeron4,*royaumeForgeron5,
        *royaumeForgeron6,*royaumeForgeron7,*royaumeForgeron8,*royaumeForgeron9,*royaumeForgeron10 };
    
    Deck* deckSupply = new Deck(cartesSupply.size(), cartesSupply);
    //int nbPilesInitial = nbPiles(*deckSupply);

    // Smaller deck test
    Tresor* ctresor20 = new Tresor(20, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor21 = new Tresor(21, "Cuivre", 0, "Tresor", emptyFonctions, 1);
    Tresor* ctresor22 = new Tresor(22, "Cuivre", 0, "Tresor", emptyFonctions, 1);

    std::vector<Carte> cartesSupplyTest = { *royaumeForgeron1,*royaumeForgeron2,*royaumeForgeron3 ,
                                            *vicduche1, *vicduche2, *vicduche3, 
                                            *royaumeVillage1,*royaumeVillage2,*royaumeVillage3,
                                            *vicprovince1, *vicprovince2, *vicprovince3, 
                                            * mal1,* mal2,* mal3,
                                            *ctresor20, *ctresor21, *ctresor22
 };

    Deck* deckSupplyTest = new Deck(cartesSupplyTest.size(), cartesSupplyTest);

    std::vector<Carte> cartesSupplyTestApresJeu1 = { *royaumeForgeron1,*royaumeForgeron2,*royaumeForgeron3 ,
                                                     *vicduche1, *vicduche2, *vicduche3, 
                                                     *vicprovince1, *vicprovince2, *vicprovince3 };

    Deck* deckSupplyTestApresJeu1 = new Deck(cartesSupplyTestApresJeu1.size(), cartesSupplyTestApresJeu1);

    std::vector<Carte> cartesSupplyTestApresJeu2 = { *vicduche1, *vicduche2, *vicduche3, *royaumeVillage1,*royaumeVillage2,*royaumeVillage3,
    *royaumeCave1,*royaumeCave2,*royaumeCave3,*royaumeCave4 };

    Deck* deckSupplyTestApresJeu2 = new Deck(cartesSupplyTestApresJeu2.size(), cartesSupplyTestApresJeu2);

    Deck* updatedDeck;                                          

    Joueur* joueur1 = new Joueur(1, *deck1);
    joueur1->diviserLesCartes();
    joueur1->printDecks();
    updatedDeck = joueur1->jouerTour(*deckSupply);
    std::cout << "**********************************************************\n";
    Joueur* joueur2 = new Joueur(2, *deck2);
    joueur2->diviserLesCartes();
    joueur2->printDecks();
    updatedDeck = joueur2->jouerTour(*deckSupply);
    //int nbPilesFinal = nbPiles(*updatedDeck);

    std::cout << "**********************************************************\n";
    std::cout << "nb de points de victoire du joueur1: \n";
    joueur1->collecterPointsVictoire();
    std::cout << "nb de points de victoire du joueur2: \n";
    joueur2->collecterPointsVictoire();
    std::cout << "**********************************************************\n";


    //le reste du code sera applique sur un autre deck de test plus petit juste pour
    // montrer la fonctionnalité des fonctions: si la fin de la partie est abouti

    int nbPilesInitial = nbPiles(*deckSupplyTest);
    int nbPilesFinal = nbPiles(*deckSupplyTestApresJeu1);
    int nbPilesFinal2 = nbPiles(*deckSupplyTestApresJeu2);

    std::cout << "le reste du code sera applique sur un autre deck de test plus petit juste pour";
    std::cout << "montrer la fonctionnalité des fonctions: si la fin de la partie est abouti\n\n";
    std::cout << "determiner fin de pile:\n";
    std::cout << "deck supply test: \n";
    deckSupplyTest->print();
    std::cout << "deck supply apres jeu exemple1: \n";
    deckSupplyTestApresJeu1->print();
    if (isProvinceVide(*deckSupplyTestApresJeu1)) {
        std::cout << "Pile province est vide. Fin de partie\n";
    }
    else if (nbPilesInitial - nbPilesFinal == 3) {
        std::cout << "3 piles de la reserve sont vides. Fin de partie\n";
    }

    std::cout << "deck supply apres jeu exemple2: \n";
    deckSupplyTestApresJeu2->print();
    if (isProvinceVide(*deckSupplyTestApresJeu2)) {
        std::cout << "Pile province est vide. Fin de partie\n";
    }
    else if (nbPilesInitial - nbPilesFinal2 == 3) {
        std::cout << "3 piles de la reserve sont vides. Fin de partie\n";
    }


    //std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
