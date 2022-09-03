
#include "iostream"
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>

#include <Input.h>
#include <Transfer.h>
#include <Output.h>

using namespace std;

/*
| C |    | D |    | E | F |    | G |    | A |    | B |
| 1 |    | 2 |    | 3 | 4 |    | 5 |    | 6 |    | 7 |
| 1 | #1 | 2 | #2 | 3 | 4 | #4 | 5 | #5 | 6 | #6 | 7 |
*/


int main()
{
	InputModule input_module;
	OutputModule output_module;
	TransferModule transfer_module;

	string inputPath;
	string outputPath;
	char inscalse_char;
	int inscalse = 0;
	char outscalse_char;
	int outscale = 0;
	vector<string> BUF;
	vector< vector<pair<int, int>>> Transfer;

	//说明
	input_module.Description();

	//获取文件路径
	inputPath = input_module.InputPath();
	cout << endl;
	//读取文件内容，并存入 数组BUF中
	if (!transfer_module.ReadTxt(inputPath, BUF))
	{
		cout << "Read Data success !" << endl;
	}
	else {
		cout << "Open file fail ! Quit ！" << endl;
		goto QUIT;
	}
	cout << endl;
	// 输入当前文件的乐调
	for(int i = 0; i < 3;i++ )
	{
		inscalse = input_module.InputScale(inscalse_char);
		if (inscalse == -1)
			cout << "您输入的乐调有误，您有3次机会重试：" << endl;
		else
			break;
	}
	cout << endl;
	//输入要转换的乐调
	for (int i = 0; i < 3; i++)
	{
		outscale = input_module.OutputScale(outscalse_char);
		if (outscale == -1)
			cout << "您要转换的乐调有误，您有3次机会重试：" << endl;
		else
			break;
	}

	
	//转换
	transfer_module.Char_Transto_Int(BUF, Transfer);
	transfer_module.Major_Transfer(Transfer, inscalse, outscale);
	transfer_module.Int_Transto_Char(BUF, Transfer);

	//输出文件
	outputPath = inputPath;
	output_module.OutPutTxt(outputPath, BUF, inscalse_char, outscalse_char);

QUIT:
	system("pause");
	return 0;
}
