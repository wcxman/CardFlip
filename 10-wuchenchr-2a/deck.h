//DECK CLASS HEADER

#ifndef DECK_H
#define DECK_H
#include "card.h"
#include "d_node.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <random>

// represents a deck of cards
class Deck
{
private:
	// node strcuture that represents one card in the single linked list node
	struct Node {
		card data;
		Node* next;
		// constructor to initialize data and the next pointer
		Node(const card& c, Node* n = nullptr) : data(c), next(n) {}
	};

	Node* head; // pointer to the first coard that is on the deck

	void clear(); // deletes nodes
	void append(const card& c); // appends at the tail of the list (keeps the order)

public:
	Deck(); // builds 52 cards in order (from A to K, and suits C,D,H,S)
	~Deck(); // frees memory (destructor)

	// randomizes the order of the cards
	void shuffle();

	// returns ture if the deck is empty
	bool empty() const
	{
		return head == nullptr;
	}

	//Removes the top node of the deck and returns it
	Node deal();

	// Overload the "<<" so we can print the entire deck easily
	// Example: "cout << d;" instead of "d.printDeck();"
	friend std::ostream& operator<<(std::ostream& os, const Deck& d);
};

#endif
