/*
 * Lab 02
 * Charles Phu
 * Alexander Rovner
 *
 * This assignment requires us to simulate two values of currency while working with
 * inherited classes and carefully scanning the user's input.
 */
#pragma once
#include "Currency.h"
#include <iostream>
using namespace std;

class Pound : public Currency {
public:
	Pound() : Currency() {};
	Pound(double n) : Currency(n) {};
	~Pound() override {};

	void print();
private:
	string name = "Pound";
};

/*Algorithm print ()
 * ===================================================================
 * This algorithm uses methods from the Currency class to output the
 * the stored Pound value.
 * Pre:
 * Post:
 * Return:
 * ===================================================================
 *
 * Output pound value and name by referencing methods in Currency
 */
void Pound::print() {
	cout << this->getWhole() << "." << this->getFraction() << " " << name << " ";
}
