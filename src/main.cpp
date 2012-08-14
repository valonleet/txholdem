#include "game.h"
#include <iostream>
#include <fstream>
#include "strength.h"
#include <cctype>

using std::string;
using std::cout;
using std::vector;
using std::ifstream;

deck::size_type strToNum(string card) {
	char value = card[0];
	char suit = card[1];

	deck::size_type valueNum = 0;
	deck::size_type suitNum = 0;

	switch (value) {
	case '2':
		valueNum = 0;
		break;
	case '3':
		valueNum = 4;
		break;
	case '4':
		valueNum = 8;
		break;
	case '5':
		valueNum = 12;
		break;
	case '6':
		valueNum = 16;
		break;
	case '7':
		valueNum = 20;
		break;
	case '8':
		valueNum = 24;
		break;
	case '9':
		valueNum = 28;
		break;
	case '10':
		valueNum = 32;
		break;
	case 'j':
		valueNum = 36;
		break;
	case 'q':
		valueNum = 40;
		break;
	case 'k':
		valueNum = 44;
		break;
	case 'a':
		valueNum = 48;
		break;
	}

	switch (suit) {
	case 'd':
		suitNum = 1;
		break;
	case 'c':
		suitNum = 2;
		break;
	case 's':
		suitNum = 3;
		break;
	default:
		suitNum = 0;
		break;
	}

	return valueNum + suitNum;
}

vector<string> split(const string& s) {
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size()) {

     while (i != s.size() && isspace(s[i]))
         ++i;

     string_size j = i;

     while (j != s.size() && !isspace(s[j]))
             j++;
         if (i != j) {
             ret.push_back(s.substr(i, j - i));
             i = j;
         }
    }
    return ret;
}

int main(void) {
	ifstream ifs("hands.txt");
	string hand;
	string card;

	deck d;
	strength s;

	while (getline(ifs, hand)) {
		vector<string> cards;
		vector<deck::size_type> cardsNum;

		cards = split(hand.c_str());

		for (vector<string>::size_type i = 0; i != cards.size(); ++i) {
			cardsNum.push_back(strToNum(cards[i]));
		}

		for (vector<deck::size_type>::size_type j = 0; j != cardsNum.size(); ++j) {
			d.toggleCard(cardsNum[j]);
		}

		s.setDeck(d);

		s.calculateStrength();
	}

	getchar();

	return 0;
}