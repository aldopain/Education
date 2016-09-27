#ifndef HEADER_H_
#define HEADER_H_
#endif /* HEADER_H_ */

#include <clocale>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <Windows.h>

#define nullptr NULL
const char universum[] = {"abcdefghijklmnopqrstuvwxyz"};
static const int N = 26;

class Set{
private:
	int length;
	char name, *elements;
public:
	Set operator|(const Set&);
	Set operator&(const Set&);
	Set operator~() const;
	void print();
	int power();
	Set(char);
	Set();
	Set(const Set&);
	Set operator = (const Set&);
	~Set();
};

class Word{
private:
	char name;
	long word;
public:
	Word();
	Word(char);
	Word(long);
	Word(const Word&);
	Word operator = (const Word&);
	Word operator|(const Word&);
	Word operator&(const Word&);
	Word operator~() const;
	void print();
};

class ByteArr{
private:
	bool elements[N];
	char name;
public:
	ByteArr();
	ByteArr(char);
	ByteArr(char*);
	ByteArr(const ByteArr&);
	ByteArr operator = (const ByteArr&);
	ByteArr operator|(const ByteArr&);
	ByteArr operator&(const ByteArr&);
	ByteArr operator~() const;
	void print();
};

class List{
private:
	char name;
	char* head;
	List *next;
public:
	List();
	List(char);
	List(char*);
	List(const List&);
	List operator = (const List&);
	List operator|(const List&);
	List operator&(const List&);
	List operator~() const;
	void print();
};
