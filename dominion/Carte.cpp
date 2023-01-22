#include <iostream>
#include <cstdlib>
#include "Carte.h"
#include <iostream>

Carte::Carte (int idd, std::string name, int cost, std::string atype, std::vector<Fonction*> abilities, int value)
	: id(idd), nom(name), cout(cost), type(atype), fonctions(abilities), valeur(value){
	isAction = false;
}

Carte::~Carte(){}

int Carte::getId() { return id; }
std::string Carte::getNom() { return nom; }
int Carte::getCout() { return cout; }
std::string Carte::getType() { return type; }
bool Carte::getIsAction() { return isAction; }
std::vector<Fonction*> Carte::getFonctions() { return fonctions; }
int Carte::getValeur() { return valeur; }
bool Carte::getIsVictoireOrTresor() { return isVictoireOrTresor; }

void Carte::setId(int idd) { id = idd; }
void Carte::setNom(std::string name) { nom=name; }
void Carte::setCout(int cost) { cout = cost; }
void Carte::setIsAction(bool tof) { isAction = tof; }
void Carte::setFonctions(std::vector<Fonction*> abilities) {
	for (int i = 0; i < abilities.size(); i++) {
		fonctions.push_back(abilities.at(i));
	}
}
void Carte::setValeur(int value) { valeur = value; }
void Carte::setIsVictoireOrTresor(bool vot) { isVictoireOrTresor = vot; }


void Carte::print() {
    std::cout << "\nNom : " << nom << "\nCout : " << cout<<"\nType: "<<type<<"\n";
}

std::ostream& operator<<(std::ostream& os, const Carte& carte)
{
	os << carte.id << '|' << carte.nom << '|' << carte.type << "\n";
	return os;
}