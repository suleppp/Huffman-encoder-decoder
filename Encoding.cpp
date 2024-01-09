#include"head.h"

void Encoding() {
	if (TreeNodeArray.size() == 0) {
		cout << "检测到哈夫曼树不在内存中,从hfmTree.txt读取" << endl;
		ifstream fin("hfmTree.txt", ios::in);
		if (fin.is_open() == false) cout << "打开hfmTee.txt失败" << endl;
		if (fin.peek() == EOF) {
			cout << "hfmTree.txt为空!请初始化后再进行编码!" << endl;
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
				TreeNodeArray[tempNode.id] = tempNode;//测试越界
			}
		}
		fin.close();
	}

	//测试点
	/*for (int i = 0; i <= 2 * n - 1; i++) {
		cout << TreeNodeArray[i].id << "	" << TreeNodeArray[i].word << "	" << TreeNodeArray[i].weight << "	" << TreeNodeArray[i].parent << "	" << TreeNodeArray[i].lchild << "	" << TreeNodeArray[i].rchild << "	" << TreeNodeArray[i].coding << endl;
	}*/


	//获取叶子节点的不等长编码
	string code;//存储符号的不定长二进制编码
	int cur_par, now;
	for (int i = 1; i <= n; i++) {//从叶子节点开始
		now = i; code = "";
		while (TreeNodeArray[now].parent != 0) {
			cur_par = TreeNodeArray[now].parent;
			if (TreeNodeArray[cur_par].lchild == TreeNodeArray[now].id) code += '0';
			else if (TreeNodeArray[cur_par].rchild == TreeNodeArray[now].id) code += '1';
			now = TreeNodeArray[now].parent;
		}
		reverse(code.begin(), code.end());
		TreeNodeArray[i].coding = code;
		cout << TreeNodeArray[i].word << ":" << code << endl;//测试
	}

	//更新hfmTree.txt的信息
	ofstream foutHFM("hfmTree.txt", ios::out);
	if (foutHFM.is_open() == false) cout << "打开hfmTree.txt失败" << endl;
	for (int i = 1; i <= 2*n-1; i++) {
		foutHFM << TreeNodeArray[i].id << "	" << TreeNodeArray[i].word << "	" << TreeNodeArray[i].weight << "	" << TreeNodeArray[i].parent << "	" << TreeNodeArray[i].lchild << "	" << TreeNodeArray[i].rchild << "	" << TreeNodeArray[i].coding << endl;
	}
	foutHFM.close();

	//获取待翻译文件数据
	ifstream finTran("ToBeTran.txt", ios::out);
	if (finTran.is_open() == false) cout << "打开ToBeTran.txt失败" << endl;
	string tran, tempTran;
	while (getline(finTran, tempTran)) {
	tran += tempTran;
	}
	finTran.close();

	// 将tran中的所有空格替换为*
	replace(tran.begin(), tran.end(), ' ', '*');

	ofstream foutCF("CodeFile.txt", ios::out);//CodeFile文件指针
	if (foutCF.is_open() == false) cout << "打开CodeFile.txt失败" << endl;
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
		cout << "ToBeTran.txt文件编码失败!" << endl; return;
	}
	}

cout << "ToBeTran.txt文件编码成功!" << endl;
foutCF << tranCode;//将结果写入文件
foutCF.close();

}