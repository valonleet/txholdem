#include "deck.h"
#include <stdexcept>
#include <map>
#include <vector>

using std::out_of_range;
using std::string;
using std::map;
using std::vector;

//===================
// DECK
//===================

// default
// initialize cardsBegin and cardsEnd to 0
// set all cards to false
deck::deck() : cardsBegin(0), cardsEnd(0) {
	for (size_type i = 0; i != 52; ++i) {
		cards[i] = false;
	}

	cardsBegin = cards;
	cardsEnd = cards + 52;
}

// same as default except all cards set to b
deck::deck(bool b) : cardsBegin(0), cardsEnd(0) {
	for (size_type i = 0; i != 52; ++i) {
		cards[i] = b;
	}

	cardsBegin = cards;
	cardsEnd = cards + 52;
}

// returns an iterator to the first card
deck::iterator deck::begin() {
	return cardsBegin;
}

// returns an iterator to (one past) the last card in cards
deck::iterator deck::end() {
	return cardsEnd;
}

// negate (toggle) the card at the given position
bool deck::toggleCard(const size_type position) {
	static const size_type maxCards = 51;

	if (position > maxCards || position < 0)
		throw out_of_range("Card out of range");
	else
		cards[position] = !cards[position];

	return cards[position];
}

// this is probably useless to have
bool deck::getCardBool(const size_type position) {
	return cards[position];
}

// print a card (size_type) as a formatted string
string deck::cardToString(const deck::size_type card) {
	string value;	// card's value
	string suit;	// card's suit

	// There are 52 cards in a deck
	// for each card value there are 4 cards (one for each suit)
	// 52 / 4 = 13, there are 13 groups of cards
	// the card value / 4 gives the group the card belongs to
	switch (card / 4) {
	case 0:
		value = "2";
		break;
	case 1:
		value = "3";
		break;
	case 2:
		value = "4";
		break;
	case 3:
		value = "5";
		break;
	case 4:
		value = "6";
		break;
	case 5:
		value = "7";
		break;
	case 6:
		value = "8";
		break;
	case 7:
		value = "9";
		break;
	case 8:
		value = "10";
		break;
	case 9:
		value = "11";
		break;
	case 10:
		value = "J";
		break;
	case 11:
		value = "Q";
		break;
	case 12:
		value = "K";
		break;
	case 13:
		value = "A";
		break;
	}

	// there are 4 types of each card
	// the suits follow the order h, d, c, s, ...
	// card % 4 will give the suit
	switch (card % 4) {
	case 0:
		suit = "H";
		break;
	case 1:
		suit = "D";
		break;
	case 2:
		suit = "C";
		break;
	case 3:
		suit = "S";
		break;
	}

	// the format is VALUE-SUIT
	return value + "-" + suit;
}

// generate a random card position
deck::size_type randomCard(deck& d) {
	// really crappy way to generate a random number
	vector<deck::size_type> possibleCards;
	deck::size_type begin = 0;
	deck::size_type end = 52;

	// find all card positions that are not in play
	while (begin != end) {
		if (d.getCardBool(begin) == false) {
			possibleCards.push_back(begin);
		}
		++begin;
	}

	deck::size_type limit = possibleCards.size();

	// no cards left, throw an error! Shouldn't ever happen though
	if (limit == 0)
		throw out_of_range("No cards left!");

	// pick a position in possibleCards
	deck::size_type card = rand() % limit;

	// return the card at the chosen position
	return possibleCards[card];
}

// returns the value of a card as a bool
bool inPlay(deck::size_type position, deck& d) {
	return d.getCardBool(position);
}

//======================
// HAND
//======================

// default constructor
// the cards are initilized to -1
hand::hand() : cards(-1, -1) {

}

// initializes the cards to c1, c2
hand::hand(size_type c1, size_type c2) : cards(c1, c2) {

}

// manually set the cards to c1, c2
void hand::setCards(size_type c1, size_type c2) {
	cards.first = c1;
	cards.second = c2;
}