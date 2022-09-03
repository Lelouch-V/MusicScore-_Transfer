
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

	//˵��
	input_module.Description();

	//��ȡ�ļ�·��
	inputPath = input_module.InputPath();
	cout << endl;
	//��ȡ�ļ����ݣ������� ����BUF��
	if (!transfer_module.ReadTxt(inputPath, BUF))
	{
		cout << "Read Data success !" << endl;
	}
	else {
		cout << "Open file fail ! Quit ��" << endl;
		goto QUIT;
	}
	cout << endl;
	// ���뵱ǰ�ļ����ֵ�
	for(int i = 0; i < 3;i++ )
	{
		inscalse = input_module.InputScale(inscalse_char);
		if (inscalse == -1)
			cout << "��������ֵ���������3�λ������ԣ�" << endl;
		else
			break;
	}
	cout << endl;
	//����Ҫת�����ֵ�
	for (int i = 0; i < 3; i++)
	{
		outscale = input_module.OutputScale(outscalse_char);
		if (outscale == -1)
			cout << "��Ҫת�����ֵ���������3�λ������ԣ�" << endl;
		else
			break;
	}

	
	//ת��
	transfer_module.Char_Transto_Int(BUF, Transfer);
	transfer_module.Major_Transfer(Transfer, inscalse, outscale);
	transfer_module.Int_Transto_Char(BUF, Transfer);

	//����ļ�
	outputPath = inputPath;
	output_module.OutPutTxt(outputPath, BUF, inscalse_char, outscalse_char);

QUIT:
	system("pause");
	return 0;
}
