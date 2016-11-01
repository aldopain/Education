#include "header.h"

Node::Node():left(nullptr), right(nullptr){}

Node::~Node(){
	if(left)
		delete left;
	if(right)
		delete right;
}

void Tree::makeTree(){
	root = makeNode(0);
}

Tree::Tree(char n, char mn, int mr):
	num(n), maxnum(mn), maxrow(mr), offset(40), root(nullptr), scrmem(new char*[maxrow]){
	for(int i = 0; i < maxrow; i++)
		scrmem[i] = new char[80];
}

Tree::~Tree(){
	for(int i = 0; i < maxrow; i++)
		delete[] scrmem[i];
	delete[] scrmem;
	delete root;
}

Node* Tree::makeNode(int depth){
	Node* v = nullptr;
	int flag = (depth < rand()%6 + 1) && (num <= 'z');
	if (flag){
		v = new Node;
		v->left = makeNode(depth + 1);
		v->name = num++;
		v->right = makeNode(depth + 1);
	}
	return v;
}

void Tree::clrscr(){
	for(int i = 0; i < maxrow; i++)
		memset(scrmem[i], '.', 80);
}

void Tree::showNode(Node *v, int r, int c){
	if(r && c && (c < 80))
		scrmem[r - 1][c - 1] = v->name;
	if(r < maxrow){
		if(v->left)
			showNode(v->left, r + 1, c - (offset >> r));
		if(v->right)
			showNode(v->right, r + 1, c + (offset >> r));
	}
}

void Tree::showTree(){
	clrscr();
	showNode(root, 1, offset);
	for(int i = 0; i < maxrow; i++){
		scrmem[i][79] = 0;
		cout << '\n' << scrmem[i];
	}
	cout << '\n';
}
