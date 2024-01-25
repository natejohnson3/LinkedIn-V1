/**
 * @file Card.cpp
 */

#include "Card.h"

 /**
  * @brief Construct a new card:: Card Object
  *
  */
Card::Card(Suit s, Rank r) {
    cardRank = r;
    cardSuit = s;
}
Card::Card(){
    cardRank = (Rank)0;  //set to joker
    cardSuit = (Suit)0; //set to spade
}
// operator overload to cout contents of individual cards

std::ostream& operator <<(std::ostream& ce, const Card& card) 
{

    if (card.isJoker()) {
        ce << "empty card\n";
    }
    else {
        ce << rankNames[card.cardRank] << " " << suitNames[card.cardSuit];
    }
    return ce;
}

bool operator ==(const Card& lhs, const Card& rhs){ //operator overload to compare cards
    return(lhs.cardRank == rhs.cardRank);
}
bool operator <(const Card& lhs, const Card& rhs){ //operator overload to compare cards
    return(lhs.cardRank < rhs.cardRank);
}