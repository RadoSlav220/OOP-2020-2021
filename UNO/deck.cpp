#include <iostream>
#include <ctime>
#include "deck.h"

//Constructor... Generates the first card
Deck::Deck()
{
    prevCard = generateCard();
}

Card Deck::getPrevCard() const {return prevCard;}

Card Deck::generateCard()
{
    Card newCard;
    newCard.setColor(static_cast<COLOR>(rand() % 5 + 1));
    if (newCard.getColor() == black){
        newCard.setNumber(0);
    }
    else {
        newCard.setNumber(rand() % 10 + 1);
    }
    return newCard;
}