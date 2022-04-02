/*
 * Lab 03
 * Charles Phu
 * Alexander Rovner
 *
 * This assignment requires us to implement Linked Lists as well as Stack
 * and Queue ADTs that are derived from Linked Lists.
 */

#include "LinkedNode.h"
#include "Currency.h"
#include <string>
#pragma once

class SinglyLinkedList {
public:
	SinglyLinkedList();
	void addCurrency(Currency* data, int index);
	void removeCurrency(Currency* data);
	void removeCurrency(int index);

	int findCurrency(Currency* data);
	Currency* getCurrency(int index);
	std::string printList();
	bool isListEmpty();
	int countCurrency();

	LinkedNode* getStart();
	LinkedNode* getEnd();
protected:
	int count;
	LinkedNode* start;
	LinkedNode* end;
};

SinglyLinkedList::SinglyLinkedList() {
	start = nullptr;
	end = nullptr;
	count = 0;
}

/*Algorithm addCurrency(Currency* data, int index)
 * ===================================================================
 * This algorithm adds a new Currency object to the given index of the LinkedList.
 * Pre: Currency* data - a referance to a Currency object
 *		index - an integer that informs where the data object should be added
 * Post: a new LinkedNode with the value of Currency* data has been added to the LinkedList at the provided index
 * Return:
 * ===================================================================
 *
 * update LinkedNode* values and set data to a temp LinkedNode
 * if(LinkedList start is null)
 *		set the temp LinkNode as start and end
 * else if(index is 0)
 *		set the temp LinkNode as start and setNext() LinkNode after start as current
 * else
 *		loop through each LinkNode and update pre and current accordingly until index has been reached
 *		pre->setNext(temp)
 *		temp->setNext(current)
 *	end if
 */
void SinglyLinkedList::addCurrency(Currency* data, int index) {
	LinkedNode* pre = new LinkedNode();
	LinkedNode* current = start;
	LinkedNode* temp = new LinkedNode(data);

	if (start == nullptr) {
		start = temp;
		end = temp;
	}
	else if (index == 0) {
		start = temp;
		start->next = current;
		count++;
	}
	else {
		for (int i = 0; i <= index; i++) {
			pre = current;
			current = current->next;
		}
		pre->next = temp;
		temp->next = current;
		count++;
	}



}


/*Algorithm getStart() and Algorithm getEnd()
 * ===================================================================
 * These algorithms return the value of their corresponding variables: start and end.
 * Pre:
 * Post:
 * Return: LinkedNode* start
				OR
		   LinkedNode* end
 * ===================================================================
 *
 * update corresponding variable with the parameter value
 * end getStart / getEnd
 */
LinkedNode* SinglyLinkedList::getStart() {
	return start;
}

LinkedNode* SinglyLinkedList::getEnd() {
	return end;
}


/*Algorithm removeCurrency(Currency* data)
 * ===================================================================
 * This algorithm removes a Currency object from the LinkedList that is equal to the given currency object.
 * Pre: Currency* data - an inputted currency object to be removed
 * Post: a LinkNode with a currency object equal to Currency* data has been removed from the LinkedList
 * Return:
 * ===================================================================
 *
 * update LinkedNode* values and set data to a temp LinkedNode
 * if(LinkedList start and end are equal to data)
 *		set start and end to null
 * else
 *		while the next LinkNode after current is not null
			change pre and current to loop through the LinkedList
 *			if(the data of current is equal to data)
				set the next LinkNode of pre to the node after current
			end if
		end loop
 *	end if
 */
void SinglyLinkedList::removeCurrency(Currency* data) {
	LinkedNode* pre = new LinkedNode();
	LinkedNode* current = start;
	LinkedNode* temp = new LinkedNode(data);

	if (start == temp && end == temp) {
		start = nullptr;
		end = nullptr;
		count = 0;
	}
	else {

		while (current->next != nullptr) {
			pre = current;
			current = current->next;

			if (current->data->isEqual(*data)) {
				//delete start->next;
				pre->next = current->next;
			}

		}
		count--;
	}

}

/*Algorithm removeCurrency(int index)
 * ===================================================================
 * This algorithm removes the LinkNode at the value of index in the LinkedList.
 * Pre: int index - an inputted int specifying the location of a LinkNode in the LinkedList
 * Post: a LinkNode at the provided index has been removed from the LinkedList
 * Return:
 * ===================================================================
 *
 * update LinkedNode* pre and current values
 * if(index is 0 and the LinkNode after start is null)
 *		set start and end to null
 * else if(index is 0 and the LinkNode after start is not null)
 *		create a temp LinkNode that is equal to the LinkNode after start
 *		set start to the temp LinkNode
 * end if
 *
 * loop until the value before the index is reached
 *		set pre to current
 *		set current as next LinkNode after current
 * end loop
 * set LinkNode after pre as the LinkNode after current
 *
 */
