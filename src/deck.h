#ifndef GUARD_deck_h
#define GUARD_deck_h

#include <string>
#include <utility>

//=========================
// DECK
// A general 52 card deck
//=========================
class deck {
public:
	// typedefs
	typedef bool* iterator;										// iterator
	typedef const bool* const_iterator;							// const iterator
	typedef size_t size_type;									// size_type

	deck();														// default constructor sets all members of cards to false
	deck(bool);													// sets all members of card to bool value

	iterator begin();											// returns cardsBegin
	iterator end();												// returns cardsEnd

	bool toggleCard(const size_type);							// negates a card (true->false, false->true)

	bool getCardBool(const size_type);							// returns the boolean value of a card given a position
	static std::string cardToString(const deck::size_type);		// returns a card position (size_type) as a formatted string such as A-S

	bool inPlay(deck::size_type);								// return true if a card is in play (i.e. it is true)
	deck::size_type randomCard();								// generate a random card that is not in play

private:
	bool cards[52];												// a deck is 52 bools, one for each card
																// the deck is in non-decreasing order : 2 - A
																// the suits follow the pattern h, d, c, s, ...

	iterator cardsBegin;										// iterator (a pointer) to the first element in cards
	iterator cardsEnd;											// iterator (a pointer) to (one past) the last elemnt in cards
};



//=======================
// HAND
// A player's hand
//=======================
class hand {
public:
	typedef size_t size_type;

	hand();										// hand initializes two cards to -1
	hand(size_type, size_type);					// creates a hand with the given cards

	void setCards(size_type, size_type);		// set cards equal to the cards given

private:
	std::pair<size_type, size_type> cards;		// the player's hand, a pair of cards
};

#endif