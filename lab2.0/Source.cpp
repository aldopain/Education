#include "header.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main(){
	int n = 0;
	srand(time(nullptr));
	Tree tr('a', 'z', 8);
	setlocale(LC_ALL, "Russian");
	tr.makeTree();
	tr.showTree();
	tr.childCount(tr.getRoot());
	tr.bfs();
	puts("endq");
	return 0;
}
