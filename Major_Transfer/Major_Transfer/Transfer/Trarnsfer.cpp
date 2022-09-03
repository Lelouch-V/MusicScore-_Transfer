
#include "iostream"
#include <stdio.h>
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include <Transfer.h>

#define Debug_Enable 1

/*
1 ReadTxt����ȡtxt�ļ������ַ����ʹ��� BUF ��
2 Char_Transto_Int���� �ַ����͵�BUF ת�� int ���ͣ����жϰ���
3 Major_Transfer:���Ե�ת������ G��תC��
4 Int_Transto_Char: ��������ת�� �ַ����� BUF ��
*/

/*
| C |    | D |    | E | F |    | G |    | A |    | B |
| 1 |    | 2 |    | 3 | 4 |    | 5 |    | 6 |    | 7 |
| 1 | #1 | 2 | #2 | 3 | 4 | #4 | 5 | #5 | 6 | #6 | 7 |
*/


enum scale{
	scale_1,
	scale_b2,	//#1  = b2
	scale_2,
	scale_b3,	//#2 = b3
	scale_3,
	scale_4,
	scale_b5,	//#4 = b5
	scale_5,
	scale_b6,	//#5 = b6
	scale_6,
	scale_b7,	//#6 = b7
	scale_7
};

/*
ת�������е�debug:
��ӡ vector< vector<pair<int, int>>> &Transfer ������
*/
void Debug(vector< vector<pair<int, int>>> &Transfer)
{
	cout << "***************************" << endl;
	int line = Transfer.size();
	cout << "��ӡ Transfer ������" << endl;
	for (int i = 0; i < line; i++)
	{
		cout << "��" << i << "��" << endl;
		for (int j = 0; j < Transfer[i].size(); j++)
		{
			cout << Transfer[i][j].first << " ";
		}
		cout << endl;
		for (int j = 0; j < Transfer[i].size(); j++)
		{
			cout << Transfer[i][j].second << " ";
		}
		cout << endl;
	}
	cout << "***************************" << endl;
	cout <<  endl;
}

/*
��ȡ Txt �ļ���Ϣ
�����������ļ�
�����ݱ��浽BUF��
*/
int TransferModule::ReadTxt(string inputPath, vector<string> &BUF)
{
	int line = 0;
	string str;

	ifstream InputFile(inputPath, ios::in); //Ĭ�ϵĴ򿪷�ʽ����ios::in
	if (InputFile.is_open())
		cout << "Open file success !" << endl;
	else 
		return -1;

	while (getline(InputFile, str))
	{
		if (str.empty())  //���� empty ��
			continue;
		BUF.push_back(str);
		line++;
	}
	
	InputFile.close();
	return 0;
}

/*
������BUF�е����ݵ�char ����
ת����int ���ͱ��浽 Transfer
����������ֵ�ת��
*/
void TransferModule::Char_Transto_Int(vector<string> &BUF, vector< vector<pair<int, int>>> &Transfer)
{
	int line = BUF.size();

	//����ÿһ�� 
	//ɸѡ�����ֲ��֣������� () [] # b
	//ȷ������Ч����
	for (int i = 0; i < line; i++)
	{
		vector<pair<int, int>> trans;
		int length = BUF[i].size();
		for (int j = 0; j < length; j++)
		{
			if (BUF[i][j] == '1')
				trans.push_back(pair<int, int>(0, scale_1));
			else if (BUF[i][j] == '2')
				trans.push_back(pair<int, int>(0, scale_2));
			else if (BUF[i][j] == '3')
				trans.push_back(pair<int, int>(0, scale_3));
			else if (BUF[i][j] == '4')
				trans.push_back(pair<int, int>(0, scale_4));
			else if (BUF[i][j] == '5')
				trans.push_back(pair<int, int>(0, scale_5));
			else if (BUF[i][j] == '6')
				trans.push_back(pair<int, int>(0, scale_6));
			else if (BUF[i][j] == '7')
				trans.push_back(pair<int, int>(0, scale_7));
			else if (BUF[i][j] == ' ')
				trans.push_back(pair<int, int>(0, -1));
		}
		Transfer.push_back(trans);
	}

#ifdef Debug_Enable
	cout << "[Debug] [Char_Transto_Int] ת��1" << endl;
	Debug(Transfer);
#endif

	for (int i = 0; i < line; i++)
	{
		int flag = 0;
		int ptr = 0;
		int length = BUF[i].size();
		for (int j = 0; j < length; j++)
		{


			if (BUF[i][j] == '(')
				flag--;
			else if (BUF[i][j] == ')')
				flag++;

			if (flag == 0 && ('0' < BUF[i][j] && BUF[i][j] < '8'))
				ptr++;
			if (flag == 0 && (BUF[i][j] == ')'))
				ptr++;
			if (BUF[i][j] == ' ')
				ptr++;

			else if (BUF[i][j] == '#')
				Transfer[i][ptr].second++;

			else if (BUF[i][j] == 'b')
				Transfer[i][ptr].second--;

			else if (BUF[i][j] == '(')
				Transfer[i][ptr].first--;

			else if (BUF[i][j] == '[')
				Transfer[i][ptr].first++;


		}
	}

#ifdef Debug_Enable
	cout << "[Debug] [Char_Transto_Int] ת��2" << endl;
	Debug(Transfer);
#endif

}

