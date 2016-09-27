#include "header.h"
using namespace std;

ByteArr::ByteArr():name('E'){
	for(int i = 0; i < N; i++)
		elements[i] = 0;
}

ByteArr::ByteArr(char c):name(c){
	for(int i = 0; i < N; i++){
		elements[i] = rand()%2;
	}
	this->print();
}

ByteArr::ByteArr(char* c){
	for(int i = 0; i < N; i++){
		for(int j = 0; c[j]; i++)
			if(c[j] == universum[i])
				elements[i] = 1;
			else
				elements[i] = 0;
	}
	name = 'Z';
}

ByteArr::ByteArr(const ByteArr&B):name('N'){
	for(int i = 0; i < N; i++){
		elements[i] = B.elements[i];
	}
}

ByteArr ByteArr::operator = (const ByteArr&B){
	ByteArr a;
	for(int i = 0; i < N; i++){
		elements[i] = B.elements[i];
	}
	return *this;
}

ByteArr ByteArr::operator|(const ByteArr&B){
	ByteArr a;
	for(int i = 0; i < N; i++)
		a.elements[i] = elements[i]|B.elements[i];
	return a;
}

ByteArr ByteArr::operator&(const ByteArr&B){
	ByteArr a;
	for(int i = 0; i < N; i++)
		a.elements[i] = elements[i]&B.elements[i];
	return a;
}

/*Word Word::operator~() const{
	Word a;
	a.word = ~word;
	return a;
}*/

ByteArr ByteArr::operator~() const{
	ByteArr a;
	for(int i = 0; i < N; i++)
		a.elements[i] = ~elements[i];
	return a;
}

void ByteArr::print(){
	cout << name << " = [ ";
	for(int i = 0; i < N; i++){
		if(elements[i])
			cout << universum[i];
	}
	cout << " ]" << endl;
}



