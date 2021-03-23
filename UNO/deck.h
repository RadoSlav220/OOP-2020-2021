#pragma once
//#include "card.h"
#include "player.h"

class Deck {
private:
    Card prevCard; //default constructs a card

public:
    Deck();

public:
    Card getPrevCard() const;
    Card generateCard();
};