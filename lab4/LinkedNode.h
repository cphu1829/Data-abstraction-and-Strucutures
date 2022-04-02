/*
 * Lab 03
 * Charles Phu
 * Alexander Rovner
 *
 * This assignment requires us to implement Linked Lists as well as Stack
 * and Queue ADTs that are derived from Linked Lists.
 */

#include "Currency.h"
#pragma once
class LinkedNode {
public:
	LinkedNode();
	LinkedNode(Currency* d);
	~LinkedNode();

	Currency* data;
	LinkedNode* next;
};

LinkedNode::LinkedNode() {
	data = nullptr;
	next = nullptr;
}

LinkedNode::LinkedNode(Currency* d) {
	data = d;
	next = nullptr;
}
