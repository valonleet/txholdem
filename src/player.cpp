#include "player.h"

// set the player's hand
void player::setHand(deck::size_type c1, deck::size_type c2) {
	cards.setCards(c1, c2);
}