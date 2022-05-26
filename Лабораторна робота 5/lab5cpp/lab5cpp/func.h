#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
	int value;
	Node* left;
	Node* right;
};

class Tree {
private:
	Node* root;
public:
	Tree();
	Node* getRoot();
	void buildTree();
	void fillTree(int*);
	void addNode(Node*&);
	void addRight(Node*&);
	void arithmeticNode(Node*&, int, char);
	void printNode(Node*, int);
	void printTree(Node*);
};

