#include "head.h"

//前提是哈夫曼表存在
void Decoding() {
    if (TreeNodeArray.size() == 0) {
        cout << "哈夫曼树不存在!请编码后再进行译码!" << endl;
        return;
    }
    ifstream finCF("CodeFile.txt", ios::in);
    if (finCF.is_open() == false) {
        cout << "文件CodeFile.dat打开失败" << endl;
        return;
    }

    string buffer, tempBuffer, tranStr = "";
    finCF >> buffer; //获取codefile中译码的结果,codefile中只有一行编码数据
    finCF.close();
    for (int i = 0; i < buffer.size(); i++) {
        tempBuffer += buffer[i];
        for (int j = 1; j <= n; j++) {
            if (tempBuffer == TreeNodeArray[j].coding) {
                tranStr += TreeNodeArray[j].word;
                tempBuffer = ""; //清空
                break;
            }
        }
    }
    if (!tempBuffer.empty()) {
        cout << "解码失败! '" << tempBuffer << "'没有对应字符!" << endl;
        cout << "请检查哈夫曼编码是否正确或其他错误后再译码!" << endl;
        return;
    }

    // 将tranStr中的所有*替换回空格
    std::replace(tranStr.begin(), tranStr.end(), '*', ' ');

    cout << "对CodeFile.txt文件进行译码结果如下:" << endl;
    cout << tranStr << endl; //测试数据

    ofstream foutTF("TextFile.txt", ios::out); //TextFile文件指针
    if (foutTF.is_open() == false) cout << "文件TextFile.txt打开失败" << endl;
    foutTF << tranStr; //写文件
    foutTF.close();
}
