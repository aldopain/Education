#include <clocale>
#include <cstdio>
#include <iostream>

using namespace std;

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
	const int u = 32;
	char A[32], B[32], C[32], D[32];
	char E[u];
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> D;
	int curLen = 0;
	curLen = copyElements(A, E, D, curLen);
	curLen = copyElements(B, E, D, curLen);
	curLen = copyElements(C, E, D, curLen);
	E[curLen] = 0;
	cout << E << endl;
	return 0;
}
