/*
 * Lab 03
 * Charles Phu
 * Alexander Rovner
 *
 * This assignment requires us to implement Linked Lists as well as Stack
 * and Queue ADTs that are derived from Linked Lists.
 */
#pragma once
#include "SinglyLinkedList.h"
#include "LinkedNode.h"
#include <string>

class Queue : public SinglyLinkedList {
public:
	Queue() : SinglyLinkedList() {};

	void enqueue(Currency* p);

	Currency* dequeue();
	Currency* peekFront();
	Currency* peekRear();

	std::string printQueue();
private:
};

/*Algorithm enqueue(Currency* p)
 * ===================================================================
 * This algorithm enqueues an inputted currency object onto the end of the queue.
 * Pre:	Currency* p - inputted currency object to add to the queue
 * Post: end and either end->next or start have changed to add p into the queue
 * Return:
 * ===================================================================
 *
 * create a new LinkedNode item with the inputted object
 * if(start is null)
 *		set start and end to point to item
 * else
 *		set the node after end to point to item
 *		set end to point to item
 * end if
 */
void Queue::enqueue(Currency* p) {
	LinkedNode* item = new LinkedNode(p);
	if (start == nullptr) {
		start = item;
		end = item;
	}
	else {
		end->next = item;
		end = item;
	}
}

/*Algorithm dequeue()
 * ===================================================================
 * This algorithm dequeues the LinkedNode from the start of the queue.
 * Pre:
 * Post: start now points to start->next
 * Return: temp->data - a currency object that has been removed from the queue
 * ===================================================================
 *
 * create a new LinkedNode temp with the inputted object
 * if(start is null)
 *		return a nullptr
 * else
 *		set start to point to the node after start
 * end if
 * return temp's currency object
 */
Currency* Queue::dequeue() {
	LinkedNode* temp = start;
	if (start == nullptr) {
		return nullptr;
	}
	else {

		start = start->next;
	}
	return temp->data;
}

/*Algorithm peekFront()
 * ===================================================================
 * This algorithm returns a reference to the currency object at the front of the queue.
 * Pre:
 * Post:
 * Return: temp - a reference to the currency object at the front of the queue
 * ===================================================================
 *
 * create a new currency object reference that points to the currency object at the front of the queue
 * return temp
 */
Currency* Queue::peekFront() {
	Currency* temp = start->data;
	return temp;
}

/*Algorithm peekRear()
 * ===================================================================
 * This algorithm returns a reference to the currency object at the end of the queue.
 * Pre:
 * Post:
 * Return: temp - a reference to the currency object at the end of the queue
 * ===================================================================
 *
 * create a new currency object reference that points to the currency object at the end of the queue
 * return temp
 */
Currency* Queue::peekRear() {
	Currency* temp = end->data;
	return temp;
}

/*
Queue::printQueue() {
	string s;
	LinkedNode* counter = start;
	if (start == nullptr && end == nullptr) {
		std::cout << "List is empty" << std::endl;
	}
	else {
		do {
			counter->getData()->print();
			counter = counter->getNext();
		} while (counter->next != nullptr);
	}

	return s;
}
*/


/*Algorithm printQueue()
 * ===================================================================
 * This algorithm returns a string that contains the contents of the entire queue, from front to end.
 * Pre:
 * Post:
 * Return: contents - a string that contains the contents of the entire queue
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
std::string Queue::printQueue() {
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