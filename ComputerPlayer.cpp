/**
 * @file ComputerPlayer.cpp
 * 
 */

#include "ComputerPlayer.h"
#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

Card ComputerPlayer::playCard(const Card& opponentCard) {
    unsigned index = rand () % hand.size();
    Card chosenCard = hand[index];
    cout << "Computer played " << chosenCard << endl;
    hand.erase(hand.begin() + index);
    return chosenCard;

}

