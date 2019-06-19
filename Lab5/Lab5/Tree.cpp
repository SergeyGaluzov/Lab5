#include "Tree.h"
#include "Elem.h"
#include <iostream>
#include <vector>
#include <map>
double make_math_operation(double left, string data, double right)
{
	if (data == "/") return left / right;
	if (data == "*") return left * right;
	if (data == "-") return left - right;
	if (data == "+") return left + right;
}
Tree::Tree(map <string, double> &database)
{
	top = nullptr;
	this->database = database;
}
Tree::Tree(Elem *top)
{
	this->top = top;
}
void Tree::infix(Elem *top)
{
	if (!top) return;
	infix(top->left);
	//cout << top->data;
	infix(top->right);
}
double Tree::calc_result(Elem *top)
{
	if (!top->left && !top->right)
	{
		if (isdigit(top->data[0]))
		{
			top->result = stoi(top->data);
		}
		else
		{
			top->result = database[top->data];
		}
		return top->result;
	}
	top->result = make_math_operation(calc_result(top->left), top->data, calc_result(top->right));
	return top->result;
}
void Tree::fill_the_tree(vector <Elem *> & list_of_elems)
{
	if (list_of_elems.size() == 1)
	{
		top = list_of_elems[0];
	}
	else
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
					if (list_of_elems.size() == 1)
					{
						break;
					}
					else i -= 2;
				}
			}
		}
	}
}