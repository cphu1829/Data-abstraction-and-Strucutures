/*
 * Lab 05
 * Charles Phu
 * Alexander Rovner
 *
 * This assignment requires us to implement a hash table,
 * resolve collisions using quadratic probing, and allow
 * users to search the hash table.
 */

#include "currency.h"
#include "dollar.h"
#include <iostream>
#include <string>
#include "Hash.h"

#pragma once
using namespace std;

int main()
{
    Currency* seedData[20] = {
        new Dollar(57.12),
        new Dollar(23.44),
        new Dollar(87.43),
        new Dollar(68.99),
        new Dollar(111.22),
        new Dollar(44.55),
        new Dollar(77.77),
        new Dollar(18.36),
        new Dollar(543.21),
        new Dollar(20.21),
        new Dollar(345.67),
        new Dollar(36.18),
        new Dollar(48.48),
        new Dollar(101.00),
        new Dollar(11.00),
        new Dollar(21.00),
        new Dollar(51.00),
        new Dollar(1.00),
        new Dollar(251.00),
        new Dollar(151.00)
    };
    Hash* hashtable = new Hash();


    for (int i = 0; i < 20; i++) {
        hashtable->insert(seedData[i]);
    }
    cout << "Data seeeded" << endl;
    cout << "Data items loaded: " << hashtable->getItemsLoaded() << endl;
    cout << "Load factor: " << hashtable->getLoadFactor() << endl;
    cout << "Numer of collisoins: " << hashtable->getCollisions() << endl;

    cout << "\n 'q' to stop program" << endl << endl;
    string userInput = "";
    do {
        cout << "Enter Dollar value: ";
        cin >> userInput;
        try {
            double tempInt = stod(userInput);
            Dollar* temp = new Dollar(tempInt);
            int index = hashtable->search(temp);
            if (index != -1) {
                cout << "Item found at index: " << index << endl;
            }
            else {
                cout << "Item not found" << endl;
            }

        }
        catch (std::invalid_argument) {
            cout << "Invalid Dollar value" << endl;
        }

    } while (userInput != "q");



    /*
    Currency* DollarArray[20] = {
        new Dollar(57.12),
        new Dollar(23.44),
        new Dollar(87.43),
        new Dollar(68.99),
        new Dollar(111.22),
        new Dollar(44.55),
        new Dollar(77.77),
        new Dollar(18.36),
        new Dollar(543.21),
        new Dollar(20.21),
        new Dollar(345.67),
        new Dollar(36.18),
        new Dollar(48.48),
        new Dollar(101.00),
        new Dollar(11.00),
        new Dollar(21.00),
        new Dollar(51.00),
        new Dollar(1.00),
        new Dollar(251.00),
        new Dollar(151.00)
    };
    BST* bst = new BST();
    for (int i = 0; i < 20; i++) {
        bst->insert(DollarArray[i]);
    }

    std::fstream outFS;
    outFS.open("traversal.txt", std::ios::out);
    outFS.close();

    

    outFS.open("traversal.txt", std::ios::app);
    outFS << "Breadth first traversal" << endl;
    outFS.close();
    cout <<  "\n\nBreadth first Traversal" << endl;
    cout << bst->BreadthFirstTraversal(bst->getRoot());
    outFS.open("traversal.txt", std::ios::app);
    outFS << "In-Order Traversal" << endl;
    outFS.close();
    
    cout <<  "\nIn-Order Traversal" << endl;
    bst->InorderTraversal(bst->getRoot());
    outFS.open("traversal.txt", std::ios::app);
    outFS << endl << "Pre-Order Traversal" << endl;
    outFS.close();
    
    cout << "\n\nPre-Order Traversal" << endl;
    bst->PreorderTraversal(bst->getRoot());
    outFS.open("traversal.txt", std::ios::app);
    outFS << endl << "Post-Order Traversal" << endl;
    outFS.close();

    cout << "\n\nPost-Order Traversal" << endl;
    bst->PostorderTraversal(bst->getRoot());
  
    
    
    
    string next = "";
    bool go = true;
    do{
        cout << "Would you like to:" << endl << "\ta - add a node" << endl
            << "\tb - search for a Dollar value" << endl << "\tc - delete a node."
            << endl << "\td - print traversal output or" << endl
            << "\te - exit the program" << endl << endl;

        cin >> next;
        if(next.compare("a") == 0 ){
           cout << endl << "Please enter the Dollar value you would like to add to the Binary Search Tree." << endl;
           cin >> next;
           double tempInt;
           try {
               tempInt = stod(next);
               Dollar* temp = new Dollar(tempInt);
               bst->insert(temp);
               cout << "Dollar value added" << endl;
           }
           catch(std::invalid_argument){
               cout << next << " input was invalid and ignored." << endl << endl;
            
               outFS.open("traversal.txt", std::ios::out);
               outFS << next << " input was invalid and ignored." << endl << endl;

               outFS.close();
           }
           next = "";
        }
        else if(next.compare("b") == 0 ){
           cout << endl << "Please enter the Dollar value you would like to search for in the Binary Search Tree." << endl;
           cin >> next;
           double tempInt;
           try {
               tempInt = stod(next);
               Dollar* temp = new Dollar(tempInt);
               BSTNode* tempBST = bst->search(temp, bst->getRoot());
               if (tempBST != nullptr) {
                   cout << "Found dollar value" << endl;
               }
               else {
                   cout << "Item not found" << endl;
               }
           }
           catch(std::invalid_argument){
               cout << next << " input was invalid and ignored." << endl << endl;
            
               outFS.open("traversal.txt", std::ios::out);
               outFS << next << " input was invalid and ignored." << endl << endl;

               outFS.close();
           }
           next = "";
        }
        else if(next.compare("c") == 0 ){
           cout << endl << "Please enter the Dollar value you would like to remove from the Binary Search Tree." << endl;
           cin >> next;
           double tempInt;
           try{
               tempInt = stod(next);
               Dollar* temp = new Dollar(tempInt);
               BSTNode* tempBST = bst->search(temp, bst->getRoot());
               if (tempBST != nullptr) {
                    bst->deleteNode(bst->getRoot(), temp);
                    cout << "Node deleted" << endl;
               }
               else {
                   cout << "Item not found, hence not deleted" << endl;
               }
           }
           catch(std::invalid_argument){
               cout << next << " input was invalid and ignored." << endl << endl;
            
               outFS.open("traversal.txt", std::ios::out);
               outFS << next << " input was invalid and ignored." << endl << endl;

               outFS.close();
           }
           next = "";
       }
       else if(next.compare("d") == 0 ){
            cout << endl << "Traversal output will now be printed." << endl << endl;
            next = "";

            cout <<  "\n\nBreadth first Traversal" << endl << endl;
            bst->BreadthFirstTraversal(bst->getRoot());

            cout <<  "In-Order Traversal" << endl;
            bst->InorderTraversal(bst->getRoot());
    
            cout << "\n\nPre-Order Traversal" << endl;
            bst->PreorderTraversal(bst->getRoot());
    
            cout << "\n\nPost-Order Traversal" << endl;
            bst->PostorderTraversal(bst->getRoot());
       }
       else if(next.compare("e") == 0 ){
           cout << endl << "You chose to exit the program. Enjoy a final printing of the traversal output." << endl << endl;
           go = false;
           next = "";
 
           cout <<  "\n\nBreadth first Traversal" << endl << endl;
           bst->BreadthFirstTraversal(bst->getRoot());

           cout <<  "In-Order Traversal" << endl;
           bst->InorderTraversal(bst->getRoot());
   
           cout << "\n\nPre-Order Traversal" << endl;
           bst->PreorderTraversal(bst->getRoot());
   
           cout << "\n\nPost-Order Traversal" << endl;
           bst->PostorderTraversal(bst->getRoot());
       }
       else{
            cout << next << " input was invalid and ignored." << endl << endl;
            
            outFS.open("traversal.txt", std::ios::out);
            outFS << next << " input was invalid and ignored." << endl << endl;

            outFS.close();
       }
    } while (go != false);
    */
    /*
    Currency* currencyArray[20] = {
        new Dollar(57.12),
        new Dollar(23.44),
        new Dollar(87.43),
        new Dollar(68.99),
        new Dollar(111.22),
        new Dollar(44.55),
        new Dollar(77.77),
        new Dollar(18.36),
        new Dollar(543.21),
        new Dollar(20.21),
        new Dollar(345.67),
        new Dollar(36.18),
        new Dollar(48.48),
        new Dollar(101.00),
        new Dollar(11.00),
        new Dollar(21.00),
        new Dollar(51.00),
        new Dollar(1.00),
        new Dollar(251.00),
        new Dollar(151.00)
    };

    cout << "\n\nLinked List class: ";
    SinglyLinkedList* LinkedList = new SinglyLinkedList();
    for (int i = 0; i < 7; i++) {
        LinkedList->addCurrency(currencyArray[i], 0);
    }

    cout << "\nIndex of 87.43 is ";
    cout << LinkedList->findCurrency(new Dollar(87.43)) << endl; 
    cout << "Index of 44.55 is ";
    cout << LinkedList->findCurrency(new Dollar(44.55)) << endl;

    LinkedList->removeCurrency(new Dollar(111.22));
    LinkedList->removeCurrency(2); 

    cout << LinkedList->printList() << endl;

    for (int i = 8; i < 11; i++) {      // objects #9-12 corrolate to 8-11 in array since indexing starts at 0
        LinkedList->addCurrency(currencyArray[i], i % 5);
    }

    cout << LinkedList->printList() << endl;

    LinkedList->removeCurrency(LinkedList->countCurrency() % 6);
    LinkedList->removeCurrency(LinkedList->countCurrency() / 7);
    cout << LinkedList->printList();

    cout << "\n\nStack class" << endl;
    Stack* stack = new Stack();
    for (int i = 13; i < 20; i++) {
        stack->push(currencyArray[i]);
    }

    cout << "Top of the stack: ";
    stack->peek()->print();
    stack->pop();
    stack->pop();
    stack->pop();
    cout << stack->printStack() << endl;

    for (int i = 0; i < 5; i++) {
        stack->push(currencyArray[i]);
    }
    stack->pop();
    stack->pop();
    cout << stack->printStack();

    cout << "\n\nQueue class" << endl;

    Queue* queue = new Queue();
    for (int i = 5; i < 19; i = i +2) {
        queue->enqueue(currencyArray[i]);
    }

    cout << "Front of Queue ";
    queue->peekFront()->print();
    cout << "Back of Queue ";
    queue->peekRear()->print();
    queue->dequeue();
    queue->dequeue();
    cout << queue->printQueue() << endl;


    for (int i = 10; i < 15; i++) {
        queue->enqueue(currencyArray[i]);
    }
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    cout << queue->printQueue() << endl << endl;

    cout << "This is the end of our ADT demonstration.";
    delete queue;
    delete stack;
    delete LinkedList;

    /*
    Currency* temp = new Dollar();
    temp->setFraction(10);
    temp->setWhole(12);
    Currency* temp1 = new Dollar();
    temp1->setFraction(110);
    temp1->setWhole(69);

    LinkedList->addCurrency(temp, 0);
    LinkedList->addCurrency(new Dollar(10.24), 1);
    LinkedList->printList();
    LinkedList->removeCurrency(0);
    LinkedList->printList();
    */
    /*
    * OLD LAB
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
        for (size_t i = 4; i < input.size(); i++) {
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

            }
            else if (input[2] == 'p' && input[input.size() - 1] == 'd') {
                tempArr[1]->setWhole(whole);
                tempArr[1]->setFraction(fraction);
                arr[1]->add(*tempArr[1]);
            }
            else {
                cout << "Invalid addition" << endl;
            }
            arr[1]->print();
            arr[0]->print();

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
                }
            }
            else {
                cout << "Invalid subtraction" << endl;
            }
            arr[1]->print();
            arr[0]->print();
        }

        whole = 0;
        fraction = 0;

    } while (input != "q");
    */
    return 0;
}

