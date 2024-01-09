#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include"HuffmanTreeNode.h"
#include"rawData.h"
using namespace std;

extern int n;
extern vector<node> TreeNodeArray;

void Initialization(int n,vector<rawData> data);
int choiceMin(int n);
void Encoding();
void Decoding();
void Print();
void TreePrinting(int nodeIndex,string prefix, ofstream& foutTP);
void Menu();