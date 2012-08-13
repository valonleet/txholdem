#ifndef GUARD_player_h
#define GUARD_player_h

#include "deck.h"

// modes of modifying money
enum mode {
	add = 0,		// add to the player's money
	subtract = 1	// subtract from the player's money
};

//================
// PLAYER
// a player
//================
class player {
public:

	void modifyMoney(unsigned int, mode);				// add or subtract from the player's money
	void setHand(deck::size_type, deck::size_type);		// set the player's hand

private:
	unsigned int money;		// the player's money
	hand cards;				// the cards the player has
};

#endif