#pragma once
#include <string>
class Fonction
{
	int nb;
	std::string acte;
public:
	Fonction() = default;
	Fonction(int, std::string);
	~Fonction();

	int getNb();
	std::string getActe();

	void setNb(int);
	void setActe(std::string);
};

