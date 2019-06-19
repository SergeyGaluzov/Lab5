#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "Elem.h"
#include "Tree.h"
#include "Shunting_yard.h"
using namespace std;
int main()
{
	string str, str_variable;
	ifstream file;
	map <string, double> database;
	file.open("file.txt");
	while (getline(file, str))
	{
		cout << str << endl;
		Tree AST(database);
		vector <Elem *> elems_list = function_of_shunting_yard(str, str_variable);
		AST.fill_the_tree(elems_list);
		double res = AST.calc_result(AST.top);
		if (str_variable == "print")
		{
			str.erase(str.begin(), str.begin() + 6);
			cout << "\nThe result of operation " << '"' << str << '"' << " is: " << res << endl << endl;
		}
		else
		{
			bool t = false;
			for (auto it = database.begin(); it != database.end(); it++)
			{
				if (str_variable == it->first)
				{
					t = true;
					database[str_variable] = res;
					break;
				}
			}
			if (!t) database.insert(make_pair(str_variable, res));
		}
		str_variable = "";
	}
	for (auto it = database.begin(); it != database.end(); it++)
	{
		cout << it->first << " = " << it->second << endl;
	}
}