/*
����
��һ���ֵ�ת����һ���ֵ�
*/
void TransferModule::Major_Transfer(vector< vector<pair<int, int>>> &Transfer, int InputMajor, int OutputMajor)
{
	int diff = OutputMajor - InputMajor;
	int line = Transfer.size();

#ifdef Debug_Enable
	cout << "[Debug] [Major_Transfer] Before Transfer" << endl;
	Debug(Transfer);
#endif

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < Transfer[i].size(); j++)
		{
			int tmp = 0;
			tmp = Transfer[i][j].second;

			if (tmp == -1)  //�����ո�
				continue;

			if ((tmp + diff) < 0)
			{
				Transfer[i][j].second = (tmp + 12 + diff) % 12;
				Transfer[i][j].first--;
			}
			else if (0 <= (tmp + diff) && (tmp + diff) <12)
			{
				Transfer[i][j].second = tmp + diff;
			}
			else if (12 <= (tmp + diff))
			{
				Transfer[i][j].second = (tmp + diff) % 12;
				Transfer[i][j].first++;
			}

		}
	}
#ifdef Debug_Enable
	cout << "[Debug] [Major_Transfer] After Transfer" << endl;
	Debug(Transfer);
#endif

}

/*
�� int ���͵��ֽ�ת�� char ����
*/
string TransferToScale(int scale)
{
	string str = "";
	switch (scale)
	{
	case -1:
		str += " ";
		break;
	case scale_1:
		str += "1";
		break;
	case scale_b2:	//#1  = b2
		str += "#1";
		break;
	case scale_2:
		str += "2";
		break;
	case scale_b3:	//#2 = b3
		str += "#2";
		break;
	case scale_3:
		str += "3";
		break;
	case scale_4:
		str += "4";
		break;
	case scale_b5:	//#4 = b5
		str += "#4";
		break;
	case scale_5:
		str += "5";
		break;
	case scale_b6:	//#5 = b6
		str += "#5";
		break;
	case scale_6:
		str += "6";
		break;
	case scale_b7:	//#6 = b7
		str += "#6";
		break;
	case scale_7:
		str += "7";
		break;
	default:
		break;
	}
	return str;
}

/*
�� int ���͵���������ת�� char ���ͣ����BUF
*/
void TransferModule::Int_Transto_Char(vector<string> &BUF, vector< vector<pair<int, int>>> &Transfer)
{
	
	int line = Transfer.size(); 
	BUF.clear();
	
	for (int i = 0; i < line; i++)
	{	
		string str = "";
		for (int j = 0; j < Transfer[i].size(); j++)
		{
			int tmp = Transfer[i][j].first;
			int val = Transfer[i][j].second;
			if (tmp < 0)
			{
				int flag = tmp;
				while (flag != 0)
				{
					str += '(';
					flag++;
				}

				str += TransferToScale(val);

				while (flag != tmp)
				{
					str += ')';
					flag--;
				}
			}

			if (tmp > 0)
			{
				int flag = tmp;
				while (flag != 0)
				{
					str += '[';
					flag--;
				}

				str += TransferToScale(val);

				while (flag != tmp)
				{
					str += ']';
					flag++;
				}
			}

			if (tmp == 0)
			{
				str += TransferToScale(val);
			}	
		}
		BUF.push_back(str);
	}
}
