#include"head.h"
//前提是codefile不为空
void Print() {
	ifstream finCF("CodeFile.txt", ios::in);
	ofstream foutCP("CodePrint.txt", ios::out);
	if (finCF.peek() == EOF) { cout << "文件CodeFile为空!请完成前序工作后再进行打印操作" << endl; return; }
	string buffer;
	getline(finCF, buffer);
	finCF.close();
	cout << "CodePrint.txt文件打印如下:" << endl;
	for (int i = 0; i < buffer.size(); i+=50) {
		cout << buffer.substr(i, 50) << endl;
		foutCP << buffer.substr(i, 50) << endl;
	}
	foutCP.close();
}