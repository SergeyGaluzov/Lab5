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
	ofstream output;
	map <string, double> database;
	file.open("file.txt");
	output.open("output.txt");
	while (getline(file, str))
	{
		output << str << endl;
		Tree AST(database);
		vector <Elem *> elems_list = function_of_shunting_yard(str, str_variable, database);
		if (str[str.length() - 1] != '0' || str[str.length() - 2] != '*')
		{
			AST.fill_the_tree(elems_list);
			double res = AST.calc_result(AST.top);
			if (str_variable == "print")
			{
				str.erase(str.begin(), str.begin() + 6);
				output << "\nThe result of operation " << '"' << str << '"' << " is: " << res << endl << endl;
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
		}
		str_variable = "";
	}
	for (auto it = database.begin(); it != database.end(); it++)
	{
		output << it->first << " = " << it->second << endl;
	}
}