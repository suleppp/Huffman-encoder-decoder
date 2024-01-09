#include"head.h"

void Initialization(int n, vector<rawData> data) {
	// 预分配空间
	TreeNodeArray.clear();
	TreeNodeArray.resize(2 * n);
	
	for (int i = 1; i <= n; i++) { //填充已知数据
		TreeNodeArray[i].id = i;
		TreeNodeArray[i].word = data[i].word;
		TreeNodeArray[i].weight = data[i].weight;
	}

	for (int i = n + 1; i <= 2 * n - 1; i++) {//构造哈夫曼树
		int son1, son2;
		son1 = choiceMin(i - 1);
		TreeNodeArray[i].lchild = son1;
		son2 = choiceMin(i - 1);
		TreeNodeArray[i].rchild = son2;
		TreeNodeArray[i].weight = TreeNodeArray[son1].weight + TreeNodeArray[son2].weight;
		TreeNodeArray[i].id = i;
	}
	
	//将哈夫曼表的信息写入hfmTree.txt
	ofstream fout;
	fout.open("hfmTree.txt", ios::out);
	cout << "哈夫曼初始化完成!" << endl;
	cout << "序号	" << "字符	" << "权值	" << "父	" << "左	" << "右	 "<<"编码" << endl;
	for (int i = 1; i <= TreeNodeArray.size()-1; i++) {
		fout << TreeNodeArray[i].id << "	" <<TreeNodeArray[i].word<<"	"<<TreeNodeArray[i].weight << "	" << TreeNodeArray[i].parent << "	" << TreeNodeArray[i].lchild << "	" << TreeNodeArray[i].rchild<<"	"<<TreeNodeArray[i].coding<<endl;
		cout << TreeNodeArray[i].id << "	" << TreeNodeArray[i].word << "	" << TreeNodeArray[i].weight << "	" << TreeNodeArray[i].parent << "	" << TreeNodeArray[i].lchild << "	" << TreeNodeArray[i].rchild << "	" << TreeNodeArray[i].coding << endl;
	}
	fout.close();
}
