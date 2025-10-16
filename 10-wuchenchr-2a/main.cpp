#include "card.h"
#include "deck.h"
#include <stdexcept>
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

//Main cpp file

//Test: Card setting, printing

int main() {
	try {
		Deck mydeck = Deck();
		cout << mydeck;
		mydeck.shuffle();
		cout << endl << mydeck << endl;
		cout << mydeck.deal().data;
		cout << endl << mydeck;
	}
	catch (std::invalid_argument e) {
		cout << e.what();
	}

	return 0;
}