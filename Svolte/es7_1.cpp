#include<iostream>
#include "es7_1_binary_tree.h"

using namespace std;

int main() {
	BinaryTree<Item> albero;

	Item p("alberto");
	albero.AddItem(p);
	Item p1("antonio");
	albero.AddItem(p1);
	Item p2("roberto");
	albero.AddItem(p2);
	Item p3("francesco");
	albero.AddItem(p3);
	Item p4("maurizio");
	albero.AddItem(p4);

	cout << "Post order: ";
	albero.traverse();
}