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

void Pound::print() {
	cout << this->getWhole() << "." << this->getFraction() << " " << name << " ";
}
