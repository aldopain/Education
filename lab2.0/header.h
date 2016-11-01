#ifndef HEADER_H_
#define HEADER_H_

#include <clocale>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#define nullptr 0

using namespace std;

class Node{
private:
	char name;
	Node* left;
	Node* right;
public:
	Node();
	~Node();
friend class Tree;
};

class Tree{
	Node* root;
	char num, maxnum;
	char** scrmem;
	int maxrow, offset;

	void clrscr();
	Node* makeNode(int depth);
	void showNode(Node* v, int r, int c);
	Tree(const Tree&);
	//Tree(Tree&&);
	Tree operator=(const Tree&) const;
	//Tree operator=(Tree&&) const;
public:
	Tree(char num, char maxnum, int maxrow);
	~Tree();
	void makeTree();
	bool exist();
	int dfs();
	int bfs();
	void showTree();
};

#endif /* HEADER_H_ */
