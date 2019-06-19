#include "Tree.h"
#include "Elem.h"
#include <iostream>
#include <vector>
double make_math_operation(double left, string data, double right)
{
	if (data == "/") return left / right;
	if (data == "*") return left * right;
	if (data == "-") return left - right;
	if (data == "+") return left + right;
}
double Tree::calc_result(Elem *top)
{
	if (!top->left && !top->right)
	{
		top->result = stoi(top->data);
		return top->result;
	}
	top->result = make_math_operation(calc_result(top->left), top->data, calc_result(top->right));
	return top->result;
}
Tree::Tree()
{
	top = nullptr;
}
Tree::Tree(Elem *top)
{
	this->top = top;
}
void Tree::fill_the_tree(vector <Elem *> & list_of_elems)
{
	while (list_of_elems.size() != 1)
	{
		for (int i = 0; i < list_of_elems.size() - 2; i++)
		{
			if (!(isalnum(list_of_elems[i]->data[0]) && isalnum(list_of_elems[i + 1]->data[0]) && isalnum(list_of_elems[i + 2]->data[0])) && !isalnum(list_of_elems[i + 2]->data[0]))
			{
				top = list_of_elems[i + 2];
				top->left = list_of_elems[i];
				top->right = list_of_elems[i + 1];
				list_of_elems.erase(list_of_elems.begin() + i);
				list_of_elems.erase(list_of_elems.begin() + i);
				break;
			}
		}
	}
}