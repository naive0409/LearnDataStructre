#include "huffmanTree.h"
#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Huffman HFcode;
	HFcode.init();
	//ACCBBBBAAACBBZABAAAA
	//I love data Structure, I love computer. I will try my best to study data Structure.

	HFcode.CreateHTree();
	HFcode.CreateTable();

	HFcode.Encode();
	

	char* binary = new char[1024];

	cout << "\n\n请输入码文：\n\n";
	cin >> binary;
	
	char* decoded = HFcode.Decode(binary);
	cout <<"\n\n解码结果是：\n\n"<< decoded << '\n';

	delete decoded;

	return 0;
}