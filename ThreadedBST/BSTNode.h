/*
 * BSTNode.h
 *
 *  Created on: Jul 12, 2019
 *      Author: alex
 */

#ifndef BSTNODE_H_
#define BSTNODE_H_

#include <iostream>

template <typename Key, typename E>
class BSTNode {
private:
	Key key;
	E value;
	bool leftIsChild = false;
	bool rightIsChild = false;
	BSTNode<Key, E>* leftChild;
	BSTNode<Key, E>* rightChild;

public:
	static BSTNode<Key, E>* nullNode;

	~BSTNode() {}

	// Default constructor
	BSTNode() {
		// Null constructor has no predecessor or successor
		leftChild = rightChild = nullNode;
	}

	// Constructor. Sets key, value, and left and right child
	BSTNode(Key k, E val, BSTNode<Key, E>* left_child, BSTNode<Key, E>* right_child) {
		key = k;
		value = val;
		setLeft(left_child);
		setRight(right_child);
	}

	// Return node value
	E& getVal() {
		return value;
	}

	// Set node value
	void setVal(const E& val) {
		value = val;
	}

	// Return node key
	Key& getKey() {
		return key;
	}

	// Set node key
	void setKey(const Key& k) {
		key = k;
	}

	// Return left child
	BSTNode* getLeft() {
		return leftChild;
	}

	// Return right child
	BSTNode* getRight() {
		return rightChild;
	}

	// Set left child (and appropriate threads)
	void setLeft(BSTNode<Key,E>* left_child) {
		if (left_child != nullNode) {
			left_child->leftChild = this->leftChild;
			left_child->rightChild = this;
			leftChild = left_child;
			leftIsChild = true;
		} else {
			left_child = nullNode;
		}
	}

	// Set right child (and appropriate threads)
	void setRight(BSTNode<Key,E>* right_child) {
		if (right_child != nullNode) {
			right_child->leftChild = this;
			right_child->rightChild = this->rightChild;
			rightChild = right_child;
			rightIsChild = true;
		} else {
			right_child = nullNode;
		}
	}

	// Preorder-traverse tree from given root.
	void traversePreorder(BSTNode<Key,E>* root) {
		BSTNode<Key, E>* curNode = root;
		while (curNode != nullNode) {
			std::cout << curNode->value << "\n";
			if (curNode->leftIsChild) {
				curNode = curNode->leftChild;
			} else if (curNode->rightIsChild) {
				curNode = curNode->rightChild;
			} else {
				while (curNode != nullNode && !curNode->rightIsChild) {
					curNode = curNode->rightChild;
				}
				if (curNode != nullNode) {
					curNode = curNode->rightChild;
				}
			}
		}
	}

	// False if either left or right is an actual child (not a thread)
	bool isLeaf() {
		return !(leftIsChild || rightIsChild);
	}
};

template <typename Key, typename E>
BSTNode<Key, E>* BSTNode<Key,E>::nullNode = NULL;

#endif /* BSTNODE_H_ */
