#pragma once

/*
    Card values mean:
    - from 1 to 9 - ordinary ones
    - 10 - unexecuted +2
    - 11 - executed +2
*/

enum COLOR{
    unknown, //TBD
    yellow,
    red,
    blue,
    green, 
    black
};

class Card {
private:
    unsigned short number;
    COLOR color;

public:
    Card();
    Card(unsigned short, COLOR);
    Card& operator=(const Card& _card);

public:
    void setNumber(const unsigned short newNum);
    void setColor(const COLOR newClr);
    unsigned short getNumber() const;
    COLOR getColor() const;

public:
    void printCard() const;
};