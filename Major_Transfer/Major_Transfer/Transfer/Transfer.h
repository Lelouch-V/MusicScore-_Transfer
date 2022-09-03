

#include "iostream"
#include <stdio.h>
#include <string>
using namespace std;

class TransferModule
{
public:
	int ReadTxt(string inputPath, vector<string> &BUF);
	void Char_Transto_Int(vector<string> &BUF, vector< vector<pair<int, int>>> &Transfer);
	void Major_Transfer(vector< vector<pair<int, int>>> &Transfer, int InputMajor, int OutputMajor);
	void Int_Transto_Char(vector<string> &BUF, vector< vector<pair<int, int>>> &Transfer);
};
