#include "head.h"

// ǰ������������
void TreePrinting(int nodeIndex, string prefix, ofstream& foutTP) {
    if (TreeNodeArray.size() == 0) {
        foutTP << "�������������ڴ���,�����ǰ��������ٽ��д�ӡ��������" << endl;
        return;
    }
    //�Һ���->��ǰ�ڵ�->����
    if (nodeIndex != 0) {
        TreePrinting(TreeNodeArray[nodeIndex].rchild, prefix + " - - -", foutTP);
        cout << prefix << (TreeNodeArray[nodeIndex].word == '\0' ? " " : string(1, TreeNodeArray[nodeIndex].word)) << "(" << TreeNodeArray[nodeIndex].weight << ")" << endl;
        foutTP << prefix << (TreeNodeArray[nodeIndex].word == '\0' ? " " : string(1, TreeNodeArray[nodeIndex].word)) << "(" << TreeNodeArray[nodeIndex].weight << ")" << endl;
        TreePrinting(TreeNodeArray[nodeIndex].lchild, prefix + " - - -", foutTP);
    }
}