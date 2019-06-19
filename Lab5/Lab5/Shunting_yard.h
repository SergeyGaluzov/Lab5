#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include "Elem.h"
#include "Tree.h"
using namespace std;
int priority(char symbol)
{
	switch (symbol)
	{
	case '(':
		return 0;
	case ')':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	};
}
vector <Elem *> function_of_shunting_yard(string &str, string &str_variable)
{
	string str_RPN;
	bool expression = false;
	stack <char> stack_of_operators;
	queue <char> queue_of_operands;
	vector <Elem*> list_of_elems;
	string temp_name;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != '=' && !expression && isalpha(str[i]))
		{
			str_variable += str[i];
			continue;
		}
		if (str[i] == '=')
		{
			expression = true;
			continue;
		}
		if (!isalnum(str[i]))
		{
			if (!temp_name.empty())
			{
				str_RPN += temp_name;
				list_of_elems.push_back(new Elem(temp_name));
				temp_name = "";
			}
			switch (str[i])
			{
			case '(':
			{	stack_of_operators.push(str[i]);
			break;
			}
			case ')':
			{
				while (stack_of_operators.top() != '(')
				{
					str_RPN += stack_of_operators.top();
					list_of_elems.push_back(new Elem(stack_of_operators.top()));
					stack_of_operators.pop();
				}
				stack_of_operators.pop();
				break;
			}
			default:
			{
				if (str[i] != ' ')
				{
					if (stack_of_operators.empty())
					{
						stack_of_operators.push(str[i]);
						continue;
					}
					if (priority(str[i]) <= priority(stack_of_operators.top()))
					{
						while (priority(str[i]) <= priority(stack_of_operators.top()))
						{
							str_RPN += stack_of_operators.top();
							list_of_elems.push_back(new Elem(stack_of_operators.top()));
							stack_of_operators.pop();
							if (stack_of_operators.empty()) break;
						}
						stack_of_operators.push(str[i]);
					}
					else stack_of_operators.push(str[i]);
					break;
				}
			}
			};
		}
		else
		{
			temp_name += str[i];
			if (i == str.length() - 1)
			{
				str_RPN += temp_name;
				list_of_elems.push_back(new Elem(temp_name));
				temp_name = "";
			}
		}
	}
	while (!stack_of_operators.empty())
	{
		str_RPN += stack_of_operators.top();
		list_of_elems.push_back(new Elem(stack_of_operators.top()));
		stack_of_operators.pop();
	}
	//cout << str_RPN << endl;
	return list_of_elems;
}