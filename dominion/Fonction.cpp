#include "Fonction.h"
#include <iostream>
#include <cstdlib>


Fonction::Fonction(int nbFonction, std::string act)
	: nb(nbFonction), acte(act) {}

Fonction::~Fonction() {}

int Fonction::getNb() { return nb; }
std::string Fonction::getActe() { return acte; }

void Fonction::setNb(int nbFonction) { nb = nbFonction; }
void Fonction::setActe(std::string act) { acte = act; }