#include"head.h"

int main() {
	    cout << "�������ַ�����Сn" << endl;
        cin >> n;
    while (true) {
        char choose;//ѡ��ʲô����
        Menu();//��ʾ�˵�
        cout << "����������Ҫ���еĲ���" << endl;
        cin >> choose;
        switch (choose) {
        case 'I': {
	    vector<rawData> data;
	    data.resize(n + 1);
        cout << "����'*'����ո�" << endl;
	    for (int i = 1; i <= n; i++) {
		    char word; double weight;
		    cout << "�������ַ���Ȩֵ" << endl;
            cin >> word >> weight;
		    rawData member(word, weight);
		    data[i] = member;
	    }

            Initialization(n,data);
            break;
        }
           
        case 'E'://c�������������룬���Ҵ�ToBetran�ļ��ж�ȡ�����Ľ��б��룬Ȼ������CodeFile�ļ�
            Encoding();
            break;
        case 'D'://��CodeFile�ļ��еĶ����Ʊ���������롣
            Decoding();
            break;
        case 'P':
            Print();//��CodeFile�ļ��е�������50һ�����ն˽�����ʾ��Ȼ��洢��CodePrin�ļ�
            break;
        case 'T': {
            string prefix = "";
            ofstream foutTP("TreePrint.txt", ios::out);
            TreePrinting(2 * n - 1, prefix, foutTP);//��ӡ��������
            foutTP.close();
            break;
        }
            
        case 'Q':
            exit(0);
        default:
            break;
        }
    }
    return 0;

}