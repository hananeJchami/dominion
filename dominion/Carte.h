#pragma once
#include <string>
#include "Fonction.h"
#include <vector>
#include <iostream>

class Carte
{
	int id;
	std::string nom;
	int cout;
	std::string type;
	std::vector<Fonction*> fonctions;
	int valeur;
	bool isAction;
	bool isVictoireOrTresor;


public:
	Carte() = default;
	Carte(int, std::string, int, std::string, std::vector<Fonction*>,int);
	~Carte();

	int getId();
	std::string getNom();
	int getCout();
	std::string getType();
	std::vector<Fonction*> getFonctions();
	int getValeur();
	bool getIsAction();
	bool getIsVictoireOrTresor();

	void setId(int);
	void setNom(std::string);
	void setCout(int);
	void setType(std::string);

	// Virtual bc only action has the right for abilities and Victoire et Tresor have the right for valeur
	virtual void setFonctions(std::vector<Fonction*>);
	virtual void setValeur(int);
	virtual void setIsAction(bool);
	virtual void setIsVictoireOrTresor(bool);

	void print();
	friend std::ostream& operator<<(std::ostream& os, const Carte& carte);


	bool operator ==(Carte carte) {
		return (this->getId() == carte.getId());
	}

};
