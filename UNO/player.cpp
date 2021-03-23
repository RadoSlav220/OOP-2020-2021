#include <iostream>
#include "player.h"

Player::Player()
{
    curSize = 0;
}

unsigned short Player::getHandSize() const {return curSize;}

Card Player::getCard(const unsigned short cardNum) const {return hand[cardNum];}

void Player::drawCard(const Card &newCard)
{
    if (curSize > 10){
        discardCard(0); //this is going to reduce the curSize by 1
    }
    hand[curSize] = newCard;
    curSize++;
}

bool Player::canPlayCard(unsigned short cardNum, const Card &prevCard)
{
    //the case the prevCard is +2
    if (hand[cardNum].getNumber() > 9 && hand[cardNum].getNumber() == prevCard.getNumber()-1){
        return true;
    }

    if (hand[cardNum].getColor() == black){
        return true;
    }

    if (hand[cardNum].getNumber() != prevCard.getNumber() && 
        hand[cardNum].getColor() != prevCard.getColor()){
            return false;
        }
    return true;
}

bool Player::isAnyPlayable(const Card& prevCard)
{
    for (unsigned short i=0; i<curSize; i++){
        if (canPlayCard(i, prevCard)){
            return true;
        }
    }
    return false;
}

void Player::discardCard(unsigned short cardNum)
{
    for (unsigned short i=cardNum; i<curSize-1; i++){
        hand[i] = hand[i+1];
    }
    curSize--;
}

void Player::printHand()
{
    std::cout << "Your hand: " << std::endl;
    for (unsigned short i=0; i<curSize; i++){
        std::cout << i << ") ";
        hand[i].printCard();
    }
}

bool Player::isWinner()
{
    return curSize == 0;
}