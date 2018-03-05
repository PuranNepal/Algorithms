#include "card.h"
#include <iostream>
#include <string>

Card::Card() {
	//we don't want any face so we choose something lower than 0
	cardFace = -1;
	pointValue = 0;
}

Card::Card(int face, suit st) {
	cardSuit = st;
	cardFace = face;
	switch (cardFace)
	{
	case 0: 
		pointValue = 15;
		break;
	case 1:
		pointValue = 2;
		break;
	case 2:
		pointValue = 3;
		break;
	case 3:
		pointValue = 4;
		break;
	case 4:
		pointValue = 5;
		break;
	case 5:
		pointValue = 6;
		break;
	case 6:
		pointValue = 7;
		break;
	case 7:
		pointValue = 8;
		break;
	case 8:
		pointValue = 9;
		break;
	case 9:
		pointValue = 10;
		break;
	case 10:
		pointValue = 10;
		break;
	case 11:
		pointValue = 10;
		break;
	case 12:
		pointValue = 10;
		break;
	};
}

bool Card::operator < (const Card& cd) const {
	if (pointValue < cd.pointValue) {
		return true;
	}

	return false;
}

bool Card::operator > (const Card& cd) const {
	if (pointValue > cd.pointValue) {
		return true;
	}
	return false;
}

bool Card::operator== (const Card& cd) const {
	if (pointValue == cd.pointValue) {
		return true;
	}

	return false;
}


//this outputs individual card
ostream& operator << (ostream& os, const Card& cd) {
	char suitSymbol;
	std::string faceSymbol;
	//gives the face symbol to a card
	switch (cd.cardFace)
	{
	case 0:
		faceSymbol = "A";
		break;
	case 1:
		faceSymbol = "2";
		break;
	case 2:
		faceSymbol = "3";
		break;
	case 3:
		faceSymbol = "4";
		break;
	case 4:
		faceSymbol = "5";
		break;
	case 5:
		faceSymbol = "6";
		break;
	case 6:
		faceSymbol = "7";
		break;
	case 7:
		faceSymbol = "8";
		break;
	case 8:
		faceSymbol = "9";
		break;
	case 9:
		faceSymbol = "10";
		break;
	case 10:
		faceSymbol = "J";
		break;
	case 11:
		faceSymbol = "Q";
		break;
	case 12:
		faceSymbol = "K";
		break;
	};

	//gives suit symbol
	switch (cd.cardSuit)
	{
	case hearts:
		//0x03 is heart symbol
		suitSymbol = ((char)0x03);
		break;
	case diamonds:
		//diamond symbol
		suitSymbol = ((char)0x04);
		break;
	case clubs:
		//club symbol
		suitSymbol = ((char)0x05);
		break;
	case spades:
		//spade symbol
		suitSymbol = ((char)0x06);
		break;
	};

	//outputs individual card with face, suit and how much point it is worth
	os << faceSymbol << suitSymbol << "[" << cd.getPointValue() << "]";

	return os;
}

int Card::getPointValue() const {
	return pointValue;
}
