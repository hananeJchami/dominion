// dominion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Deck.h"
#include "Joueur.h"
#include "Action.h"

int main()
{
    Fonction* fonction1 = new Fonction(1,"cartes");
    Fonction *fonctions[1] = { fonction1 };

    Fonction* fonction2 = new Fonction(1, "cartes");

    Action* carteAction1 = new Action(1, "Forgeron", 3, "Action", *fonctions);
    Carte* carte2 = new Carte(2, "Marché", 5, "Tresor");
    Carte* carte3 = new Carte(3, "Village", 2, "Victoire");
    Action* carteAction2 = new Action(4, "bucheron", 1, "Action", *fonctions);
    Carte* carte5 = new Carte(5, "shi", 2,"Victoire");
    Carte cartes[5] = { *carteAction1,*carte2,*carte3, *carteAction2, *carte5 };

    Deck* deck1 = new Deck(5, cartes);

    Joueur* joueur1 = new Joueur(*deck1);
    joueur1->diviserLesCartes();
    joueur1->print();
    joueur1->jouerTour();

    std::cout << "Hello World!\n";
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
