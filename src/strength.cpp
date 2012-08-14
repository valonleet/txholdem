#include "strength.h"
#include <algorithm>
#include <iostream>

using std::sort;
using std::cout;
using std::endl;
using std::string;

strength::strength() {

}

strength::strength(hand h, deck d) {

}

strength::strength(deck d) : cards(d) {

}

void setHand(hand h, deck d) {

}

void strength::setDeck(deck d) {
	cards = d;
}

bool isRoyalFlush(deck::size_type hand52[]) {
	deck::size_type tPos = hand52[0];

	if ((tPos / 4) == 8) {
		for (deck::size_type i = 1; i < 5; ++i) {
			if ((tPos + (i * 4)) == hand52[i]) {
				continue;
			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	}

	return true;
}

bool isStraightFlush(deck::size_type hand[]) {
	deck::size_type firstCard = hand[0];

	for (deck::size_type i = 1; i < 5; ++i) {
		if ((firstCard + (i * 4)) == hand[i]) {
			continue;
		}
		else {
			return false;
		}
	}

	return true;
}

bool isFourOfAKind(deck::size_type hand[]) {
	deck::size_type firstCard = hand[0];

	// to 13 card deck
	for (deck::size_type i = 0; i < 5; ++i) {
		hand[i] /= 4;
	}

	if (hand[0] == hand[1]) {
		if (hand[1] == hand[2] && hand[2] == hand[3])
			return true;
	}
	else if (hand[1] == hand[4]) {
		if (hand[1] == hand[2] && hand[2] == hand[3])
			return true;
	}

	return false;
}

bool isFullHouse(deck::size_type hand[]) {
	// to 13 card deck
	for (deck::size_type i = 0; i < 5; ++i) {
		hand[i] /= 4;
	}

	if (hand[0] == hand[1]) {
		if (hand[2] == hand[3] && hand[3] == hand[4])
			return true;
		else if (hand[1] == hand[2] && hand[3] == hand[4])
			return true;
	}

	return false;
}

bool isFlush(deck::size_type hand[]) {
	deck::size_type firstCard = hand[0];

	for (deck::size_type i = 1; i < 5; ++i) {
		if (hand[i] % 4 == (firstCard % 4)) {
			continue;
		}
		else {
			return false;
		}
	}

	return true;
}

bool isStraight(deck::size_type hand[]) {
	deck::size_type firstCard = hand[0];

	// to 13 card deck
	for (deck::size_type i = 0; i < 5; ++i) {
		hand[i] /= 4;
	}

	for (deck::size_type i = 1; i < 5; ++i) {
		if (hand[i] == firstCard + i) {
			continue;
		}
		else {
			return false;
		}
	}

	return true;
}

bool isThreeOfAKind(deck::size_type hand[]) {
	// to 13 card deck
	for (deck::size_type i = 0; i < 5; ++i) {
		hand[i] /= 4;
	}

	if (hand[0] == hand[1]) {
		if (hand[1] == hand[2])
			return true;
	}
	else if (hand[1] == hand[2]) {
		if (hand[2] == hand[3])
			return true;
	}
	else if (hand[2] == hand[3]) {
		if (hand[3] == hand[4])
			return true;
	}

	return false;
}

bool isTwoPair(deck::size_type hand[]) {
	// to 13 card deck
	for (deck::size_type i = 0; i < 5; ++i) {
		hand[i] /= 4;
	}

	if (hand[0] == hand[1] && hand[2] == hand[3])
		return true;
	else if (hand[1] == hand[2] && hand[3] == hand[4])
		return true;
	else if (hand[0] == hand[1] && hand[3] == hand[4])
		return true;

	return false;
}

bool isPair(deck::size_type hand[]) {
	// to 13 card deck
	for (deck::size_type i = 0; i < 5; ++i) {
		hand[i] /= 4;
	}

	for (deck::size_type i = 0; i < 4; ++i) {
		if (hand[i] == hand[i + 1])
			return true;
	}

	return false;
}

deck::size_type strength::calculateStrength() {
	typedef deck::size_type deck_sz;

	// strength of each hand type from pair to royal flush
	static deck_sz ranks[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// 7 cards to calculate 5 card hands from
	deck_sz possibleHands[7];

	// counter to fill in possibleHands
	deck_sz c = 0;

	// 5 cards to be tested at a time
	deck_sz hand[5];

	// indices to calculate combinations
	deck_sz i, j, k, l, m;

	// max hand to return
	deck_sz max = 0;

	// fill in possible hands from the cards in cards
	for (deck_sz s = 0; s < 52; ++s) {
		if (cards.getCardBool(s) == true) {
			possibleHands[c] = s;
			++c;
		}
	}

	cout << "Cards: ";
	for (deck_sz x = 0; x < 7; ++x) {
		cout << cardToString(possibleHands[x]) << " ";
	}
	cout << endl << endl;

	// 13 card deck
	deck_sz hand13[7];

	// get combinations and calculate the strength of each
	for (i = 0; i < 3; ++i) {
		for (j = i + 1; j < 4; ++j) {
			for (k = j + 1; k < 5; ++k) {
				for (l = k + 1; l < 6; ++l) {
					for (m = l + 1; m < 7; ++m) {
						// set the hand
						hand[0] = possibleHands[i];
						hand[1] = possibleHands[j];
						hand[2] = possibleHands[k];
						hand[3] = possibleHands[l];
						hand[4] = possibleHands[m];

						for (deck_sz x = 0; x < 5; ++x) {
							cout << cardToString(hand[x]) << " ";
						}

						if (isRoyalFlush(hand)) {
							cout << "ROYAL FLUSH" << std::endl;
						}
						else if (isStraightFlush(hand)) {
							cout << "STRAIGHT FLUSH" << std::endl;
						}
						else if (isFourOfAKind(hand)) {
							cout << "FOUR OF A KIND" << std::endl;
						}
						else if (isFullHouse(hand)) {
							cout << "FULL HOUSE" << std::endl;
						}
						else if (isFlush(hand)) {
							cout << "FLUSH" << std::endl;
						}
						else if (isStraight(hand)) {
							cout << "STRAIGHT" << std::endl;
						}
						else if (isThreeOfAKind(hand)) {
							cout << "THREE OF A KIND" << std::endl;
						}
						else if (isTwoPair(hand)) {
							cout << "TWO PAIR" << std::endl;
						}
						else if (isPair(hand)) {
							cout << "PAIR" << std::endl;
						}
						else {
							cout << "FUCK" << std::endl;
						}
						
					}
				}
			}
		}
	}

	return 5;

}

// print a card (size_type) as a formatted string
string cardToString(deck::size_type card) {
	string value;	// card's value
	string suit;	// card's suit

	// There are 52 cards in a deck
	// for each card value there are 4 cards (one for each suit)
	// 52 / 4 = 13, there are 13 groups of cards
	// the card value / 4 gives the group the card belongs to
	switch (card / 4) {
	case 0:
		value = "2";
		break;
	case 1:
		value = "3";
		break;
	case 2:
		value = "4";
		break;
	case 3:
		value = "5";
		break;
	case 4:
		value = "6";
		break;
	case 5:
		value = "7";
		break;
	case 6:
		value = "8";
		break;
	case 7:
		value = "9";
		break;
	case 8:
		value = "10";
		break;
	case 9:
		value = "J";
		break;
	case 10:
		value = "Q";
		break;
	case 11:
		value = "K";
		break;
	case 12:
		value = "A";
		break;
	}

	// there are 4 types of each card
	// the suits follow the order h, d, c, s, ...
	// card % 4 will give the suit
	switch (card % 4) {
	case 0:
		suit = "H";
		break;
	case 1:
		suit = "D";
		break;
	case 2:
		suit = "C";
		break;
	case 3:
		suit = "S";
		break;
	}

	// the format is VALUE-SUIT
	return value + "-" + suit;
}