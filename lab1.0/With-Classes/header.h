/*
 * header.h

 *
 *  Created on: 23 сент. 2016 г.
 *      Author: Яан
 */

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
	static const int N = 26;
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
	static const int N = 26;
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
	static const int N = 32;
	int length, *elements;
	char name;
};
