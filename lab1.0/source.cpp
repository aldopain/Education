#include <clocale>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <Windows.h>

#define nullptr NULL;

const int u = 26;

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

Element* copyElements(Element* A, Element* D, Element* E){
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

int* copyElements(int mapA[], int mapB[], int mapC[], int mapD[]){
	int* mapE = new int[u];
	for (int i = 0; i < u; i++){
		mapE[i] = (mapA[i] || mapB[i] || mapC[i]) && !mapD[i];
	}
	return mapE;
}

int* universumMapping(char* universum, char* A){
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

void printWord(long word, char* universum){
    for(int i = 0; i < u; i++)
        if(word & (1 << i)){
            cout << universum[i];
        }
    cout << endl;
}

void printByteArray(int* ba, char* universum){
    for(int i = 0; i < u; i++){
        if(ba[i] == 1){
            cout << universum[i];
        }
    }
}


int copyElements(char A[], char E[], char D[], int curLen){
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

long copyElements(long A, long B, long C, long D){
    long E = (A|B|C)&~E;
    return E;
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(866);
	char universum[] = { "abcdefghijklmnopqrstuvwxyz" };
	char A[u], B[u], C[u], D[u];
	char E[u];
	cout << "Введите A" << endl;
	cin >> A;
	cout << "Введите B" << endl;
	cin >> B;
	cout << "Введите C" << endl;
	cin >> C;
	cout << "Введите D" << endl;
	cin >> D;
	cout << "1. Работа с массивами\n2. Работа со структурами\n3. Работа через массивы битов\n4. Работа через машинные слова" << endl;
	char menu;
	cin >> menu;
	switch (menu){
		case '1':{
				int curLen = 0;
				curLen = copyElements(A, E, D, curLen);
				curLen = copyElements(B, E, D, curLen);
				curLen = copyElements(C, E, D, curLen);
				E[curLen] = 0;
				cout << E << endl;
		}
		case '2':{
				Element* strA = nullptr;
				Element* strB = nullptr;
				Element* strC = nullptr;
				Element* strD = nullptr;
				Element* strE = nullptr;
				strA = getStructFromArray(A);
				strB = getStructFromArray(B);
				strC = getStructFromArray(C);
				strD = getStructFromArray(D);
				strE = copyElements(strA, strD, strE);
				strE = copyElements(strB, strD, strE);
				strE = copyElements(strC, strD, strE);
				printStruct(strE);
				break;
		}
		case '3':{
				int* mapA = new int[u];
				int* mapB = new int[u];
				int* mapC = new int[u];
				int* mapD = new int[u];
				mapA = universumMapping(universum, A);
				mapB = universumMapping(universum, B);
				mapC = universumMapping(universum, C);
				mapD = universumMapping(universum, D);
				int* mapE = copyElements(mapA, mapB, mapC, mapD);
				printByteArray(mapE, universum);
                break;
		}
		case '4':{
				long wordA = toWord(universumMapping(universum, A));
				long wordB = toWord(universumMapping(universum, B));
				long wordC = toWord(universumMapping(universum, C));
				long wordD = toWord(universumMapping(universum, D));
                long wordE = copyElements(wordA, wordB, wordC, wordD);
                printWord(wordE, universum);
		}
	}
	return 0;
}
