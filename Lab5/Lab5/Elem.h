#pragma once
#include <string>
using namespace std;
class Elem
{
public:
	//friend class Tree;
	Elem(string name);
	Elem(char name);
	Elem *left;
	Elem *right;
	string data;
	double result;
};
