#include"head.h"
//ǰ����codefile��Ϊ��
void Print() {
	ifstream finCF("CodeFile.txt", ios::in);
	ofstream foutCP("CodePrint.txt", ios::out);
	if (finCF.peek() == EOF) { cout << "�ļ�CodeFileΪ��!�����ǰ�������ٽ��д�ӡ����" << endl; return; }
	string buffer;
	getline(finCF, buffer);
	finCF.close();
	cout << "CodePrint.txt�ļ���ӡ����:" << endl;
	for (int i = 0; i < buffer.size(); i+=50) {
		cout << buffer.substr(i, 50) << endl;
		foutCP << buffer.substr(i, 50) << endl;
	}
	foutCP.close();
}