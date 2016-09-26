#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "header.h"

#define nullptr NULL

const long numOfIterations = 1000000000;

using namespace std;

int main() {
	srand(time(nullptr));
	clock_t begin = clock();
	//Set A('A'), B('B'), C('C'), D('D'), E;
	Word A('A'), B('B'), C('C'), D('D'), E;
	for(long q = 0; q < numOfIterations; q++){
		E = (A|B|C)&~D;
	}
	clock_t end = clock();
	E.print();
	cout << end - begin;
	return 0;
}
