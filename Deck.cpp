/**
 * @file Deck.cpp
 *
 */

#include "Deck.h"
#include "Card.h"

Deck::Deck() {
    for (int s = 0; s < 4; s++)
    {
        for (int r = 1;r < 14; ++r)
        {
            Card card( (Card::Suit) s ,(Card::Rank) r);
            cardDeck.push_back(card);
        }
    }
    nextCard = 0;//set next card to 0
}


void Deck::shuffle()
{
    // loop to shuffle the cards
    for (size_t i = 0; i < cardDeck.size() / 2;)
    {
        int ind1 = rand() % MaxCards;
        int ind2 = rand() % MaxCards;
        if (ind1 != ind2)
        {
            Card temp = cardDeck[ind1];
            cardDeck[ind1] = cardDeck[ind2];
            cardDeck[ind2] = temp;
            i++;
        }
    }
    nextCard = 0;
}


bool Deck::isEmpty() const
{
    return(nextCard >= cardDeck.size());
}


 Card Deck::draw()
{
    if (isEmpty())
    {
        std::out_of_range d("Empty Deck");
        throw d;
    }
    Card card = cardDeck[nextCard];
    nextCard++;
    return card;
}