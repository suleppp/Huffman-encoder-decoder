#include"head.h"

int choiceMin(int n) {//返回vector里面的权值最小节点的下标
	double cur_min_weight=0x3f3f3f3f;
	int cur_min_idex=1;
	for (int i = 1; i <=n; i++) {
		if (TreeNodeArray[i].parent == 0) {
			if (TreeNodeArray[i].weight < cur_min_weight) {
				cur_min_weight = TreeNodeArray[i].weight;
				cur_min_idex = i;
			}
		}
	}
	TreeNodeArray[cur_min_idex].parent =n+ 1;
	return cur_min_idex;
}


