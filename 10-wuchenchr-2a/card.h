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
		//Constructor 
		card(char card_suit, char card_value);

		card(char card_suit, int card_value);

		void setSuit(char card_suit);

		void setVal(char card_value);

		void setVal(int card_value);

		char getSuit();

		char getValue();

		friend std::ostream& operator<<(std::ostream& os, const card& c);

};




#endif
