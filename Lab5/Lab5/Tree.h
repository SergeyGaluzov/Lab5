#pragma once
#include <vector>
#include "Elem.h"
#include <map>
class Tree
{
public:
	Elem *top;
	map <string, double> database;
	Tree(map <string, double> &database);
	Tree(Elem *top);
	void infix(Elem *top);
	double calc_result(Elem *top);
	void fill_the_tree(vector <Elem *> & list_of_elems);
};