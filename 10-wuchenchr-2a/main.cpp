#include "card.h"
#include <stdexcept>
#include <iostream>
using namespace std;

//Main cpp file

//Test: Card setting, printing

int main() {
	try {
		card charCard = card('S', 'A');
		card intCard = card('S', 10);
		cout << charCard << " " << intCard;
		charCard.setSuit('d');
		intCard.setVal(2);
		cout << endl << charCard << " " << intCard;
		charCard.setVal(10);
		intCard.setSuit('~');
	}
	catch (std::invalid_argument e) {
		cout << e.what();
	}

	return 0;
}