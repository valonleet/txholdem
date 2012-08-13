#ifndef GUARD_game_h
#define GUARD_game_h

#include "deck.h"
#include "player.h"
#include <string>
#include <vector>

class game {
public:		
	void addPlayer(player);		// add a player
	void deal();				// deal cards to players
	void flop();				// flop, first 3 cards on board
	void turn();				// turn, next card on board
	void river();				// river, final card on board
	void takeBets();			// take bets
	void gameOver();			// clean up once the round is finished

private:
	deck dealt;					// the cards that have been dealt
	deck table;					// the cards on the table

	unsigned int pot;			// prize pot of money

	std::vector<player> players;	// the players
									// players are positioned from left to right
};

#endif