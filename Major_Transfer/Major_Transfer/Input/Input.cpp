#include <Input.h>

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
�����ļ�·����
�����ֶ����룬
�ļ����� "\\" ������"\".
���������ļ���
ֱ�����뼴�ɡ�
*/
string InputModule::InputPath()
{
	string InputPath = "";
	cout << "�������ļ�·���������ļ���" << endl;
	cin >> InputPath;

	cout << "�ļ�·��Ϊ��" << endl;
	cout << InputPath << endl;

	return InputPath;
}

/*
���뵱ǰ���ֵ�
*/
int InputModule::InputScale(char &in)
{
	char inputscale;
	int inscale = 0;
	cout << "������A - F �� "<<endl;
	cout << "�����뵱ǰ���׵��ֵ���" << endl;
	cin >> inputscale;
	in = inputscale;
	switch (inputscale)
	{
		case 'C':
		case 'c':
			inscale = scale_1;
			break;
		case 'D':
		case 'd':
			inscale = scale_2;
			break;
		case 'E':
		case 'e':
			inscale = scale_3;
			break;
		case 'F':
		case 'f':
			inscale = scale_4;
			break;
		case 'G':
		case 'g':
			inscale = scale_5;
			break;
		case 'A':
		case 'a':
			inscale = scale_6;
			break;
		case 'B':
		case 'b':
			inscale = scale_7;
			break;
		default:
			inscale = -1;
			break;
	}
	if (inscale == -1)
		return -1;
	else
		return inscale;
}

/*
����Ҫת�����ֵ�
*/
int InputModule::OutputScale(char &out)
{
	char outputscale;
	int outscale = 0;
	cout << "����������ת�����ֵ���" << endl;
	cin >> outputscale;
	out = outputscale;
	switch (outputscale)
	{
	case 'C':
	case 'c':
		outscale = scale_1;
		break;
	case 'D':
	case 'd':
		outscale = scale_2;
		break;
	case 'E':
	case 'e':
		outscale = scale_3;
		break;
	case 'F':
	case 'f':
		outscale = scale_4;
		break;
	case 'G':
	case 'g':
		outscale = scale_5;
		break;
	case 'A':
	case 'a':
		outscale = scale_6;
		break;
	case 'B':
	case 'b':
		outscale = scale_7;
		break;
	default:
		outscale = -1;
		break;
	}
	if (outscale == -1)
		return -1;
	else
		return outscale;

}


void InputModule::Description()
{
	cout << "******************" << endl;
	cout << "���ߣ�Major Transfer" << endl
		<< "version: V1.0" << endl
		<< "���ܣ������״�һ���ֵ�ת����һ���ֵ�" << endl
		<< endl
		<< "ʹ��˵����" << endl
		<< "1. ()��ʾ����" << endl
		<< "2. []��ʾ����" << endl
		<< "3. b��ʾ��������" << endl
		<< "4. #��ʾ��������" << endl
		<< endl
		<< "ע�����" << endl
		<< "1. Ŀǰ��֧�� txt �ļ����� �� ���" << endl
		<< "2. ����˵�txt�ļ��е��޹��ַ�" << endl
		<< "3. �ᱣ��txt �ļ��еĿո�" << endl
		<< "******************" << endl;
}