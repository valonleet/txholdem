#ifndef GUARD_game_h
#define GUARD_game_h

#include "deck.h"
#include "player.h"
#include <string>
#include <vector>

class game {
public:		
	game(std::string playerFile = "players.txt");		// constructor, defaults playerFile to players.txt

	player loadPlayer(std::string name);				// load a player, return true if the player was loaded, false if not
	void addPlayer(std::string);						// add a player
	void removePlayer(std::string);						// remove a player	
	void deal();										// deal cards to players
	void flop();										// flop, first 3 cards on board
	void turn();										// turn, next card on board
	void river();										// river, final card on board
	void takeBets();									// take bets
	void getWinner();									// get the round winner
	void gameOver();									// clean up once the round is finished

		
private:
	std::string id;										// the game's id

	const std::string playerFile;						// the file to load players from

	deck dealt;											// the cards that have been dealt
	deck table;											// the cards on the table

	unsigned int pot;									// prize pot of money

	std::vector<player> players;						// the players
														// players are positioned from left to right
};

void genID(char*, const int);

#endif