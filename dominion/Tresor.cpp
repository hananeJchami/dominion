#include "Tresor.h"
#include <iostream>
#include <cstdlib>


//les cartes tresor n'ont aucune abilite et on met la valeur par defaut pour chaque type de carte:
Tresor::Tresor(int idd, std::string name, int cost, std::string aType, std::vector<Fonction*> abilities, int value)
	: Carte(idd, name, cost, aType, abilities,value) {
	setIsAction(false);
	setIsVictoireOrTresor(true);
	aType = "Tresor";
	if (name == "Cuivre") { value = 1;  }
	if (name == "Argent") { value = 2; }
	if (name == "Or") { value = 3; }

}

Tresor::~Tresor() {}