#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;


struct HNode
{
	short weight, parent, lchild, rchild;
};

struct HCode
{
	char data;
	char code[10];
};

class Huffman
{
private:
	HNode* HTree;
	HCode* HCodeTable;
	char str[1024];//输入的字符串
	char leaf[256];//叶子节点对应的字符
	int a[256];//记录每个出现字符的个数

	void code(int i, string newcode);

public:
	int n;//叶子节点数
	int N;
	void init();
	void CreateHTree(/*int a[], int n, char name[]*/);
	void SelectMin(int& x, int& y, int s, int e);
	
	void CreateTable();
	void Encode();
	char* Decode(char* s);
	void Print(int i, int m);


	~Huffman();
};

void Huffman::init()
{
	cout << "请输入字符串用于创建哈夫曼树：\n";
	int nNum[256] = { 0 };
	int ch = cin.get();
	int i = 0;
	while ((ch != '\r') && (ch != '\n'))
	{
		nNum[ch]++;
		str[i++] = ch;
		ch = cin.get();
	}
	n = 0;
	for (i=0;i<256;i++)
	{
		if (nNum[i]>0)
		{
			leaf[n] = (char)i;
			a[n] = nNum[i];
			n++;
		}
	}
}

void Huffman::SelectMin(int& x, int& y, int s, int e)
{
	int i;
	for (i=s;i<=e;i++)
	{
		if (HTree[i].parent==-1)
		{
			x = y = i;
			break;
		}
	}
	for (;i<e;i++)
	{
		if (HTree[i].parent == -1)
		{
			if (HTree[i].weight<HTree[x].weight)
			{
				y = x; x = i;
			}
			else if((x==y)||(HTree[i].weight < HTree[y].weight))
			{
				y = i;
			}
		}
	}
}

void Huffman::CreateHTree()
{
	N = n;
	HCodeTable = new HCode[N];
	HTree = new HNode[2 * N - 1];
	for (int i = 0;i<N;i++)
	{
		HTree[i].weight = a[i];
		HTree[i].lchild = HTree[i].rchild = HTree[i].parent = -1;
		HCodeTable[i].data = leaf[i];
	}

	int x, y;
	for (int i = n ; i < 2 * N - 1 ; i++)
	{
		SelectMin(x, y, 0, i);
		HTree[x].parent = HTree[y].parent = i;
		HTree[i].weight = HTree[x].weight + HTree[y].weight;
		HTree[i].lchild = x;
		HTree[i].rchild = y;
		HTree[i].parent = -1;

	}
	//打印权值表
	cout << "\n权值表如下：\n";
	cout << '\t'
		<< "weight" << '\t'
		<< "lchild" << '\t'
		<< "rchild" << '\t'
		<< "parent" << '\n';


	for (int i = 0; i < 2 * N - 1; i++)
	{

		cout<< i << '\t'
			<< HTree[i].weight << '\t'
			<< HTree[i].lchild << '\t'
			<< HTree[i].rchild << '\t'
			<< HTree[i].parent << '\t' << '\n';
	}

	cout << "\n\n\n";
}

void Huffman::code(int i, string newcode)
{
	if (HTree[i].lchild == -1)
	{
		strcpy(HCodeTable[i].code , newcode.c_str() );
		return;
	}
	code(HTree[i].lchild, newcode + "0");
	code(HTree[i].rchild, newcode + "1");

}

void Huffman::CreateTable()
{
	code(2 * n - 2, "");
	cout << "\n编码表如下：\n";
	cout << '\t'
		<< "字符" << '\t'
		<< "编码" << '\n';
	for (int i = n; i <= 2 * N - 1; i++)
	{

		cout << i-n << '\t' << HCodeTable[i - n].data << '\t'
			<< HCodeTable[i - n].code << '\n';
	}
	cout << "\n\n\n";
}

char* Huffman::Decode(char* s)
{
	char* d = new char[256];
	char* decoded = d;
	while (*s!='\0')
	{
		int parent = 2 * N - 2;
		while (HTree[parent].lchild!=-1)
		{
			if (*s=='0')
			{
				parent = HTree[parent].lchild;
			}
			else
			{
				parent = HTree[parent].rchild;
			}
			s++;
		}
		*d = HCodeTable[parent].data;
		d++;//d会移动，加一个固定的指针decoded
	}
	*d = '\0';//加个结束符，输出用
	return decoded;
}

void Huffman::Encode()
{
	char* s = str;
	char* result = new char[8192];
	
	while (*s != '\0')
	{
		for (int j = 0; j < n; j++) {
			if (*s == HCodeTable[j].data)
			{
				cout << HCodeTable[j].code;
				//strcat( result,HCodeTable[j].code);
			}
		}
		s++;
	}
	cout << '\n';
}

Huffman::~Huffman()
{
	delete[]HTree;
	delete[]HCodeTable;
}