#include <iostream>
#include <cstdlib>
#include "Deck.h"

Deck::Deck(int nbCards, std::vector<Carte> cards)
    : nbCartes(nbCards){
    for (int i = 0; i < nbCards; i++) {
        cartes.push_back(cards.at(i));
    }
}

Deck::~Deck() {}

int Deck::getNbCartes() { return nbCartes; }
std::vector<Carte> Deck::getCartes() { return cartes; }

std::vector<Carte> Deck::resize(int bound) { cartes.resize(bound); 
return cartes;
}

int Deck::getNbDuMemeType() { return nbDuMemeType; }
//std::vector<Carte> getPileTypes() { return pileTypes; }

void Deck::setCartes(std::vector<Carte> cards) {
    for (int i = 0; i < cards.size(); i++) {
        cartes.push_back(cards.at(i));
        nbCartes++;
    }
}


void Deck::ajouterCarte(Carte carte) {
    cartes.insert(cartes.end(), carte);
    nbCartes++;
}
void Deck::supprimerCarte(Carte carte) {
    auto it = std::find(cartes.begin(), cartes.end(), carte);
    auto index = std::distance(cartes.begin(), it);

    cartes.erase(cartes.begin() + index);
    nbCartes--;
    
}
void Deck::setNbCartes(int nb) {
    nbCartes = nb; 
}

void Deck::shuffle(int nbCardsToShuffle) {

    // Initialize seed randomly
    srand(time(0));

    for (int i = 0; i < nbCartes; i++)
    {
        // Random for remaining positions.
        int r = i + (rand() % (nbCardsToShuffle - i));

        std::swap(cartes[i], cartes[r]);
    }
}
void Deck::print() {
    std::cout << " Deck\n";
    for (int i = 0; i < nbCartes; i++) {
        std::cout << this->getCartes().at(i);
    }
    std::cout << "\n";
}


