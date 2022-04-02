/*
 * Lab 04
 * Charles Phu
 * Alexander Rovner
 *
 * This assignment requires us to implement a Binary Search Tree,
 * methods to traverse and modify it, and a separentate file to store
 * the output.
 */

#include "BSTNode.h"
#include "Dollar.h"
#include "Queue.h"
#include "Currency.h"
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <sstream>
#include <iomanip>
#pragma once

class BST : public Queue {
public:
    BST();
    ~BST();

    BSTNode* search(Currency* data, BSTNode* curr);
    BSTNode* min(BSTNode* cur);
    int count();
    BSTNode* deleteNode(BSTNode* curr, Currency* data);
    void deleteNode(Currency* data);
    void insert(Currency* data);
    bool isEmpty();
    void print();
    void empty();
    void swap(Currency* node1, Currency* node2);

    BSTNode* getRoot();

    // traversals
    void InorderTraversal(BSTNode* curr);
    void PreorderTraversal(BSTNode* curr);
    void PostorderTraversal(BSTNode* curr);
    std::string BreadthFirstTraversal(BSTNode* curr);

private:
    int counter = 0;
    BSTNode* root;
};

BST::BST() {
    root = nullptr;
}


/*Algorithm insert(Currency* data)
 * ===================================================================
 * This algorithm inserts an inputted Currency object into the BST.
 * Pre:	Currency* p - inputted Currency object to add to the BST
 * Post: the BST has an additional node, shifting others to fit
 * Return:
 * ===================================================================
 *
 *  create a new BSTNode node with the inputted Currency object
 *  create a new empty BSTNode parent
 *  create a new BSTNode currentNode which points to root
 *  if(root is null)
 *		 set root to point to node
 *  else
 *		 while (currentNode is not a nullptr)
 *           set parent to point to currentNode
 *           if(node's whole value is less than currentNode's whole value)
 *               set currentNode to currentNode left node
 *           else
 *               set currentNode to currentNode right node
 *           end if
 *       end loop
 *       if(node's whole value is less than parent's whole value)
 *           set parent's left node to point to node
 *       else
 *           set parent's right node to point to node
 *       end if
 *  end if
 */
 
void BST::insert(Currency* data) {
    BSTNode* node = new BSTNode(data);
    BSTNode* parent = new BSTNode();
    BSTNode* currentNode = root;
    if (root == nullptr) {
        root = node;
    }
    else {

        while (currentNode != nullptr) {
            parent = currentNode;
            //node->getData() < currentNode->getData()
            if (node->getData()->getWhole() < currentNode->getData()->getWhole()) {
                currentNode = currentNode->getLeft();
            }
            else {
                currentNode = currentNode->getRight();
            }
        }

        if (node->getData()->getWhole() < parent->getData()->getWhole()) {
            parent->setLeft(node);
        }
        else {
            parent->setRight(node);
        }
    }
    this->counter++;
}

BSTNode* BST::deleteNode(BSTNode* root, Currency* key) {
    if (root == nullptr)
        return nullptr;
    if (!key->isGreater(*root->data) && !key->isEqual(*root->data))
        root->left = deleteNode(root->left, key);
    else if (key->isGreater(*root->data))
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            
            return nullptr;
        }
        else if (root->left == nullptr) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }

        BSTNode* minimum = min(root->right);
        std::swap(root->data, minimum->data);
        //root->key = min->key;

        root->right = deleteNode(root->right, minimum->data);

    }
    return root;
}

void BST::deleteNode(Currency* data) {
    if (root == NULL) return;
    this->root = deleteNode(this->root, data);
}

BSTNode* BST::min(BSTNode* cur) {
    while (cur->left != nullptr) {
        cur = cur->left;
    }
    return cur;
}

/*Algorithm isEmpty()
 * ===================================================================
 * This algorithm determines whether or not the BST is empty and returns an appropriate bool.
 * Pre:
 * Post:
 * Return: bool answering whether the BST is empty or not
 * ===================================================================
 *
 *  if (root is null)
 *      return false
 *  else
 *      return true
 *  end if
 */
bool BST::isEmpty() {
    if (root == nullptr) {
        return false;
    }
    else {
        return true;
    }
}

void BST::empty() {
    root = nullptr;
}

BSTNode* BST::getRoot() {
    return root;
}

/*Algorithm search(Currency* data, BSTNode* curr)
 * ===================================================================
 * This algorithm recursively searches the BST for a node with data starting at the given node.
 * Pre:	Currency* data - inputted Currency object to search for
 *      BSTNode* curr - node in the BST to start search at
 * Post:
 * Return: BSTNode* - a pointer to a node in the BST
 *          OR
 *         nullptr - no nodes in the BST match the provided data object
 * ===================================================================
 *
 *  if (curr's data is null)
 *      return a nullptr
 *  end if
 *  if (data's value is less than curr's data value)
 *      return search(data, curr's left leaf node)
 *  else if (data's value is greater than curr's data value)
 *      return search(data, curr's right leaf node)
 *  else if (data's value is equal to curr's data value)
 *      return curr
 *  end if
 */
BSTNode* BST::search(Currency* data, BSTNode* curr) {
    if (curr == nullptr) {
        return nullptr;
    }
    if (data->getWhole() < curr->getData()->getWhole()) {
        return search(data, curr->getLeft());
    }
    else if (data->getWhole() > curr->getData()->getWhole()) {
        return search(data, curr->getRight());
    }
    else if (data->getWhole() == curr->getData()->getWhole() && data->getFraction() == curr->getData()->getFraction()) {
        return curr;
    }
}

