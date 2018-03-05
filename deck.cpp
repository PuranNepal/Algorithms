#include "deck.h"
#include <algorithm>
#include <iostream>

Deck::Deck() {

	//this records 4 different suits
	int count = 0;

	//this initialized the deck of 52 card 
	for (int i = 0; i < numCards; i++) {

		//if the card is filled 13 cards for a suit then
		// we update count to move on to different suit
		if ((i >= 13) && (i % 13 == 0)) {
			count += 1;
		}
		// there are only 13 cards in one suit
		theDeck[i] = Card(i % 13, suit(count));
	}

	//initializing topCard
	topCard = 0;
}

Card Deck::dealCard() {
	Card topMostCard;
	//get the top card
	topMostCard = theDeck[topCard];
	//we move to different card
	topCard += 1;
	return topMostCard;
}

void Deck::Shuffle() {
	//using the standard library shuffle algorithm
	std::random_shuffle(&theDeck[0], &theDeck[numCards]);
}

bool Deck::isEmpty() {
	//if topCard is more than number of card than we have no more 
	// card to choose from
	if (topCard >= numCards) {
		return true;
	}

	return false;
}

ostream& operator << (ostream& os, const Deck& dec) {
	//out puts all card in the deck
	int count = 1;
	for (int i = 0; i < dec.numCards; i++) {
		os << dec.theDeck[i] << "  ";
		if (count % 10 == 0) {
			os << std::endl;
		}
		count += 1;
	}
	os << std::endl;
	return os;
}