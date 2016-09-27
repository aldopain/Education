#include "header.h"
using namespace std;

Word::Word():word(0),name('E'){}

Word::Word(char c):word(rand()),name(c){
	this->print();
}

Word::Word(long a):word(a), name('R'){}

Word::Word(const Word&B):word(B.word), name(B.name){}

Word Word::operator = (const Word&B){
	word = B.word;
	return *this;
}

Word Word::operator|(const Word&B){
	Word a;
	a.word = word|B.word;
	return a;
}

Word Word::operator&(const Word&B){
	Word a;
	a.word = word&B.word;
	return a;
}

Word Word::operator~() const{
	Word a;
	a.word = ~word;
	return a;
}

void Word::print(){
	cout << name << "[ ";
	for(int i = 0; i < N; i++){
		if(word & (1 << i))
			cout << universum[i];
	}
	cout<< " ]" << endl;
}
