/*y3			  y2-d
				/	   \
y2			  y1*c		d
			 /		\
y1			a+b		 c
		   /    \
		  a		 b					*/
#include "func.h"

int main() {
	int num[4];
	cout << "ok, throw me some numbers: \n";
	for (int i = 0; i < 4; i++) {
		cout << (char)(97 + i) << ": ";
		cin >> num[i];
	}
	Node* root = 0;
	buildTree(root, num);
	vector<int> base;
	cout << "tree value is " << root->value << "\n";
	cout << "y3=y2-d\n";
	printTree(root);
	cout << "y2=y1*c\n";
	printTree(root->left);
	cout << "a+b\n";
	printTree(root->left->left);
}