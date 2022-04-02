// lab02fixed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
    Currency* arr[] = { new Dollar(), new Pound()};

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
            if (input[2] == 'd' && input[input.size()-1] == 'r') {  // if input is d (dollar)
                tempArr[0]->setWhole(whole);// whole number from input
                tempArr[0]->setFraction(fraction);// fraction number from input
                arr[0]->add(*tempArr[0]);
                arr[1]->print();
                arr[0]->print();

            }
            else if (input[2] == 'p' && input[input.size()-1] == 'd') {
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
