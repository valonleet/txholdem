#include "player.h"
#include <fstream>

using std::string;
using std::ifstream;
using std::invalid_argument;

// default constructor, name default intialized and money 0
player::player() : money(0) {

}

// initialized name and money
player::player(string name, unsigned int money) : name(name), money(money) {

}

// assignment
player player::operator=(const player& p) {
	if (&p != this) {
		name = p.name;
		money = p.money;
		cards = p.cards;
	}

	return *this;
}

// add or subtract money
void player::modifyMoney(unsigned int offset, mode m) {
	if (m == add)
		money += offset;
	else
		money -= offset;
}

// set the player's hand
void player::setHand(deck::size_type c1, deck::size_type c2) {
	cards.setCards(c1, c2);
}