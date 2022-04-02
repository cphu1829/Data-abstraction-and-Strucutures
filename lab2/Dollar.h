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

class Dollar : public Currency {
public:
	Dollar() : Currency() {};
	Dollar(double n) : Currency(n) {};
	~Dollar() override {};

	void add(const Dollar& a);

	void print();
private:
	string name = "Dollar";
};


/*Algorithm print ()
 * ===================================================================
 * This algorithm uses methods from the Currency class to output the
 * the stored Dollar value.
 * Pre:
 * Post:
 * Return:
 * ===================================================================
 *
 * Output dollar value and name by referencing methods in Currency
 */
void Dollar::print() {
	cout << this->getWhole() << "." << this->getFraction() << " " << name << endl;
}


