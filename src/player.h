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
	player();														// default constructor, default string name and 0 money
	player(std::string, unsigned int);								// create player from name and money

	// operators
	player operator=(const player&);								// assignment operator

	// accessors
	const std::string getName() const { return name; }				// return name
	const unsigned int getMoney() const { return money; }			// return money
	const hand getHand() const { return cards; }					// return hand

	void modifyMoney(unsigned int, mode);							// add or subtract from the player's money
	void setHand(deck::size_type, deck::size_type);					// set the player's hand
	void commands();												// loop to take player command

private:
	std::string name;												// the player's account name
	unsigned int money;												// the player's money
	hand cards;														// the cards the player has
};

#endif