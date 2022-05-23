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

void buildTree(Node*&, int*);
void addNode(Node*&, int v = 0);
void addRight(Node*& node, int v = 0);
void arithmeticNode(Node*&, int, char);
void printNode(Node* root, int space);
void printTree(Node* root);
