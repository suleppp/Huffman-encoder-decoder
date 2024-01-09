#include "head.h"

//ǰ���ǹ����������
void Decoding() {
    if (TreeNodeArray.size() == 0) {
        cout << "��������������!�������ٽ�������!" << endl;
        return;
    }
    ifstream finCF("CodeFile.txt", ios::in);
    if (finCF.is_open() == false) {
        cout << "�ļ�CodeFile.dat��ʧ��" << endl;
        return;
    }

    string buffer, tempBuffer, tranStr = "";
    finCF >> buffer; //��ȡcodefile������Ľ��,codefile��ֻ��һ�б�������
    finCF.close();
    for (int i = 0; i < buffer.size(); i++) {
        tempBuffer += buffer[i];
        for (int j = 1; j <= n; j++) {
            if (tempBuffer == TreeNodeArray[j].coding) {
                tranStr += TreeNodeArray[j].word;
                tempBuffer = ""; //���
                break;
            }
        }
    }
    if (!tempBuffer.empty()) {
        cout << "����ʧ��! '" << tempBuffer << "'û�ж�Ӧ�ַ�!" << endl;
        cout << "��������������Ƿ���ȷ�����������������!" << endl;
        return;
    }

    // ��tranStr�е�����*�滻�ؿո�
    std::replace(tranStr.begin(), tranStr.end(), '*', ' ');

    cout << "��CodeFile.txt�ļ���������������:" << endl;
    cout << tranStr << endl; //��������

    ofstream foutTF("TextFile.txt", ios::out); //TextFile�ļ�ָ��
    if (foutTF.is_open() == false) cout << "�ļ�TextFile.txt��ʧ��" << endl;
    foutTF << tranStr; //д�ļ�
    foutTF.close();
}
