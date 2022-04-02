/*
 * Lab 03
 * Charles Phu
 * Alexander Rovner
 *
 * This assignment requires us to implement Linked Lists as well as Stack
 * and Queue ADTs that are derived from Linked Lists.
 */
#pragma once

#include <string>
#include "SinglyLinkedList.h"
#include "LinkedNode.h"



class Stack : public SinglyLinkedList {
public:
	Stack() : SinglyLinkedList() {};

	void push(Currency* p);
	Currency* pop();
	Currency* peek();

	std::string printStack();
private:
};


/*Algorithm push(Currency* p)
 * ===================================================================
 * This algorithm pushes an inputted currency object onto the stack.
 * Pre:	Currency* p - inputted currency object to add to the stack
 * Post: start and start->next or end have changed to add p onto the stack
 * Return:
 * ===================================================================
 *
 * create a new LinkedNode item with the inputted object
 * if(start is null)
 *		set start and end to point to item
 * else
 *		create a temp LinkedNode and set it equal to start
 *		set start to point to item
 *		set the node after start to point to temp
 * end if
 */
void Stack::push(Currency* p) {
	LinkedNode* item = new LinkedNode(p);
	if (start == nullptr) {
		start = item;
		end = item;
	}
	else {
		LinkedNode* temp = start;
		start = item;
		start->next = temp;
	}
}

/*Algorithm pop()
 * ===================================================================
 * This algorithm removes the top LinkedNode from the stack.
 * Pre:
 * Post: top node in the stack will be removed if non-null
 * Return: temp->data - the Currency object of the removed node
 *			OR
 *		   nullptr - the Stack is empty
 * ===================================================================
 *
 * create a new LinkedNode item with the inputted object
 * if(start is null)
 *		set start and end to point to item
 * else
 *		create a temp LinkedNode and set it equal to start
 *		set start to point to item
 *		set the node after start to point to temp
 * end if
 */
Currency* Stack::pop() {
	LinkedNode* temp = start;
	if (start == nullptr) {
		return nullptr;
	}
	else {
		start = start->next;
	}
	return temp->data;
}

/*Algorithm peek()
 * ===================================================================
 * This algorithm returns a reference to the currency object in the stack's first node.
 * Pre:
 * Post:
 * Return: temp - a reference to start's currency object
 * ===================================================================
 *
 * create a temp currency object pointer that points to start's currency object
 * return temp
 * end peek
 */
Currency* Stack::peek() {
	Currency* temp = start->data;
	return temp;
}

/*Algorithm printStack()
 * ===================================================================
 * This algorithm returns a string that contains the contents of the entire stack.
 * Pre:
 * Post:
 * Return: contents - a string that contains the contents of the entire stack
 * ===================================================================
 *
 * create a counter LinkedNode that points to start
 * create a temp currency object
 * create a contents string
 * if(start AND end are null)
 *		set contents to say that the list is empty
 * else
 *		loop a do-while(LinkedNode after counter is not null)
 *			set temp to equal counter's data
 *			if(temp's getFraction returns a value less than 10)
 *				append the temp's getWhole and getFraction results, converted to strings with an extra 0 in front of getFraction, with a tab on the end
 *			else
 *				append the temp's getWhole and getFraction results, converted to strings, with a tab on the end
 *			end if
 *			set counter to point to the node after counter
 *		end loop
 * end if
 * return contents
 */
std::string Stack::printStack() {
	LinkedNode* counter = start;
	Currency* temp = nullptr;
	std::string contents = "";

	if (start == nullptr && end == nullptr) {
		contents = "List is empty\n";
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

