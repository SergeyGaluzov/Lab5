#pragma once
#include <vector>
#include "Elem.h"
class Tree
{
public:
	Elem *top;
	Tree();
	Tree(Elem *top);
	void fill_the_tree(vector <Elem *> & list_of_elems);
};