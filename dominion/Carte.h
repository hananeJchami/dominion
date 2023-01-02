#pragma once
#include <string>
#include "Fonction.h"
class Carte
{
	int id;
	std::string nom;
	int cout;
	std::string type;

public:
	Carte() = default;
	Carte(int, std::string, int, std::string);
	~Carte();

	int getId();
	std::string getNom();
	int getCout();
	std::string getType();

	void setId(int);
	void setNom(std::string);
	void setCout(int);
	void setType(std::string);

	void print();
	//virtual void executerFonctions(); // fi hal bado l joueur yelaab one of the fonctions li mawjoudin aal carte

};

