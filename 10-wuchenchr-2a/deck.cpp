//DECK CPP FILE

#include "deck.h"
#include "card.h"
#include "d_node.h"
#include <iostream>
#include <stdexcept>
#include <ctime>

// deletes all nodes in the linked list
void Deck::clear()
{
	while (head) // loops until the list is empty
	{
		Node* t = head->next; // saves the next node
		delete head; // deletes the current node
		head = t; // move head to next node
	}
}

// adds a new card at the end of the linked list
void Deck::append(const card& c)
{
	Node* n = new Node(c); // creates a new node with this card

	if (!head) // checks that if the list is empty, makes the new node the head
	{
		head = n;
		return;
	}

	// else find the last node
	Node* p = head;
	while (p->next) {
		p = p->next;
	}

	p->next = n; // links the new node at the end
}

// builds the deck in order: from A to K and suits (C, D, H, S)
Deck::Deck() : head(nullptr)
{
	const char suits[4] = { 'C', 'D', 'H', 'S' }; // represents the all suits
	const char ranks[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' }; // represents all ranks

	for (char s : suits)
	{
		for (char r : ranks)
		{
			append(card(s, r));
		}
	}
}

// destructor to clear all nodes
Deck::~Deck()
{
	clear();
}

// randomizes the order of the cards in the deck
void Deck::shuffle()
{
	// seed for random value
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
		seeded = true;
	}

	// copies linked list to a vector
	std::vector<card> v;
	for (Node* p = head; p; p = p->next) {
		v.push_back(p->data);
	}

	// shuffles using rand() and swaps them
	for (int i = static_cast<int>(v.size()) - 1; i > 0; --i) {
		int j = std::rand() % (i + 1);  // random index from 0 to i

		// swapping
		card temp = v[i];
		v[i] = v[j];
		v[j] = temp;
	}

	// deletes old linked list
	clear();

	// rebuilds deck from the obtained shuffled vector
	for (const auto& c : v) {
		append(c);
	}

}

// overload "<<" operator to print all the cards in the deck (13 cards per line)
std::ostream& operator<<(std::ostream& os, const Deck& d) {
	const Deck::Node* p = d.head;
	int count = 0;

	while (p) {
		os << p->data;// prints card (uses Card's operator<<)
		count++;// increases the count

		if (count % 13 == 0) // makes a newline every 13 cards
			os << '\n';
		else
			os << ' ';

		p = p->next; // moves to next card
	}

	if (count % 13 != 0) os << '\n';
	return os;
}