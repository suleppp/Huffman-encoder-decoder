#include"head.h"

int main() {
	    cout << "请输入字符集大小n" << endl;
        cin >> n;
    while (true) {
        char choose;//选择什么操作
        Menu();//显示菜单
        cout << "请输入你想要进行的操作" << endl;
        cin >> choose;
        switch (choose) {
        case 'I': {
	    vector<rawData> data;
	    data.resize(n + 1);
        cout << "请用'*'代替空格" << endl;
	    for (int i = 1; i <= n; i++) {
		    char word; double weight;
		    cout << "请输入字符和权值" << endl;
            cin >> word >> weight;
		    rawData member(word, weight);
		    data[i] = member;
	    }

            Initialization(n,data);
            break;
        }
           
        case 'E'://c创建哈夫曼编码，并且从ToBetran文件中读取的正文进行编码，然后存放于CodeFile文件
            Encoding();
            break;
        case 'D'://对CodeFile文件中的二进制编码进行译码。
            Decoding();
            break;
        case 'P':
            Print();//将CodeFile文件中的数据以50一行在终端进行显示，然后存储进CodePrin文件
            break;
        case 'T': {
            string prefix = "";
            ofstream foutTP("TreePrint.txt", ios::out);
            TreePrinting(2 * n - 1, prefix, foutTP);//打印哈夫曼树
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