#include "card.h"
#include <stdexcept>

class card
{
private:
	char suit;
	char val;

public:
	//Constructor 
	card(char card_suit, char card_value)
	{
		switch (card_suit) {
		case 'h':
		case 'H':
			suit = 'H';
			break;

		case 'd':
		case 'D':
			suit = 'D';
			break;

		case 'c':
		case 'C':
			suit = 'C';
			break;

		case 's':
		case 'S':
			suit = 'S';
			break;
		default:
			throw std::invalid_argument("Invalid suit character");
		}
		//TO IMPLEMENT: Card Value switch case
	}
};