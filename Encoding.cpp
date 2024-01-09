#include"head.h"

void Encoding() {
	if (TreeNodeArray.size() == 0) {
		cout << "��⵽�������������ڴ���,��hfmTree.txt��ȡ" << endl;
		ifstream fin("hfmTree.txt", ios::in);
		if (fin.is_open() == false) cout << "��hfmTee.txtʧ��" << endl;
		if (fin.peek() == EOF) {
			cout << "hfmTree.txtΪ��!���ʼ�����ٽ��б���!" << endl;
			return;
		}
		else {
			TreeNodeArray.resize(2 * n);
			string buffer;
			while (true) {
				node tempNode;
				fin >> tempNode.id >> tempNode.word >> tempNode.weight >> tempNode.parent >> tempNode.lchild >> tempNode.rchild >> tempNode.coding;
				if (fin.fail()) break;
				//cout << tempNode.id << "	" << tempNode.word << "	" << tempNode.weight << "	" << tempNode.parent << "	" << tempNode.lchild << "	" << tempNode.rchild << "	" << tempNode.coding << endl;
				TreeNodeArray[tempNode.id] = tempNode;//����Խ��
			}
		}
		fin.close();
	}

	//���Ե�
	/*for (int i = 0; i <= 2 * n - 1; i++) {
		cout << TreeNodeArray[i].id << "	" << TreeNodeArray[i].word << "	" << TreeNodeArray[i].weight << "	" << TreeNodeArray[i].parent << "	" << TreeNodeArray[i].lchild << "	" << TreeNodeArray[i].rchild << "	" << TreeNodeArray[i].coding << endl;
	}*/


	//��ȡҶ�ӽڵ�Ĳ��ȳ�����
	string code;//�洢���ŵĲ����������Ʊ���
	int cur_par, now;
	for (int i = 1; i <= n; i++) {//��Ҷ�ӽڵ㿪ʼ
		now = i; code = "";
		while (TreeNodeArray[now].parent != 0) {
			cur_par = TreeNodeArray[now].parent;
			if (TreeNodeArray[cur_par].lchild == TreeNodeArray[now].id) code += '0';
			else if (TreeNodeArray[cur_par].rchild == TreeNodeArray[now].id) code += '1';
			now = TreeNodeArray[now].parent;
		}
		reverse(code.begin(), code.end());
		TreeNodeArray[i].coding = code;
		cout << TreeNodeArray[i].word << ":" << code << endl;//����
	}

	//����hfmTree.txt����Ϣ
	ofstream foutHFM("hfmTree.txt", ios::out);
	if (foutHFM.is_open() == false) cout << "��hfmTree.txtʧ��" << endl;
	for (int i = 1; i <= 2*n-1; i++) {
		foutHFM << TreeNodeArray[i].id << "	" << TreeNodeArray[i].word << "	" << TreeNodeArray[i].weight << "	" << TreeNodeArray[i].parent << "	" << TreeNodeArray[i].lchild << "	" << TreeNodeArray[i].rchild << "	" << TreeNodeArray[i].coding << endl;
	}
	foutHFM.close();

	//��ȡ�������ļ�����
	ifstream finTran("ToBeTran.txt", ios::out);
	if (finTran.is_open() == false) cout << "��ToBeTran.txtʧ��" << endl;
	string tran, tempTran;
	while (getline(finTran, tempTran)) {
	tran += tempTran;
	}
	finTran.close();

	// ��tran�е����пո��滻Ϊ*
	replace(tran.begin(), tran.end(), ' ', '*');

	ofstream foutCF("CodeFile.txt", ios::out);//CodeFile�ļ�ָ��
	if (foutCF.is_open() == false) cout << "��CodeFile.txtʧ��" << endl;
	string tranCode = "";
	for (int i = 0; i < tran.size(); i++) {
	bool found = false;
	for (int j = 1; j <= n; j++) {
		if (tran[i] == TreeNodeArray[j].word) {
			tranCode += TreeNodeArray[j].coding;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "Error: Character '" << tran[i] << "' not found in TreeNodeArray." << endl;
		cout << "ToBeTran.txt�ļ�����ʧ��!" << endl; return;
	}
	}

cout << "ToBeTran.txt�ļ�����ɹ�!" << endl;
foutCF << tranCode;//�����д���ļ�
foutCF.close();

}