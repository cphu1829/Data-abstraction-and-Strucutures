/*
 * Lab 04
 * Charles Phu
 * Alexander Rovner
 *
 * This assignment requires us to implement a Binary Search Tree,
 * methods to traverse and modify it, and a separate file to store
 * the output.
 */

#pragma once
#include "Currency.h"
class BSTNode {
public:
	BSTNode();
	BSTNode(Currency* d);

	BSTNode* getLeft();
	BSTNode* getRight();
	Currency* getData();
	void setLeft(BSTNode* temp);
	void setRight(BSTNode* temp);
	void setData(Currency* d);
	BSTNode* left;
	BSTNode* right;
	Currency* data;
private:
};

BSTNode::BSTNode() {
	data = nullptr;
	left = nullptr;
	right = nullptr;
}

BSTNode::BSTNode(Currency* d) {
	this->data = d;
	left = nullptr;
	right = nullptr;
}


BSTNode* BSTNode::getLeft() {
	return left;
}

BSTNode* BSTNode::getRight() {
	return right;
}

Currency* BSTNode::getData() {
	return data;
}

void BSTNode::setLeft(BSTNode* temp) {
	left = temp;
}

void BSTNode::setRight(BSTNode* temp) {
	right = temp;
}

void BSTNode::setData(Currency* d) {
	data = d;
}

