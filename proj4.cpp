/*
Author: Puran Nepal
Course: CSCI 3110
Project: Project 4
*/

#include <iostream>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <stdlib.h>
using namespace std;

int main() {
	srand(1000); //random seed
	Deck myDeck; //initializing our deck 
	Player player1("Player 1"); //creating player 1 
	Player player2("Player 2"); //creating player 2
	Card player1Choice; //this variable records the card being played by player 1
	Card player2Choice; //this variable records the card being played by player 2
	int Max_PlayerCard = player1.Max_Cards; //maxium number of card a player is allowed to hold in his/her hand
	int count = 1; //nth hand
	bool flag = false; //flag


	cout << "Original deck has the following cards: " << endl;
	cout << myDeck;
	cout << endl;

	cout << "The deck after shuffling (top of the deck listed first): " << endl;
	myDeck.Shuffle();
	cout << myDeck;
	cout << endl;
	
	//initialzing number of player's card 
	// this distributes max_number of cards to each player from the shuffled deck
	for (int i = 0; i < Max_PlayerCard; i++) {
		player1.drawCard(myDeck);
		player2.drawCard(myDeck);
	}
	
	//this is where the players start playing hands 
	//it stops when the deck is empty and the player's hand is empty.
	while (flag != true) {
		cout << "**************************** Hand " << count << " ****************************" << endl;

		//outputs the current hand of the player
		cout << player1;
		cout << player2;

		//players draw the top card from their HAND
		player1Choice = player1.playCard();
		player2Choice = player2.playCard();

		//displays what they have choosen
		cout << player1.getName() << " played card: " << player1Choice << " --- "
			<< player2.getName() << " played card: " << player2Choice << endl;
		cout << endl;

		//if nobody wins then nobody gets anypoint
		if (player1Choice == player2Choice) {
			cout << "It's a draw! " << "nobody won!" << endl;
		} //if player1 wins the hand 
		else if (player1Choice > player2Choice) {
			cout << player1.getName() << " wins this hand." << endl;
			//adds the point of the both cards to the score 
			player1.addScore(player1Choice);
			player1.addScore(player2Choice);
		}
		else {
			//if the player2 wins
			cout << player2.getName() << " wins this hand." << endl;
			player2.addScore(player1Choice);
			player2.addScore(player2Choice);
		}

		//displays the remaining hand of the both player
		cout << player1;
		cout << player2;

		//if the deck is NOT EMPTY then players draw a card from the deck
		//if the deck is empty players will keep playing from their hand until their hand is completely empty
		if (myDeck.isEmpty() != true) {
			player1.drawCard(myDeck);
			player2.drawCard(myDeck);
		}
		
		//if player's their hand is expty then the game stops
		// we can just check for one player because their playing at the same time
		if (player1.emptyHand() == true) {
			flag = true;
		}

		//updating our hand
		count += 1;
		cout << endl;
	}

	//outputs who the game by how much point
	if (player1.getScore() > player2.getScore()) {
		cout << player1.getName() << " wins with a score of " << player1.getScore() << endl;
	}
	else {
		cout << player2.getName() << " wins with a score of " << player2.getScore() << endl;
	}
	
	system("pause");
	return 0;
}