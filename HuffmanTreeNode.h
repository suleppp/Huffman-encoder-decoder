#pragma once
#include<string>
using namespace std;
typedef class HuffmanTreeNode
{
public:
	int id;//���
	double weight;//Ȩ��
	int parent, lchild, rchild;
	char word;//�ַ�
	string coding;//����
	HuffmanTreeNode();
	~HuffmanTreeNode() = default;
}node;


