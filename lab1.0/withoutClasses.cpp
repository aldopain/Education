#include <clocale>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <time.h>

#define nullptr NULL

const int u = 26;
const long numOfIterations = 10000000;
const int menu = 4;
const char universum[] = { "abcdefghijklmnopqrstuvwxyz" };

using namespace std;

class Element{
public:
	char e;
	Element* next;

	Element(char c, Element* n)
		:e(c), next(n){}
};

void printStruct(Element* A){
	for (Element* i = A; i; i = i->next){
		cout << i->e;
	}
	cout << endl;
}

Element* getStructFromArray(char A[]){
	Element* strA = nullptr;
	for (int i = 0; A[i]; i++){
		Element* a = new Element(A[i], strA);
		strA = a;
	}
	return strA;
}

bool checkForRepeat(char E[], char element, int curLen){
	for (int i = 0; i < curLen; i++){
		if (E[i] == element){
			return false;
		}
	}
	return true;
}

bool checkForRepeat(Element* E, char element){
	for (Element* i = E; i; i = i->next) {
		if (i->e == element){
			return false;
		}
	}
	return true;
}

Element* test(Element* A, Element* D, Element* E){
	for (Element* i = A; i; i = i->next) {
		bool flag = true;
		if (checkForRepeat(E, i->e)){
			for (Element* j = D; j && flag; j = j->next)
			if (i->e == j->e)
				flag = 0;
			if (flag){
				Element* a = new Element(i->e, E);
				E = a;
			}
		}
	}
	return E;
}

int* test(int mapA[], int mapB[], int mapC[], int mapD[]){
	int* mapE = new int[u];
	for (int i = 0; i < u; i++){
		mapE[i] = (mapA[i] || mapB[i] || mapC[i]) && !mapD[i];
	}
	return mapE;
}

int* universumMapping(char* A){
	int* map = new int[u];
	for (int i = 0; i < u; i++)
		map[i] = 0;
	for (int j = 0; A[j]; j++){
		for (int i = 0; universum[i]; i++){
			if (A[j] == universum[i])
				map[i] = 1;
		}
	}
	return map;
}

void printWord(long word){
    for(int i = 0; i < u; i++)
        if(word & (1 << i)){
            cout << universum[i];
        }
    cout << endl;
}

void printByteArray(int* ba){
    for(int i = 0; i < u; i++){
        if(ba[i] == 1){
            cout << universum[i];
        }
    }
}
char* randomizer(){
	char* A;
	A = new char[u+1];
	int curLen = 0;
	for (int j = 0; j < u; j++){
		if(rand()%2)
			A[curLen++] = universum[j];
	}
	A[curLen] = '\0';
	return A;
}

int test(char A[], char E[], char D[], int curLen){
	for (int i = 0; A[i]; i++) {
		bool flag = true;
		if (checkForRepeat(E, A[i], curLen)){
			for (int j = 0; D[j] && flag; j++)
			if (A[i] == D[j])
				flag = 0;
			if (flag)
				E[curLen++] = A[i];
		}
	}
	return curLen;
}

long toWord(int* A){
    long word = 0;
    for(int i = 0; i < u; i++)
        if(A[i] == 1)
            word |= (1 << i);
    return word;
}

long test(long A, long B, long C, long D){
    long E = (A|B|C)&~D;
    return E;
}

int main() {
	srand(time(nullptr));
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(866);
	char *A, *B, *C, *D;
	char E[u];
	A = randomizer();
	B = randomizer();
	C = randomizer();
	D = randomizer();
	cout << A << endl << B << endl << C << endl << D << endl;
	switch (menu){
		case 1:{
			clock_t begin = clock();
			for(int i = 0; i < numOfIterations; i++){
				int curLen = 0;
				curLen = test(A, E, D, curLen);
				curLen = test(B, E, D, curLen);
				curLen = test(C, E, D, curLen);
				E[curLen] = 0;
			}
			cout << E << endl;
			clock_t end = clock();
			cout << end - begin;
			break;
		}
		case 2:{
			Element* strA = nullptr;
			Element* strB = nullptr;
			Element* strC = nullptr;
			Element* strD = nullptr;
			Element* strE = nullptr;
			strA = getStructFromArray(A);
			strB = getStructFromArray(B);
			strC = getStructFromArray(C);
			strD = getStructFromArray(D);
			clock_t begin = clock();
			for(int i = 0; i < numOfIterations; i++){
				strE = test(strA, strD, strE);
				strE = test(strB, strD, strE);
				strE = test(strC, strD, strE);
			}
			printStruct(strE);
			clock_t end = clock();
			cout << end - begin;
			break;
		}
		case 3:{
			int* mapE;
			int* mapA = new int[u];
			int* mapB = new int[u];
			int* mapC = new int[u];
			int* mapD = new int[u];
			mapA = universumMapping(A);
			mapB = universumMapping(B);
			mapC = universumMapping(C);
			mapD = universumMapping(D);
			clock_t begin = clock();
			for(int i = 0; i < numOfIterations; i++){
				mapE = test(mapA, mapB, mapC, mapD);
			}
			printByteArray(mapE);
			clock_t end = clock();
			cout << endl << end - begin;
            break;
		}
		case 4:{
			long wordE;
			long wordA = toWord(universumMapping(A));
			long wordB = toWord(universumMapping(B));
			long wordC = toWord(universumMapping(C));
			long wordD = toWord(universumMapping(D));
			clock_t begin = clock();
			for(int i = 0; i < numOfIterations; i++)
				wordE = test(wordA, wordB, wordC, wordD);
            printWord(wordE);
            clock_t end = clock();
            cout << end - begin;
		}
	}
	return 0;
}
