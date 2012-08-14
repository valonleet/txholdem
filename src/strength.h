#ifndef GUARD_strength_h
#define GUARD_strength_h

#include "deck.h"

//==================================================
// STRENGTH
// class used to calculate a hand's strength
//==================================================
class strength {
public:
	strength();
	strength(hand, deck);
	strength(deck);

	void setHand(hand, deck);
	void setDeck(deck);

	deck::size_type calculateStrength();

private:
	deck cards;
};

bool sortPredicate(deck::size_type);
bool isRoyalFlush(deck::size_type cards[]);
bool isStraightFlush(deck::size_type cards[]);
bool isFourOfAKind(deck::size_type cards[]);
bool isFullHouse(deck::size_type cards[]);
bool isFlush(deck::size_type cards[]);
bool isStraight(deck::size_type cards[]);
bool isThreeOfAKind(deck::size_type cards[]);
bool isTwoPair(deck::size_type cards[]);
bool isPair(deck::size_type cards[]);

std::string cardToString(deck::size_type);

#endif