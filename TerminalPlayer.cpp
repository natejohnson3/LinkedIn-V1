/**
 * @file TerminalPlayer.cpp
 * 
 */

#include "TerminalPlayer.h"
#include "Card.h"
#include <iostream>
#include <ostream>
#include <string>


Card TerminalPlayer::playCard(const Card& opponentCard) {
    // If opponentCard is a Joker, we are going first
    // Check if the opponent card is a joker
    if (opponentCard.isJoker()) {
        // We are going first, so pick any card from our hand
        std::cout << "You are going first.\n";
        std::cout << "Your hand: ";  
        std::cout << hand[0] << ", " << hand[1] << ", " << hand[2] << std::endl;
        std::cout << "Choose a card to play (enter 0-2): ";
        int index;
        std::cin >> index;
        Card playedCard = hand[index];
        std::cout << "Card Played: " << playedCard << std::endl;
        hand.erase(hand.begin() + index);
        return playedCard;
        
    }    else {
        // We are going second, so opponentCard is what our opponent played
        std::cout << "You are going second.\n";
        std::cout << "Your hand: ";  
        std::cout << hand[0] << ", " << hand[1] << ", " << hand[2] << std::endl;
        std::cout << "Choose a card to play (enter 0-2): ";
        int index;
        std::cin >> index;
        Card playedCard = hand[index];
        std::cout << "Card Played: " << playedCard << std::endl;
        hand.erase(hand.begin() + index);
        return playedCard;
    }
}
