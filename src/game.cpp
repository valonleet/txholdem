#include "game.h"
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;
using std::invalid_argument;

// constructors
/*ame::game() : playerFile("players.txt") {

}*/

game::game(string playerFile) : playerFile(playerFile) {

}

//============================
// player file format :
// line 1: name	
// line 2: money
//============================
player game::loadPlayer(std::string name) {
	ifstream loadFile(playerFile.c_str());
	std::string line;
	std::string money = "";

	if (!loadFile)
		throw invalid_argument("File not Found");

	// find a line with the proper name
	while (getline(loadFile, line)) {
		if (line == name) {
			// name found, the next line is the money
			getline(loadFile, money);

			// file clean up
			loadFile.clear();
			loadFile.close();

			// return the player
			return player(name, atoi(money.c_str()));
		}
	}

	// file clean up
	loadFile.clear();
	loadFile.close();

	// return false to indicate failure
	return player();
}

// add a player by name
void game::addPlayer(std::string name) {
	player p = loadPlayer(name);

	if (p.getName() != "") {
		players.push_back(p);
	}
}

// remove player by name
void game::removePlayer(string name) {
	vector<player>::iterator begin = players.begin();

	// find the player
	while (begin != players.end()) {
		if (begin->getName() == name) {
			break;
		}
		++begin;
	}

	// need to save their money first
	if (begin != players.end())
		players.erase(begin);
}

// deal to the players
void game::deal() {
	//===============================================================================
	// NOTE==========================================================================
	// you might alternate who you deal to first, check that and update accordingly
	//===============================================================================
	vector<player>::iterator iter;		// iterate through players
	deck::size_type card1;				// first card for player
	deck::size_type card2;				// second card for player

	// deal to each player
	while (iter != players.end()) {
		// generate 2 cards
		card1 = dealt.randomCard();
		card2 = dealt.randomCard();

		// set the players hand
		iter->setHand(card1, card2);

		// toggle the dealt cards
		dealt.toggleCard(card1);
		dealt.toggleCard(card2);

		// go to next player
		++iter;
	}
}

void game::flop() {
	deck::size_type card1, card2, card3;

	// get 3 random cards that have not been dealt
	card1 = dealt.randomCard();
	card2 = dealt.randomCard();
	card3 = dealt.randomCard();

	// toggle cards in the dealt deck
	dealt.toggleCard(card1);
	dealt.toggleCard(card2);
	dealt.toggleCard(card3);

	// toggle cards in the table deck
	table.toggleCard(card1);
	table.toggleCard(card2);
	table.toggleCard(card3);
}

void game::turn() {
	deck::size_type card;

	// random card
	card = dealt.randomCard();

	// toggle dealt
	dealt.toggleCard(card);

	// toggle table
	table.toggleCard(card);
}

void game::river() {
	turn();
}

void game::takeBets() {

}

void game::gameOver() {

}