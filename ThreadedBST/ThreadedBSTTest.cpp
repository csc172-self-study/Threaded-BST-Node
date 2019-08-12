/*
 * ThreadedBSTTest.cpp
 *
 * Simple driver to test threaded BST implementation. Note that this does not make use of an actual tree.
 *
 *  Created on: Aug 12, 2019
 *      Author: alex
 */

#include "BSTNode.h"
#include <string>
using std::string;

int main() {
	// Create 4 nodes
	BSTNode<int, string>* node1 = new BSTNode<int, string>(1, "node1", BSTNode<int,string>::nullNode, BSTNode<int,string>::nullNode);
	BSTNode<int, string>* node2 = new BSTNode<int, string>(2, "node2", BSTNode<int,string>::nullNode, BSTNode<int,string>::nullNode);
	BSTNode<int, string>* node3 = new BSTNode<int, string>(3, "node3", BSTNode<int,string>::nullNode, BSTNode<int,string>::nullNode);
	BSTNode<int, string>* node4 = new BSTNode<int, string>(4, "node4", BSTNode<int,string>::nullNode, BSTNode<int,string>::nullNode);

	// Combine them manually into a small tree
	node3->setLeft(node2);
	node2->setLeft(node1);
	node3->setRight(node4);

	// Traverse this (very small) tree. Could call the traverse function from any node.
	node1->traversePreorder(node3);
}
