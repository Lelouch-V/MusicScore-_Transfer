#include "iostream"
#include <stdio.h>
#include <string>

using namespace std;

class InputModule
{
public:
	string InputPath();
	int InputScale(char &in);
	int OutputScale(char &out);
	void Description();
};
