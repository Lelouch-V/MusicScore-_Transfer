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
输入文件路径，
若是手动输入，
文件夹用 "\\" 而不是"\".
若是拖入文件，
直接拖入即可。
*/
string InputModule::InputPath()
{
	string InputPath = "";
	cout << "请输入文件路径或拖入文件：" << endl;
	cin >> InputPath;

	cout << "文件路径为：" << endl;
	cout << InputPath << endl;

	return InputPath;
}

/*
输入当前的乐调
*/
int InputModule::InputScale(char &in)
{
	char inputscale;
	int inscale = 0;
	cout << "乐谱有A - F 调 "<<endl;
	cout << "请输入当前乐谱的乐调：" << endl;
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
输入要转换的乐调
*/
int InputModule::OutputScale(char &out)
{
	char outputscale;
	int outscale = 0;
	cout << "请输入您想转换的乐调：" << endl;
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
	cout << "工具：Major Transfer" << endl
		<< "version: V1.0" << endl
		<< "功能：将乐谱从一个乐调转成另一个乐调" << endl
		<< endl
		<< "使用说明：" << endl
		<< "1. ()表示低音" << endl
		<< "2. []表示高音" << endl
		<< "3. b表示降半音阶" << endl
		<< "4. #表示升半音阶" << endl
		<< endl
		<< "注意事项：" << endl
		<< "1. 目前仅支持 txt 文件输入 和 输出" << endl
		<< "2. 会过滤掉txt文件中的无关字符" << endl
		<< "3. 会保留txt 文件中的空格" << endl
		<< "******************" << endl;
}