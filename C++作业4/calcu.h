#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<sstream>
using namespace std;
class cal 
{
public:
	void random(int *a, int*b, int*c, int *d);
	void boundary();
	void print( int v, int c);
	void writefile(char *str, char *p);
	int fileread(char *p1);
	int test(int total, char *p1);
	int generateExpression(int x);
	float calcusum(int a, int b, char sig);
	string combine(string a, string b, char sign);
	string int_string(int number);
	char randop();
private:
	char *p;
	char *pr;
};