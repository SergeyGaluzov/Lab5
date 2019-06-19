#pragma once
#include <string>
#include "Elem.h"
using namespace std;
Elem::Elem(string name)
{
	data = name;
	left = nullptr;
	right = nullptr;
	result = 0;
}
Elem::Elem(char name)
{
	data = name;
	left = nullptr;
	right = nullptr;
}