/* Lab 2
 *
 * Charles Phu
 * Alexander Rovner
 *
 * WIP
 * This assignment involves our creation of a Currency Simulator
 * by using an abstract Currency class and deriving from it.
 * WIP
*/
#include <iostream>
using namespace std;

class Currency {
public:
	Currency();
	Currency(double n);
	Currency(const Currency& other) {
		whole = other.whole;
		fraction = other.fraction;
	}
	virtual ~Currency() = 0;

	//getters and setters
	int getWhole() const;
	double getFraction() const;
	void setWhole(int num);
	void setFraction(int num);

	//functions 
	virtual void add(const Currency& a);
	void subtract(Currency& a);
	bool isEqual(Currency& a);
	bool isGreater(Currency& a);
	virtual void print() = 0;

private:
	int whole;
	int fraction;
};

inline Currency::Currency() {
	whole = 0;
	fraction = 0;
}

Currency::Currency(double n) {
	whole = (int)ceil(n);
	fraction = (n - whole) * 100;
}

Currency::~Currency() {}

inline int Currency::getWhole() const {
	return whole;
}

inline double Currency::getFraction() const {
	return fraction;
}

inline void Currency::setWhole(int num) {
	whole = num;
}

inline void  Currency::setFraction(int num) {
	fraction = num;
}

void Currency::add(const Currency& a) {
	this->setWhole(this->getWhole() + a.getWhole());

	if (this->getFraction() + a.getFraction() >= 100) {
		this->setWhole(this->getWhole() + 1);
		this->setFraction(this->getFraction() + a.getFraction() - 100);
	}
	else {
		this->setFraction(this->getFraction() + a.getFraction());
	}
}

inline void Currency::subtract(Currency& a) {
	this->setWhole(this->getWhole() - a.getWhole());

	if (this->getFraction() - a.getFraction() < 0) {
		this->setWhole(this->getWhole() - 1);
		this->setFraction(this->getFraction() - a.getFraction() + 100);
	}
	else {
		this->setFraction(this->getFraction() - a.getFraction());
	}
}

inline bool Currency::isEqual(Currency& a) {
	if (this->getWhole() == a.getWhole() && this->getFraction() == a.getFraction()) {
		return true;
	}
	else {
		return false;
	}
}

inline bool Currency::isGreater(Currency& a) {
	if (this->getWhole() > a.getWhole()) {
		return true;
	}
	else if (this->getWhole() == a.getWhole() && this->getFraction() > a.getFraction()) {
		return true;
	}
	else {
		return false;
	}
}

/*
bool operator==(const Currency& lhs, const Currency& rhs) {
	if (lhs.getWhole() == rhs.getWhole() && lhs.getFraction() == rhs.getFraction()) {
		return true;
	}
	else {
		return false;
	}

}

bool operator>(const Currency& lhs, const Currency& rhs) {
	if (lhs.getWhole() > rhs.getWhole()) {
		return true;
	}
	else if (lhs.getWhole() == rhs.getWhole() && lhs.getFraction() > rhs.getFraction()) {
		return true;
	}
	else {
		return false;
	}
}*/#pragma once
