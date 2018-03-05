#include "player.h"
#include <string>

Player::Player(string name1) {
	name = name1;
	score = 0;
	//initialzing the hand of the player
	//we will set it to true as if they have all already played all of their hand
	// meaning that their hand array is empty
	for (int i = 0; i < Max_Cards; i++) {
		hasPlayed[i] = true;
	}

}

Card Player::playCard() {
	Card choice;

	//this looks for any slot in the hasPlayed that is not empty 
	// first one that is not empty gets chosen 
	for (int i = 0; i < Max_Cards; i++)
	{
		if (hasPlayed[i] != true) {
			choice = hand[i];
			hasPlayed[i] = true;
			break;
		}
	}
	
	return choice;
}

void Player::drawCard(Deck& dk) {
	//passed deck is the deck we are allowed to choose from
	Card drawnCardFromTopOfTheDeck = dk.dealCard();

	//after we choose a card from the deck we look for 
	//  a empty slot, the first slot gets filled with that card
	for (int i = 0; i < Max_Cards; i++) {
		if (hasPlayed[i] == true) {
			hand[i] = drawnCardFromTopOfTheDeck;
			hasPlayed[i] = false;
			break;
		}
	}

}

void Player::addScore(Card acard) {
	score += acard.getPointValue();
}

int Player::getScore() const {
	return score;
}

string Player::getName() const {
	return name;
}

bool Player::emptyHand() const {
	bool isEmptyHand = true;
	//looks for any slot that is not empty 
	// if there an non empty slot thein it returns false
	// else it is empty 
	for (int i = 0; i < Max_Cards; i++) {
		if (hasPlayed[i] != true) {
			isEmptyHand = false;
			break;
		}
	}
	
	return isEmptyHand;
}

//outputs the current hand of the player
ostream& operator << (std::ostream& os, const Player& playa) {
	os << playa.getName() <<"'s hand: ";
	for (int i = 0; i < playa.Max_Cards; i++) {
		if (playa.hasPlayed[i] == true) {
			os << "________  ";
		}
		else {
			os << playa.hand[i] << " ";
		}
	}
	os << "with score " << playa.getScore() << std::endl;
	return os;
}