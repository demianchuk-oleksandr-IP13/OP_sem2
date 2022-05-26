#include "func.h"

Tree::Tree() {
	Node* root = 0;
}

Node* Tree::getRoot() {
	return root;
}

void Tree::buildTree() {
	for (int i = 0; i < 4; i++) {
		addNode(this->root);
	}
	root->left->left->left->right = 0;
}

void Tree::fillTree(int* num) {
	root->left->left->left->value = num[0];
	
	arithmeticNode(root->left->left, num[1], '+');
	arithmeticNode(root->left, num[2], '*');
	arithmeticNode(root, num[3], '-');
}

void Tree::addNode(Node*& node) {
	int leaves = 0;
	if (!node)
	{
		node = new Node;
		node->value = 0;
		node->left = 0;
		addRight(node->right);
		return;
	}
	else
	{
		addNode(node->left);
	}
}

void Tree::addRight(Node*& node) {
		node = new Node;
		node->value = 0;
		node->left = 0;
		node->right = 0;
}


void Tree::arithmeticNode(Node*& node, int num, char oper) {
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


void Tree::printNode(Node* root, int space) {
	if (root == NULL) return;
	printNode(root->right, ++space);
	for (int i = 1; i < space; i++) {
		cout << '\t';
	}
	cout << root->value << endl;
	printNode(root->left, space);
}

void Tree::printTree(Node* root) {
	cout << "__________________________________\n";
	cout << endl << endl;
	printNode(root, 0);
	cout << "__________________________________\n\n";
}
