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

void Dollar::print() {
	cout << this->getWhole() << "." << this->getFraction() << " " << name << endl;
}


