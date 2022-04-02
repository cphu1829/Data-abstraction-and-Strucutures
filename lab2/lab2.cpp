/*
 * Lab 02
 * Charles Phu
 * Alexander Rovner
 *
 * This assignment requires us to simulate two values of currency while working with
 * inherited classes and carefully scanning the user's input.
 */

#include "Currency.h"
#include "Dollar.h"
#include "Pound.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int whole = 0, fraction = 0;
    string input, temp;
    Currency* tempArr[] = { new Dollar(), new Pound() };
    Currency* arr[] = { new Dollar(), new Pound() };


    cout << " == = Currency Simulator == = " << endl;
    cout << "Please enter the following separated by spaces :" << endl;
    cout << "1. Whether you would like to add or subtract currency by entering 'a' or 's'" << endl;
    cout << "2. What kind of currency you would like to update : 'd' for dollar, or 'p' for pound" << endl;
    cout << "3. What number you will be updating the currency amount by, such as '1' or '12.52'" << endl;
    cout << "4. The name of the currency you are updating : 'pound' or 'dollar', matching the type you entered for #2" << endl;
    cout << "If you would like to exit the Currency Simulator Program, enter 'q'.\n" << endl;

    cout << "Starting Currency Values: ";
    arr[1]->print();
    arr[0]->print();

    do {
        getline(cin, input);

        temp = "";
        for (int i = 4; i < input.size(); i++) {
            if (input[i] != '.' && input[i] != ' ') {
                temp += input[i];
            }
            else if (input.find('.') == -1) {
                whole = stoi(temp);
                temp = "";
                break;
            }
            else {
                if (input[i] == '.') {
                    whole = stoi(temp);
                    temp = "";
                }
                else if (input[i] == ' ') {
                    if (temp.size() == 1) {
                        temp += '0';
                    }
                    fraction = stoi(temp);
                    temp = "";
                    break;
                }
            }
        }



        if (input[0] == 'a') {  //if input is a (add)
            if (input[2] == 'd' && input[input.size() - 1] == 'r') {  // if input is d (dollar)
                tempArr[0]->setWhole(whole);// whole number from input
                tempArr[0]->setFraction(fraction);// fraction number from input
                arr[0]->add(*tempArr[0]);
                arr[1]->print();
                arr[0]->print();

            }
            else if (input[2] == 'p' && input[input.size() - 1] == 'd') {
                tempArr[1]->setWhole(whole);
                tempArr[1]->setFraction(fraction);
                arr[1]->add(*tempArr[1]);
                arr[1]->print();
                arr[0]->print();
            }
            else {
                cout << "Invalid addition" << endl;
            }

        }
        else if (input[0] == 's') {
            if (input[2] == 'd' && input[input.size() - 1] == 'r') {
                tempArr[0]->setWhole(whole);
                tempArr[0]->setFraction(fraction);

                if (arr[0]->getFraction() - tempArr[0]->getFraction() < 0 && arr[0]->getWhole() - tempArr[1]->getWhole() - 1 <= 0) {
                    cout << "Invalid subtraction" << endl;
                }
                else {
                    arr[0]->subtract(*tempArr[0]);
                    arr[1]->print();
                    arr[0]->print();
                }


            }
            else if (input[2] == 'p' && input[input.size() - 1] == 'd') {
                tempArr[1]->setWhole(whole);
                tempArr[1]->setFraction(fraction);

                if (arr[1]->getFraction() - tempArr[1]->getFraction() < 0 && arr[1]->getWhole() - tempArr[1]->getWhole() - 1 <= 0) {
                    cout << "Invalid subtraction" << endl;
                }
                else {
                    arr[1]->subtract(*tempArr[1]);
                    arr[1]->print();
                    arr[0]->print();
                }
            }
            else {
                cout << "Invalid subtraction" << endl;
            }

        }

        whole = 0;
        fraction = 0;

    } while (input != "q");

    return 0;
}