#include "func.h"

void buildTree(Node*& y3, int* num) {
	for (int i = 0; i < 4; i++) {
		addNode(y3);
	}
	y3->left->left->left->value = num[0];
	y3->left->left->left->right = 0;
	arithmeticNode(y3->left->left, num[1], '+');
	arithmeticNode(y3->left, num[2], '*');
	arithmeticNode(y3, num[3], '-');
}

void addNode(Node*& node, int v) {
	int leaves = 0;
	if (!node)
	{
		node = new Node;
		node->value = v;
		node->left = 0;
		addRight(node->right);
		return;
	}
	else
	{
		addNode(node->left, v);
	}
}

void addRight(Node*& node, int v) {
		node = new Node;
		node->value = v;
		node->left = 0;
		node->right = 0;
}


void arithmeticNode(Node*& node, int num, char oper) {
	node->right->value = num;
	switch (oper) {
	case('+'):
		node->value = node->left->value + node->right->value;
		break;
	case('-'):
		node->value = node->left->value - node->right->value;
		break;
	case('*'):
		node->value = node->left->value * node->right->value;
		break;
	default:
		node->value = node->left->value / node->right->value;
		break;
	}
}


void printNode(Node* root, int space) {
	if (root == NULL) return;
	printNode(root->right, ++space);
	for (int i = 1; i < space; i++) {
		cout << '\t';
	}
	cout << root->value << endl;
	printNode(root->left, space);
}

void printTree(Node* root) {
	cout << "__________________________________\n";
	cout << endl << endl;
	printNode(root, 0);
	cout << "__________________________________\n\n";
}
