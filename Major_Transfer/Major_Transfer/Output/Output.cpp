#include "iostream"
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <Output.h>

void OutputModule::OutPutTxt(string outputPath, vector<string> &BUF,char in,char out)
{
	int line = BUF.size();
	string str="_";
	str += in;
	str += "to";
	str += out;
	int PathLen = outputPath.size();
	outputPath.insert(PathLen - 4, str);  //给输出的文件加上  "_out" 后缀
	cout << "New File=" << outputPath << endl;

	ofstream outFile(outputPath, ios::trunc | ios::out);  //ios::trunc表示在打开文件前将文件清空,由于是写入,文件不存在则创建

	//逐行 逐字符 写入文件中
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < BUF[i].size(); j++)
			outFile << BUF[i][j];
		outFile << "\n";
	}
	outFile.close();
}