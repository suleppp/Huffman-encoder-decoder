#include "head.h"

// 前提哈夫曼表存在
void TreePrinting(int nodeIndex, string prefix, ofstream& foutTP) {
    if (TreeNodeArray.size() == 0) {
        foutTP << "哈夫曼树不在内存中,请完成前序操作后再进行打印哈夫曼树" << endl;
        return;
    }
    //右孩子->当前节点->左孩子
    if (nodeIndex != 0) {
        TreePrinting(TreeNodeArray[nodeIndex].rchild, prefix + " - - -", foutTP);
        cout << prefix << (TreeNodeArray[nodeIndex].word == '\0' ? " " : string(1, TreeNodeArray[nodeIndex].word)) << "(" << TreeNodeArray[nodeIndex].weight << ")" << endl;
        foutTP << prefix << (TreeNodeArray[nodeIndex].word == '\0' ? " " : string(1, TreeNodeArray[nodeIndex].word)) << "(" << TreeNodeArray[nodeIndex].weight << ")" << endl;
        TreePrinting(TreeNodeArray[nodeIndex].lchild, prefix + " - - -", foutTP);
    }
}