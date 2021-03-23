#include <iostream>
#include <ctime>
//#include "card.h"
//#include "player.h"
#include "deck.h"

using std::cout;
using std::endl;
using std::cin;

const int playersCount = 3;

void drawCards(Player &pl, Deck &deck, const int cardsCnt)
{
    cout << "Ooops, you gotta draw " << cardsCnt << " card(s)!" << endl;
    system("pause");
    for (int i=0; i<cardsCnt; i++){
        Card newCard = deck.generateCard();
        pl.drawCard(newCard);
        cout << "You drew: ";
        newCard.printCard();
        system("pause");
    }
}

int main()
{
    srand(time(NULL));
    Player players[playersCount];
    Deck deck;


    //Game settup
    for (int i=0; i<playersCount; i++){
        //here the starting number of cards can be changed
        for (int j=0; j<2; j++){
            Card card = deck.generateCard();
            players[i].drawCard(card);   
        }
    }

    Card currCard = deck.getPrevCard();
    bool won = false; //true if anyone has won
 
    system("cls");

    while (!won){
        for (int i=0; i<playersCount; i++){
            cout << endl << "Player " << i+1 << ", your turn!" << endl;
            currCard.printCard();
            players[i].printHand();
            cout << endl << players[i].getHandSize() << ") draw a card no matter what the cards are\n" << endl;
            
            //currCard is +2
            if (currCard.getNumber() == 10){
                drawCards(players[i], deck, 2);
                currCard.setNumber(11);
            }

            //if the player cannot play any card
            //if the first card in the game is black, the player must be allowed to play any card he wants
            else if (!players[i].isAnyPlayable(currCard) && currCard.getColor() != black){
                drawCards(players[i], deck, 1);
            }

            else {
                cout << "Choose a card to be played!" << endl;
                unsigned short choosenCard;
                cin >> choosenCard;

                //if the player chooses to draw anyway
                if (choosenCard == players[i].getHandSize()){
                    drawCards(players[i], deck, 1);
                    system("cls");
                    continue;
                }

                while (!cin || choosenCard > players[i].getHandSize() || (!players[i].canPlayCard(choosenCard, currCard) && currCard.getColor()!=black)){
                    cout << "You cannot play this card! Choose another one!" << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> choosenCard;
                }

                currCard = players[i].getCard(choosenCard);

                //if the played card is Change color
                if (players[i].getCard(choosenCard).getColor() == black){
                    cout << "Choose the new color: " << endl;
                    cout << "1) Yellow" << endl;
                    cout << "2) Red" << endl;
                    cout << "3) Blue" << endl;
                    cout << "4) Green" << endl;
                    short newColor;
                    cin >> newColor;
                    while (!cin || newColor <= 0 || newColor > 4){
                        cout << "Invalid color selected! Select a valid one!" << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> newColor;
                    }
                    currCard.setColor(static_cast<COLOR> (newColor));
                    currCard.setNumber(0);
                }
                
                players[i].discardCard(choosenCard);

                //winning check
                if (players[i].isWinner()){
                    cout << "Player " << i+1 << " is the winner!" << endl;
                    won = true;
                    break;
                }
            }
            system ("cls");
        }
    }

    return 0;
}