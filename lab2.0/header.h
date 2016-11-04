#ifndef HEADER_H_
#define HEADER_H_

#include <clocale>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#define nullptr 0

using namespace std;

template <class Item> class Stack{
	Item* S;
	int t;
public:
	Stack(int max):S(new Item[max]), t(0){}
	int empty() const{ return t == 0;}
	void push(Item item){S[t++] = item;}
	Item pop(){ return(t?S[--t]:0);}
};

template <class Item> class Queue{
	Item* Q;
	int h, t, N;
public:
	Queue(int max):h(0), t(0), N(max), Q(new Item[max + 1]){}
	int empty() const{ return (h%N) == t;}
	void put(Item item){Q[t++] = item; t%=N;}
	Item get(){h%=N; return Q[h++];}
};

class Node{
private:
	char name;
	Node* left;
	Node* right;
	int childCount;
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
	Tree operator=(const Tree&) const;
public:
	Node* getRoot();
	Tree(char num, char maxnum, int maxrow);
	~Tree();
	void makeTree();
	bool exist();
	int bfs();
	int childCount(Node*);
	void showTree();
};

#endif /* HEADER_H_ */
