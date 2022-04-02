/*
 * Lab 05
 * Charles Phu
 * Alexander Rovner
 *
 * This assignment requires us to implement a hash table,
 * resolve collisions using quadratic probing, and allow
 * users to search the hash table.
 */

#include <iostream>
#include "Dollar.h"

#pragma once

class Hash{
public:
	Hash();
	void insert(Currency* data);
	int search(Currency* data);
	int getCollisions();
	double getLoadFactor();
	int getItemsLoaded();
private:
	int itemsLoaded = 0;
	int collisions = 0;
	const int SIZE = 29;
	Currency* map[29];
};



Hash::Hash() {
	for (int i = 0; i < 29; i++) {
		map[i] = NULL;
	}
}

/*Algorithm insert(Currency* data)
 * ===================================================================
 * This algorithm inserts the provided Currency object into the hash.
 * Pre: Currency* data - provided object to add to the hash
 * Post: map -
 * Return:
 * ===================================================================
 *
 * Create int bucketsProbed and set it to 0
 * Create int i and set it to 0
 * Create int key and use data to calculate where to insert the object
 *
 * Create an int bucket that is equal to key
 * while (bucketsProbed < SIZE)
 *     if(map[bucket] is NULL)
 *         set map[bucket] to data
 *         increment itemsLoaded
 *         break
 *     end if
 *     increment i
 *     increment collisions
 *     set bucket to new location using quadratic formula
 *     increment bucketsProbed
 * end loop
 */
void Hash::insert(Currency* data) {
	int bucketsProbed = 0;
	int i = 0;
	int key = (data->getWhole() * 2 + data->getFraction() * 3) % SIZE;

	int bucket = key;
	while (bucketsProbed < SIZE) {
		if (map[bucket] == NULL) {
			map[bucket] = data;
			itemsLoaded++;
			break;
		}
		/*
		
		for (int i = 0; i < bucket; i++) {
			currBucket = currBucket->next;
		}
		if (currBucket->data->getWhole() == 0) {
			currBucket = new LinkedNode(data);
			break;
		}
		n++;
		bucket = (data->getWhole() % size + n + n*n) % size;
		
		bucketsProbed++;
		std::cout << bucketsProbed << std::endl;
		*/
		i++;
		collisions++;
		bucket = (key + 1 * i + 1 * i * i) % SIZE;
		bucketsProbed++;
	}
}


/*Algorithm search(Currency* data)
 * ===================================================================
 * This algorithm searches the hash for the provided data object.
 * Pre: Currency* data - provided object to search the hash for
 * Post:
 * Return: int counter - location in hash where the data object is present
 *              OR
 *         int - 1     - the hash does not have the data object
 * ===================================================================
 *
 * Create int counter and set it to 0
 * for (int i starts at 0, increments until i equals SIZE)
 *     if (map[i] is not NULL)
 *         if (map[i] is equal to the data pointer)
 *             return counter
 * end loop
 * return -1 (out of bonds)
 */
int Hash::search(Currency* data) {
	int counter = 0;
	for (int i = 0; i < SIZE; i++) {
		if (map[i] != NULL) {
			if (map[i]->isEqual(*data)) {
				return counter;
			}
		}
		counter++;
	}
	return -1;
}

/*Algorithm getCollisions() / Algorithm getLoadFactor() / Algorithm getItemsLoaded()
 * ===================================================================
 * These algorithms return specific variables for other classes to make use of.
 * Pre:
 * Post:
 * Return: int collisions - number of collisions
 *              OR
 *         int itemsLoaded / SIZE - load factor
 *              OR
 *         int itemsLoaded - number of items loaded into the hash
 * ===================================================================
 *
 * Create int counter and set it to 0
 * for (int i starts at 0, increments until i equals SIZE)
 *     if (map[i] is not NULL)
 *         if (map[i] is equal to the data pointer)
 *             return counter
 * end loop
 * return -1
 */
int Hash::getCollisions() {
	return collisions;
};
double Hash::getLoadFactor() {
	return (double) itemsLoaded / SIZE;
}
int Hash::getItemsLoaded() {
	return itemsLoaded;
}