/*
 * Lab 02
 * Charles Phu
 * Alexander Rovner
 *
 * This assignment requires us to simulate two values of currency while working with
 * inherited classes and carefully scanning the user's input.
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


/*Algorithm getWhole() and Algorithm getFraction()
 * ===================================================================
 * These algorithms return the value of their corresponding variables: whole and fraction.
 * Pre:
 * Post:
 * Return: integer whole
				OR
		   integer fraction
 * ===================================================================
 *
 * update corresponding variable with the parameter value
 * end getWhole / getFraction
 */
inline int Currency::getWhole() const {
	return whole;
}

inline double Currency::getFraction() const {
	return fraction;
}

/*Algorithm setWhole(num) and Algorithm setFraction(num)
 * ===================================================================
 * These algorithms update the value of their corresponding variables: whole and fraction.
 * Pre:  num - the updated value for the variable
 * Post: whole - an int representing the non-decimal value
 *				OR
 *		 fraction - an int representing the decimal value
 * Return:
 * ===================================================================
 *
 * update corresponding variable with the parameter value
 * end setWhole / setFraction
 */
inline void Currency::setWhole(int num) {
	whole = num;
}

inline void  Currency::setFraction(int num) {
	fraction = num;
}


/*Algorithm add(a)
 * ===================================================================
 * This algorithm adds the existing whole and fraction values to the stored values
 * and adjusts the stored whole and fraction if the fraction would go past 99.
 * Pre: a - a class that is derived from Currency
 * Post:
 * Return:
 * ===================================================================
 *
 * add input whole to class whole
 * if (class fraction and input fraction added together are >= 100)
 *		increase class whole by 1
 *		add input fraction to class value and subtract 100
 * else
 *		add class and input fraction
 * end if
 */
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

/*Algorithm subtract(a)
 * ===================================================================
 * This algorithm subtracts the input whole and fraction values from the stored values
 * and adjusts the stored whole and fraction values if the fraction would become negative.
 * Pre: a - a class that is derived from Currency
 * Post:
 * Return:
 * ===================================================================
 *
 * subtract input whole from class whole
 * if (class fraction subtracted by input fraction would be < 0)
 *		Decrease class whole by 1
 *		subtract input fraction from class fraction and add 100
 * else
 *		subtract input fraction from class fraction
 * end if
 */
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

/*Algorithm isEqual(a)
 * ===================================================================
 * This algorithm compares the stored whole and fraction values with the inputted
 * whole and fraction values, returning true if they are equal and false otherwise.
 * Pre: a - a class that is derived from Currency
 * Post:
 * Return: true or false
 * ===================================================================
 *
 * if (class whole is equal to input whole AND class fraction is equal to input fraction)
 *		return true
 * else
 *		return false
 * end if
 */
inline bool Currency::isEqual(Currency& a) {
	if (this->getWhole() == a.getWhole() && this->getFraction() == a.getFraction()) {
		return true;
	}
	else {
		return false;
	}
}

/*Algorithm isGreater(a)
 * ===================================================================
 * This algorithm compares the stored whole and fraction values with the
 * inputted whole and fraction values, returning true if the class values
 * are greater and false otherwise.
 * Pre: a - a class that is derived from Currency
 * Post:
 * Return: true or false
 * ===================================================================
 *
 * if (class whole > input whole)
 *		return true
 * else if (class whole is equal to input whole AND class fraction > input fraction)
 *		return true
 * else
 *		return false
 * end if
 */
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

#pragma once
