#include <clocale>
#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

class Element{
public:
	char e;
	Element* next;

	Element(char c, Element* n)
	:e(c), next(n){}
};

void printStruct(Element* A){
	for(Element* i = A; i; i = i->next){
		cout << i->e;
	}
	cout << endl;
}

Element* getStructFromArray(char A[]){
	Element* strA = nullptr;
	for(int i = 0; A[i]; i++){
		Element* a = new Element(A[i], strA);
		strA = a;
	}
	return strA;
}

bool checkForRepeat(char E[], char element, int curLen){
	for(int i = 0; i < curLen; i++){
		if(E[i] == element){
			return false;
		}
	}
	return true;
}

int copyElements(char A[], char E[], char D[], int curLen){
	for (int i = 0; A[i]; i++) {
			bool flag = true;
			if(checkForRepeat(E, A[i], curLen)){
				for (int j = 0; D[j] && flag; j++)
					if (A[i] == D[j])
						flag = 0;
				if (flag)
					E[curLen++] = A[i];
			}
		}
	return curLen;
}

int main() {
	setlocale(LC_ALL, "Russian");
	char menu;
	const int u = 33;
	char A[u], B[u], C[u], D[u];
	char E[u];
	cin >> A;
	Element* strA = nullptr;
	strA = getStructFromArray(A);
	printStruct(strA);
	return 0;
}
