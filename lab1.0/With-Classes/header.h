#ifndef HEADER_H_
#define HEADER_H_
#endif /* HEADER_H_ */

#include <clocale>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <Windows.h>

class Set{
private:
	static int N;
	int n;
	char S, *A;
public:
	Set operator|(const Set&);
	Set operator&(const Set&);
	Set operator~(const Set&);
	void print();
	int power(){return n;};
	Set(char);
	Set();
	Set(const Set&);
	Set operator = (const Set&);
	~Set(){delete[] A;};
};

class Word{

};

class ByteArr{

};
