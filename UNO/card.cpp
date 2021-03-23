#include <iostream>
#include "card.h"

Card::Card()
{
    number = 0;
    color = unknown; 
}

//does not validate the card info 
//this task is supposed to be done in another class
Card::Card(unsigned short num, COLOR clr)
{
    number = num;
    color = clr;
}

Card& Card::operator=(const Card& _card)
{
    if (this == &_card){
        return *this;
    }
    number = _card.number;
    color = _card.color;
    return *this;
}

//Setters
void Card::setNumber(const unsigned short newNum)
{
    number = newNum;
}

void Card::setColor(const COLOR newClr)
{
    color = newClr;
}

//Getters
unsigned short Card::getNumber() const {return number;}
COLOR Card::getColor() const {return color;}

void Card::printCard() const
{
    switch (color){
        case 1: std::cout << "Yellow "; break;
        case 2: std::cout << "Red "; break;
        case 3: std::cout << "Blue "; break;
        case 4: std::cout << "Green "; break;
        case 5: std::cout << "Change Clr" << std::endl; return;
        default: std::cout << "Unknown "; break;
    }
    //10 means the card is a magic card (+2)
    if (number == 10 || number == 11){
        std::cout << "+2" << std::endl;
    }
    else {
        std::cout << number << std::endl;
    }
}