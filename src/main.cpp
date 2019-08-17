//============================
//===【main.cpp】
//============================
//===   エントリーポイント(仮説明)
//============================
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int	main(void)
{
	string inputStr;
	string	className;
	//■■■■■■■■■■■■■//
	//■■■【ファイル名】■■■//
	//■■■■■■■■■■■■■//
	cout << "クラス名を入力して下さい" << endl;
	cin >> className;

	ofstream header(className + ".h");
	ofstream source(className + ".cpp");
	header << "//=========================="<<endl;
	header << "//===【" << className << ".h" << "】" << endl;
	header << "//==========================" << endl;

	source << "//==========================" << endl;
	source << "//===【" << className << ".cpp" << "】" << endl;
	source << "//==========================" << endl;

	//■■■■■■■■■■■■■■//
	//■■■【ファイル説明】■■■//
	//■■■■■■■■■■■■■■//
	cout << "クラスの説明を入力して下さい" << endl;
	cout << "記述終了時には endof と入力して下さい" << endl;

	vector <string> multiLineStr;
	//▼▼▼入力中▼▼▼//
	while (1)
	{
		cin >> inputStr;
		if (inputStr == "endof")
		{
			break;
		}
		multiLineStr.push_back(inputStr);
	}
	//▼▼▼本体▼▼▼//
	for (int i = 0; i < multiLineStr.size(); i++)
	{
		header << "//    " + multiLineStr[i]<<endl;
	}
	//▼▼▼終了行▼▼▼//
	header << "//==========================" << endl;

	//▼▼▼本体▼▼▼//
	for (int i = 0; i < multiLineStr.size(); i++)
	{
		source << "//    " + multiLineStr[i] << endl;
	}
	//▼▼▼終了行▼▼▼//
	source << "//==========================" << endl << endl;

	//■■■■■■■■■■■■■■■■■//
	//■■■【ヘッダ情報コメント】■■■//
	//■■■■■■■■■■■■■■■■■//
	header << "#pragma" << "\t" << "once" << endl;
	header << "//=====================//"	<< endl;
	header << "//===【インクルード記述】 ===//"	<< endl;
	header << "//=====================//"	<< endl;
	source << "//=====================//"	<< endl;
	source << "//===【インクルード記述】 ===//"	<< endl;
	source << "//=====================//"	<< endl;

	//■■■■■■■■■■■■■//
	//■■■【ヘッダ構築】■■■//
	//■■■■■■■■■■■■■//
	//▼▼▼【名前空間】▼▼▼//
	header << "namespace" << "\t" << "OGL" << endl<<"{"<<endl;
	//▼▼▼【クラス】▼▼▼//
	header << "\t" << "class" << "\t" << className << endl<<"\t"<<"{"<<endl;
	//▼▼▼【public】▼▼▼//
	header << "\t" << "public:" << endl;
	header << "\t\t" << className << "();" << endl;
	header << "\t\t" << "~"<<className << "();" << endl;
	//▼▼▼【private】▼▼▼//
	header << "\t" << "private:" << endl;
	//▼▼▼【endof_クラス】▼▼▼//
	header << "\t" << "};" << "\t" << "//EndOf__class_"<<className << endl;
	//▼▼▼【endof_名前空間】▼▼▼//
	header << "}" << "\t" << "//EndOf__namespace_OGL" << endl;
	
	//■■■■■■■■■■■■■//
	//■■■【ソース構築】■■■//
	//■■■■■■■■■■■■■//
	source << "#include" << "\t" << '"' << className << ".h" << '"' << endl<<endl;
	source << "OGL::" << className << "::" << className << "()" << endl<<"{"<<endl<<"}"<<endl<<endl;
	source << "OGL::" << className << "::~" << className << "()" << endl << "{" << endl << "}" << endl << endl;
}