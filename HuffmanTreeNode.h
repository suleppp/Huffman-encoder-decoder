#pragma once
#include<string>
using namespace std;
typedef class HuffmanTreeNode
{
public:
	int id;//ĞòºÅ
	double weight;//È¨ÖØ
	int parent, lchild, rchild;
	char word;//×Ö·û
	string coding;//±àÂë
	HuffmanTreeNode();
	~HuffmanTreeNode() = default;
}node;


