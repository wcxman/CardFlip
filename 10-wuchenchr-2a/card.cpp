#include "card.h"
#include <stdexcept>
#include <iostream>

	//Constructor, takes characters representing suit and value
	card::card(char card_suit, char card_value)
	{
		setSuit(card_suit);
		setVal(card_value);
	}

	//Constructor with integer card_value (cannot input A, J, Q, K)
	card::card(char card_suit, int card_value)
	{
		setSuit(card_suit);
		setVal(card_value);
	}

	//Copy Constructor
	card::card(const card& copied)
	{
		suit = copied.suit;
		val = copied.val;
	}

	//Sets the card's suit to the user's input if valid
	void card::setSuit(char card_suit) 
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
	}

	//Sets the card's value to the user's char input if valid
	void card::setVal(char card_value) 
	{
		if (card_value > 49 && card_value < 58) //Range of 2-9 in ASCII
		{
			val = card_value;
		}
		else switch (card_value) {
		case 't':
		case 'T':
			val = 'T';
			break;
		case 'j':
		case 'J':
			val = 'J';
			break;
		case 'q':
		case 'Q':
			val = 'Q';
			break;
		case 'k':
		case 'K':
			val = 'K';
			break;
		case 'a':
		case 'A':
			val = 'A';
			break;
		default:
			throw std::invalid_argument("Invalid value character");
		}
	}

	//Sets the card's value to the user's int input if valid
	void card::setVal(int card_value)
	{
		if (card_value > 1 && card_value < 10) {
			val = '0' + card_value;
		}
		else if (card_value == 10) {
			val = 'T';
		}
		else throw std::invalid_argument("Invalid value integer");
	}

	//Returns the suit of the card
	char card::getSuit()
	{
		return suit;
	}

	//Returns the value of the card (always char)
	char card::getValue()
	{
		return val;
	}

	//Overloads << operator
	std::ostream& operator<<(std::ostream& os, const card& c)
	{
		return os << c.suit << c.val;
	}

	//Overloads assignment operator
	card& card::operator=(const card& c)
	{
		if (this != &c) {
			suit = c.suit;
			val = c.val;
			return *this;
		}
		
	}