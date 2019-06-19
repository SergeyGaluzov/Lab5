#include <iostream>
#include <vector>
#include <map>
#include "Elem.h"
#include "Tree.h"
#include "Shunting_yard.h"
using namespace std;
int main()
{
	Tree AST;
	vector <Elem *> elems_list = function();
	AST.fill_the_tree(elems_list);
	double res = AST.calc_result(AST.top);
	cout << '\n' << res << endl;
}