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
	outputPath.insert(PathLen - 4, str);  //��������ļ�����  "_out" ��׺
	cout << "New File=" << outputPath << endl;

	ofstream outFile(outputPath, ios::trunc | ios::out);  //ios::trunc��ʾ�ڴ��ļ�ǰ���ļ����,������д��,�ļ��������򴴽�

	//���� ���ַ� д���ļ���
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < BUF[i].size(); j++)
			outFile << BUF[i][j];
		outFile << "\n";
	}
	outFile.close();
}