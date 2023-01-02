#include <iostream>
#include <cstdlib>
#include "Deck.h"

Deck::Deck(int nbCards, Carte(&cards)[5])
    : nbCartes(nbCards) {
    for (int i = 0; i < nbCards; i++) {
        cartes[i] = cards[i];
    }
}

Deck::~Deck() {}

int Deck::getNbCartes() { return nbCartes; }
Carte* Deck::getCartes() { return cartes; }

void Deck::setNbCartes(int nb) { nbCartes = nb; }

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

