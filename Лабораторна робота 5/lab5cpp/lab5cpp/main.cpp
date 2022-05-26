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

	Tree Derevo = Tree();
	Derevo.buildTree();
	Derevo.fillTree(num);
	vector<int> base;
	cout << "tree value is " << Derevo.getRoot()->value << "\n";
	cout << "y3 = y2-d\n";
	Derevo.printTree(Derevo.getRoot());
	cout << "y2 = y1*c\n";
	Derevo.printTree(Derevo.getRoot()->left);
	cout << "y1 = a+b\n";
	Derevo.printTree(Derevo.getRoot()->left->left);
}