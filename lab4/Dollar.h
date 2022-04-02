/*
 * Lab 02
 * Charles Phu
 * Alexander Rovner
 *
 * This assignment requires us to simulate two values of currency while working with
 * inherited classes and carefully scanning the user's input.
 */
#pragma once
#include "currency.h"
#include <iostream>
#include <string>

class Dollar : public Currency {
public:
	Dollar() : Currency() {};
	Dollar(double n) : Currency(n) {};

	void add(const Dollar& a); 
	void subtract(const Dollar& a); 
	std::string getPrintStatement(); // new code, returns a string of the print statement to make it easier to write to files
	std::string getName();
	void print();

private:
	std::string name = "Dollar";
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
	// changed print function in order to print .00
	if (this->getFraction() < 10) {
		std::cout << this->getWhole() << ".0" << this->getFraction() << " " << name << std::endl;
	}
	else {
		std::cout << this->getWhole() << "." << this->getFraction() << " " << name << std::endl;
	}
}


void Dollar::add(const Dollar& a) {
	this->setWhole(this->getWhole() + a.getWhole());

	if (this->getFraction() + a.getFraction() >= 100) {
		this->setWhole(this->getWhole() + 1);
		this->setFraction(this->getFraction() + a.getFraction() - 100);
	}
	else {
		this->setFraction(this->getFraction() + a.getFraction());
	}
}

void Dollar::subtract(const Dollar& a) {
	this->setWhole(this->getWhole() - a.getWhole());

	if (this->getFraction() - a.getFraction() < 0) {
		this->setWhole(this->getWhole() - 1);
		this->setFraction(this->getFraction() - a.getFraction() + 100);
	}
	else {
		this->setFraction(this->getFraction() - a.getFraction());
	}
}

std::string Dollar::getName() {
	return name;
}

//new code
std:: string Dollar::getPrintStatement() {
	std::string temp = "";
	if (this->getFraction() < 10) {
		temp = std::to_string(this->getWhole()) + ".0" + std::to_string(this->getFraction()) + " " + name;
	}
	else {
		temp = std::to_string(this->getWhole()) + "." + std::to_string(this->getFraction()) + " " + name;
	}

	return temp;
}

