include "header.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <math.h>

static int toNum = 48;
static int R = 2;

class Bigraph{
	bool findPath(int start, int* matching, bool* visited){
		visited[start] = true;
		for(int v = 0; v < numOfNodes; v++){
			int u = matching[v];
			if(matrix[start][v] && (u == -1 || (!visited[u] && findPath(u, matching, visited)))){
				matching[v] = start;
				return true;
			}
		}
		return false;
	}

	public:
	vector < vector <bool> > matrix;
	int numOfNodes;

	Bigraph(string s){
		numOfNodes = sqrt(s.length());
		for(int i = 0; i < numOfNodes; i++)
			matrix.push_back(vector<bool>(numOfNodes));
		for(int i = 0; i < s.length(); i++)
			matrix[i/numOfNodes][i%numOfNodes] = s.at(i) - toNum;
	}

	Bigraph(int N){
		numOfNodes = N;
		vector<int> right(1);
		vector<int> left(1);
		right.push_back(0);
		left.push_back(1);
		for(int i = 2; i < numOfNodes; i++){
			if(rand()%R)
				right.push_back(i);
			else
				left.push_back(i);
		}
		for(int i = 0; i < numOfNodes; i++)
			matrix.push_back(vector<bool>(numOfNodes));
		for(int i = 0; i < right.size(); i++){
			for(int j = 0; j < left.size(); j++){
				int a = rand()%2;
				matrix[right[i]][left[j]] = a;
				matrix[left[j]][right[i]] = a;
			}
		}
		for(int i = 0; i < numOfNodes; i++)
			matrix[i][i] = 0;
	}

	int* maxMatching(){
		int* matching = new int[numOfNodes];
		for(int i = 0; i < numOfNodes; i++)
			matching[i] = -1;
		for(int u = 0; u < numOfNodes; u++)
			findPath(u, matching, new bool[numOfNodes]);
		return matching;
	}
};

int main(){
	srand(time(nullptr));
	//Bigraph a(6);
	//Bigraph a("0100000110111000010001000100001001000000001000000001000010000000");
	//Bigraph a("0001100000101100001001100000101000001000000100000");
	//Bigraph a("0000010000000111000001100000000100000001111000000110000000011000");
	//Bigraph a("0001100011000101110011000");
	//Bigraph a("001011001010110000000001110000100100");
	//Bigraph a("0100101001010010");
	Bigraph a("011100100");
	long start_time =  clock();
	int* res;
	for(int i = 0; i < 1000000; i++)
		res = a.maxMatching();
	long end_time =  clock();
	for(int i = 0; i < a.numOfNodes; i++){
		for(int j = 0; j < a.numOfNodes; j++)
			cout << (a.matrix)[i][j];
		cout << endl;
	}
	for(int i = 0; i < a.numOfNodes; i++)
		cout << res[i] << endl;
	cout << end_time - start_time << endl;
	return 0;
}