int BST::count() {
    return this->counter;
}

/*Algorithm InorderTraversal(BSTNode* curr)
 * ===================================================================
 * This algorithm traverses and prints the BST in order from the provided BSTNode
 * Pre:	BSTNode* curr - the current node in the BST being traversed
 * Post: BST contents have been output to a file
 * Return:
 * ===================================================================
 *
 * IN PROGRESS
 *
 * create a new ofstream object outFS
 * open the "traversal.txt" file
 *
 * if (curr's data is not null)
 *     call InorderTraversal(curr's left leaf node)
 *     print curr's data
 *     output curr's data's print statement onto the file
 *     call InorderTraversal(curr's right leaf node)
 * end if
 * close the "traversal.txt" file
 */
void BST::InorderTraversal(BSTNode* curr) {
    /*
    goes to left most subtree
    visit node
    go to right subtree
    */

    std::fstream outFS;
    outFS.open("traversal.txt", std::ios::app);

    if (curr != nullptr) {
        InorderTraversal(curr->getLeft());
        curr->getData()->print();


        outFS << curr->getData()->getPrintStatement() << std::endl;
        InorderTraversal(curr->getRight());
    }
    outFS.close();
}

/*Algorithm PreorderTraversal(BSTNode* curr)
 * ===================================================================
 * This algorithm traverses and prints the BST in pre order from the provided BSTNode
 * Pre:	BSTNode* curr - the current node in the BST being traversed
 * Post: BST contents have been output to a file and printed
 * Return:
 * ===================================================================
 *
 * IN PROGRESS
 *
 * create a new ofstream object outFS
 * open the "traversal.txt" file
 *
 * if (curr's data is not null)
 *     print curr's data
 *     output curr's data's print statement onto the file
 *     call PreorderTraversal(curr's left leaf node)
 *     call PreorderTraversal(curr's right leaf node)
 * end if
 * close the "traversal.txt" file
 */
void BST::PreorderTraversal(BSTNode* curr) {
    /*
    visit node
    goes to left most subtree
    go to right subtree
    */

    std::fstream outFS;
    outFS.open("traversal.txt", std::ios::app);

    if (curr != nullptr) {
        curr->getData()->print();
        outFS << curr->getData()->getPrintStatement() << std::endl;
        PreorderTraversal(curr->getLeft());
        PreorderTraversal(curr->getRight());
    }
    outFS.close();
}

/*Algorithm PostorderTraversal(BSTNode* curr)
 * ===================================================================
 * This algorithm traverses and prints the BST in post order from the provided BSTNode
 * Pre:	BSTNode* curr - the current node in the BST being traversed
 * Post: BST contents have been output to a file and printed
 * Return:
 * ===================================================================
 *
 * IN PROGRESS
 *
 * create a new ofstream object outFS
 * open the "traversal.txt" file
 *
 * if (curr's data is not null)
 *     call PostorderTraversal(curr's left leaf node)
 *     call PostorderTraversal(curr's right leaf node)
 *     print curr's data
 *     output curr's data's print statement onto the file
 * end if
 * close the "traversal.txt" file
 */
void BST::PostorderTraversal(BSTNode* curr) {
    /*
    goes to left most subtree
    go to right subtree
    visit node
    */

    std::fstream outFS;
    outFS.open("traversal.txt", std::ios::app);

    if (curr != nullptr) {
        PreorderTraversal(curr->getLeft());
        PreorderTraversal(curr->getRight());
        curr->getData()->print();
        outFS << curr->getData()->getPrintStatement() << std::endl;
    }
    outFS.close();
}

/*Algorithm BreadthFirstTraversal(BSTNode* r)
 * ===================================================================
 * This algorithm traverses and prints the BST using the breadth-first order from the provided BSTNode.
 * Pre:	BSTNode* r - the current node in the BST being traversed
 * Post: BST contents have been output to a file and printed
 * Return: string - string stream's string contents were returned
 * ===================================================================
 *
 * create a new queue of BSTNodes
 * create a stringstream stream
 * create a new BSTNode curr and point it to r
 * push curr onto the queue
 * while(Queue is not empty)
 *     create a new BSTNode node equal to the front of the queue
 *     pop the queue
 *     output the node's data value to the stream
 *     if (node's left node is not null)
 *         push node's left node onto the queue
 *     end if
 *     if (node's right node is not null)
 *         push node's right node onto the queue
 *     end if
 * end loop
 * create a new fstream object
 * open the "traversal.txt" file
 * print the string stream to the file
 * close the "traversal.txt" file
 * return the string stream
 */
std::string BST::BreadthFirstTraversal(BSTNode* r) {
    std::queue<BSTNode*>* Queue = new std::queue<BSTNode*>();
    std::stringstream stream;

    BSTNode* curr = r;
    Queue->push(curr);
    while (!Queue->empty()) {
        BSTNode* node = Queue->front();
        Queue->pop();
        stream << std::fixed << std::setprecision(2) << node->getData()->getPrintStatement() << std::endl;
        if (node->getLeft() != nullptr) {
            Queue->push(node->getLeft());
        }
        if (node->getRight() != nullptr) {
            Queue->push(node->getRight());
        }
    }

    std::fstream outFS;
    outFS.open("traversal.txt", std::ios::app);
    outFS << stream.str() << std::endl;
    outFS.close();

    return stream.str();
}
