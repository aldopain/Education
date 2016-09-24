/*
 * Set.cpp
 *
 *  Created on: 23 сент. 2016 г.
 *      Author: Яан
 */

#include "header.h"
using namespace std;

Set Set::operator|(const Set&B){
	Set C;
	memcpy(C.elements, elements, length);
	C.length = length;
	for(int i = 0; i < B.length; i++){
		bool f = true;
		for(int j = 0; j < length; j++)
			if(B.elements[i] == elements[j])
				f = false;
		if(f)
			C.elements[C.length++] = B.elements[i];
	}
	C.elements[C.length] = 0;
	return C;
}

Set Set::operator&(const Set&B){
	Set C;
		for(int i = 0; i < length; i++){
			for(int j = 0; j < B.length; j++)
				if(elements[i] == B.elements[j])
					C.elements[C.length++] = elements[i];
		}
	C.elements[C.length] = 0;
	return C;
}

Set Set::operator~() const{
	Set C;
	for(char c = 'a'; c <= 'z'; c++){
		bool f = true;
		for(int j = 0; j < length; j++)
			if(c == elements[j]){
				f = false;
				break;
			}
		if(f)
			C.elements[C.length++] = c;
	}
	C.elements[C.length] = 0;
	return C;
}

void Set::print(){
	cout << name << " = [" << elements << "]" << endl;
}

int Set::power(){
	return length;
}

Set::Set(char s): name(s), length(0), elements(new char[N+1]){
	for(int i = 0; i < N; i++)
		if(rand()%2)
			elements[length++] = i + 'a';
	elements[length] = 0;
	this->print();
}

Set::Set():length(0), name('O'){
	elements = new char[N+1];
	elements[0] = 0;
}

Set::Set(const Set&B): name(B.name), elements(new char[N+1]), length(B.length){
	memcpy(elements, B.elements, N+1);
}

Set Set::operator = (const Set&B){
	if(this != &B){
		memcpy(elements, B.elements, N+1);
		name = 'R';
	}
	return *this;
}

Set::~Set(){
	delete[] elements;
}


