#include "huffmanTree.h"
#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int choose;//ѡ��
	Huffman HFcode;
	HFcode.init();

	////ACCBBBBAAACBBZABAAAA
	////I love data Structure, I love computer. I will try my best to study data Structure.

	HFcode.CreateHTree();
	HFcode.CreateTable();

	HFcode.Encode();

	do {
		char binary[1024];//����
		cout << "\n\n���������ģ�\n\n";
		cin >> binary;

		char* decoded = HFcode.Decode(binary);
		cout << "\n\n�������ǣ�\n\n" << decoded << "\n\n";

		delete decoded;
		cout << "����0�˳������������ַ��������н��룺\n";
		cin >> choose;
	} while (choose!= 0);

	return 0;
}