void SinglyLinkedList::removeCurrency(int index) {
	LinkedNode* pre = new LinkedNode();
	LinkedNode* current = start;

	if (index == 0 && start->next == nullptr) {
		start = nullptr;
		end = nullptr;
		count = 0;
	}
	else if (index == 0 && start->next != nullptr) {
		LinkedNode* temp = start->next;
		//delete start;
		start = temp;
		
	}

	for (int i = 0; i < index - 1; i++) {
		pre = current;
		current = current->next;
	}

	pre->next = current->next;
	count--;
	//delete current;

}

/*Algorithm countCurrency()
 * ===================================================================
 * This algorithm counts how many LinkNodes with currency values are in the LinkedList.
 * Pre:
 * Post:
 * Return: temp - an integer with the total number of non-null LinkNodes in the LinkedList
 * ===================================================================
 *
 * create a LinkedNode* counter equal to the start LinkedNode
 * create an int variable temp to count how many non-null LinkedNodes exist in the LinkedList
 * if(LinkedList is not empty)
 *		increment temp
 * end if
 * loop while LinkNode after counter is not null
 *		increment temp
 *		set counter to be the LinkNode after counter
 * end loop
 * return temp
 *
 */
int SinglyLinkedList::countCurrency() {
	LinkedNode* counter = start;
	int temp = 0;
	if (!isListEmpty()) {
		temp++;
	}

	while (counter->next != nullptr) {
		temp++;
		counter = counter->next;
	}
	return temp;
}


/*Algorithm printList()
 * ===================================================================
 * This algorithm outputs the data contents of the LinkedList.
 * Pre:
 * Post:
 * Return:
 * ===================================================================
 *
 * create a LinkedNode* counter equal to the start LinkedNode
 * if(LinkedList is empty)
 *		output that the "List is empty"
 * else
 *		loop through the amount of non-null LinkNodes in the LinkedList
 *			get the data of the counter LinkedNode and print it
 *			set the counter to be the LinkedNode after counter
 *		end loop
 * end if
 *
 */
std::string SinglyLinkedList::printList() {
	LinkedNode* counter = start;
	Currency* temp;
	std::string contents = "";

	if (start == nullptr && end == nullptr) {
		return "List is empty\n";
	}
	else {
		do {
			temp = counter->data;

			if (temp->getFraction() < 10) {
				contents.append(std::to_string(temp->getWhole()) + ".0" + std::to_string((int)(temp->getFraction())) + " " + temp->getName() + "\t");
			}
			else {
				contents.append(std::to_string(temp->getWhole()) + "." + std::to_string((int)(temp->getFraction())) + " " + temp->getName() + "\t");
			}
			counter = counter->next;
		} while (counter->next != nullptr);
		temp = counter->data;
		contents.append(std::to_string(temp->getWhole()) + "." + std::to_string((int)(temp->getFraction())) + " " + temp->getName() + "\t");

	}
	return contents;
}

/*Algorithm isListEmpty()
 * ===================================================================
 * This algorithm checks if the LinkedList has non-null LinkedNodes.
 * Pre:
 * Post:
 * Return: bool true
 *			OR
 *		   bool false
 * ===================================================================
 *
 * if(start is null AND end is null)
 *		return true
 * else
 *		return false
 *
 */
bool SinglyLinkedList::isListEmpty() {
	if (start == nullptr && end == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

/*Algorithm findCurrency(Currency* data)
 * ===================================================================
 * This algorithm checks if the LinkedList has non-null LinkedNodes.
 * Pre:
 * Post:
 * Return: temp - int that contains the first appearance of currency object data in the LinkedList
 *				OR
 *		   -1 - int that is returned if currency object data is not present in the LinkedList
 * ===================================================================
 *
 * create a LinkedNode* counter equal to the start LinkedNode
 * create an int variable temp to count what is the current index
 * if(LinkedList is empty)
 *		return -1
 * end if
 * loop until all non-null values of the LinkedList have been checked
 *		if(data of counter is equal to data)
 *			return temp
 *		else
 *			increment temp
 *		end if
 *		set counter to LinkNode after counter
 * end loop
 *
 */
int SinglyLinkedList::findCurrency(Currency* data) {
	LinkedNode* counter = start;
	int temp = 0;
	if (isListEmpty()) {
		return -1;
	}

	for (int i = 0; i < countCurrency(); i++) {
		if (counter->data->isEqual(*data)) {
			return temp;
		}
		else {
			temp++;
		}
		counter = counter->next;
	}
}

/*Algorithm getCurrency(int index)
 * ===================================================================
 * This algorithm returns the value of currency object at the corresponding index.
 * Pre: index - an int specifying a specific location in the LinkedList
 * Post:
 * Return: counter->getData() - the value of the LinkNode's currency object at the given index
 * ===================================================================
 *
 * create a LinkedNode* counter equal to the start LinkedNode
 * create an int variable temp to count what is the current index
 * loop until index has been surpassed
 *		update counter to be the next value
 * end loop
 * return data from counter
 */
Currency* SinglyLinkedList::getCurrency(int index) {
	LinkedNode* counter = start;
	int temp = 0;

	for (int i = 0; i <= index; i++) {
		counter = counter->next;
	}
	return counter->data;
}
