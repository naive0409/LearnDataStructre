#include "huffmanTree.h"
#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int choose;//选项
	Huffman HFcode;
	HFcode.init();

	////ACCBBBBAAACBBZABAAAA
	////I love data Structure, I love computer. I will try my best to study data Structure.

	HFcode.CreateHTree();
	HFcode.CreateTable();

	HFcode.Encode();

	do {
		char binary[1024];//码文
		cout << "\n\n请输入码文：\n\n";
		cin >> binary;

		char* decoded = HFcode.Decode(binary);
		cout << "\n\n解码结果是：\n\n" << decoded << "\n\n";

		delete decoded;
		cout << "输入0退出，其他任意字符继续进行解码：\n";
		cin >> choose;
	} while (choose!= 0);

	return 0;
}