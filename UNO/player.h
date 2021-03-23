#pragma once
#include "card.h"

const unsigned short MAX_HAND = 10;

class Player{
private:
    Card hand[MAX_HAND];
    unsigned short curSize;

public:
    Player();

public:
    unsigned short getHandSize() const;
    Card getCard(const unsigned short cardNum) const;
    void drawCard(const Card& newCard);
    bool canPlayCard(unsigned short cardNum, const Card& prevCard);
    bool isAnyPlayable(const Card& prevCard);
    void printHand();
    bool isWinner();
    void discardCard(unsigned short cardNum);
};