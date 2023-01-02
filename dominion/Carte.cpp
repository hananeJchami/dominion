#include <iostream>
#include <cstdlib>
#include "Carte.h"

Carte::Carte (int idd, std::string name, int cost, std::string atype) 
	: id(idd), nom(name), cout(cost), type(atype){
}

Carte::~Carte(){}

int Carte::getId() { return id; }
std::string Carte::getNom() { return nom; }
int Carte::getCout() { return cout; }
std::string Carte::getType() { return type; }

void Carte::setId(int idd) { id = idd; }
void Carte::setNom(std::string name) { nom=name; }
void Carte::setCout(int cost) { cout = cost; }

void Carte::print() {
    std::cout << " Nom : " << nom << " Cout : " << cout;
}