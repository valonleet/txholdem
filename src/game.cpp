#include "game.h"

using std::vector;

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
		card1 = randomCard(dealt);		// pass dealt deck
		card2 = randomCard(dealt);

		// set the players hand
		iter->setHand(card1, card2);

		// toggle the dealt cards
		dealt.toggleCard(card1);
		dealt.toggleCard(card2);

		// go to next player
		++iter;
	}
}