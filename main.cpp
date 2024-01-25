/**
 * @brief main
 * 
 */
#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "TerminalPlayer.h"
#include "ComputerPlayer.h"
#include "Player.h"

using namespace std;

int main(int argc, const char * argv[])
{
   // create a deck
    Deck deck;

    // shuffle the deck
    deck.shuffle();


    TerminalPlayer player1("Mary");
    ComputerPlayer player2("Computer");

    // Test playing a card as going first
    Card opponentCard = Card();

    player1.receiveCard(deck.draw());
    player2.receiveCard(deck.draw());
    player1.receiveCard(deck.draw());
    player2.receiveCard(deck.draw());
    player1.receiveCard(deck.draw());
    player2.receiveCard(deck.draw());


    bool player1First = rand() % 2;    //check 10:30
    Card player1Card;
    Card player2Card;
    Card Joker = Card();

    while(player1.hasCards()){

        if(player1First){
            player1Card = player1.playCard(Joker);
            player2Card = player2.playCard(player1Card);
        } else {
            player2Card = player2.playCard(Joker);
            player1Card = player1.playCard(player1Card);
        }

            
        //check two cards to see who wins
        //update score
        //based on winner we need to determine who goes first next round
        if (player1Card < player2Card){
            player2.addScore(1);
            cout << "Computer wins this round" << endl;
            player1First = false;

        }else if(player2Card == player1Card){
            cout  << "Tied" << endl;

        }else{
            player1.addScore(1);
            cout << "Terminal player wins this round" << endl;
            player1First = true;
        }

        // if there are cards left in the deck draw cards for the players
        if(!deck.isEmpty()){
            player1.receiveCard(deck.draw());
            player2.receiveCard(deck.draw());
        }
    }

 
    //see who won and and the game
    if(player1.getScore() > player2.getScore() ){
        cout << "Player 1 wins with " << player1.getScore() << endl;
    }else if(player1.getScore() == player2.getScore()){
        cout << "The game is a tie " << player1.getScore() << endl;
    }else{
        cout << "Player 2 wins with " << player2.getScore() << endl;
    }
    
    

    return 0;
}