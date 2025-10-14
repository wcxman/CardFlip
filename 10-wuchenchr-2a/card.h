//card header
#ifndef CARD_H
#define CARD_H
#include <stdexcept>
#include <iostream>



class card
{
	private:
		char suit;
		char val;

	public: 
		//Constructor, takes characters representing suit and value
		card(char card_suit, char card_value);

		//Constructor with integer card_value (cannot input A, J, Q, K)
		card(char card_suit, int card_value);

		//Sets the card's suit to the user's input if valid
		void setSuit(char card_suit);

		//Sets the card's value to the user's char input if valid
		void setVal(char card_value);

		//Sets the card's value to the user's int input if valid
		void setVal(int card_value);

		//Returns the suit of the card
		char getSuit();

		//Returns the value of the card (always char)
		char getValue();

		//Overloads << operator, printing suit and then value
		friend std::ostream& operator<<(std::ostream& os, const card& c);

};




#endif
