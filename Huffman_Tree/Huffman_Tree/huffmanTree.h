#pragma once
#pragma warning(disable:4996)//�õ���strcpy()
#include <iostream>
#include <string>
using namespace std;

struct HNode
{
	short weight, parent, lchild, rchild;
};

struct HCode
{
	char data;//a b c ���ַ�
	char code[10];//����������
};

class Huffman
{
private:
	HNode* HTree;
	HCode* HCodeTable;
	char str[1024];//������ַ���
	char leaf[256];//Ҷ�ӽڵ��Ӧ���ַ�
	int a[256];//��¼ÿ�������ַ��ĸ���

	void code(int i, string newcode);//�ݹ麯�������ɱ���

public:
	int n;//Ҷ�ӽڵ���
	void init();//��ʼ���������ַ���ͳ����Ƶ
	void CreateHTree();//��������������Ȩֵ��
	void SelectMin(int& x, int& y, int s, int e);//ѡ��������С��
	
	void CreateTable();//���������
	void Encode();//�����ʼ������ַ���
	char* Decode(char* s);//���ܸ������ַ���

	~Huffman();//����
};

void Huffman::init()
{
	cout << "�������ַ������ڴ�������������\n";
	int nNum[256] = { 0 };//ͳ��Ƶ��
	int ch = cin.get();//ÿ���ַ�
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
			leaf[n] = (char)i;//Ҷ�ڵ��ַ�,û�г��ֵ��ַ���ͳ��
			a[n] = nNum[i];//�Լ���Ӧ��Ƶ��
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
	HCodeTable = new HCode[n];
	HTree = new HNode[2 * n - 1];
	for (int i = 0;i<n;i++)
	{
		HTree[i].weight = a[i];
		HTree[i].lchild = HTree[i].rchild = HTree[i].parent = -1;
		HCodeTable[i].data = leaf[i];
	}

	int x, y;
	for (int i = n ; i < 2 * n - 1 ; i++)
	{
		SelectMin(x, y, 0, i);
		HTree[x].parent = HTree[y].parent = i;
		HTree[i].weight = HTree[x].weight + HTree[y].weight;
		HTree[i].lchild = x;
		HTree[i].rchild = y;
		HTree[i].parent = -1;

	}

	//��ӡȨֵ��
	cout << "\nȨֵ�����£�\n";
	cout << '\t'
		<< "weight" << '\t'
		<< "lchild" << '\t'
		<< "rchild" << '\t'
		<< "parent" << '\n';


	for (int i = 0; i < 2 * n - 1; i++)
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
	if (HTree[i].lchild == -1)//ֱ��û��������,�����ڴ������Ҷ�ӽڵ�
	{
		strcpy(HCodeTable[i].code , newcode.c_str() );
		return;
	}
	code(HTree[i].lchild, newcode + "0");//�ݹ鴦��������
	code(HTree[i].rchild, newcode + "1");//�ݹ鴦��������

}

void Huffman::CreateTable()
{
	code(2 * n - 2, "");
	cout << "\n��������£�\n";
	cout << '\t'
		<< "�ַ�" << '\t'
		<< "����" << '\n';
	for (int i = n; i <= 2 * n - 1; i++)
	{

		cout << i-n << '\t' << HCodeTable[i - n].data << '\t'
			<< HCodeTable[i - n].code << '\n';
	}
	cout << "\n\n\n";
}

char* Huffman::Decode(char* s)
{
	char* d = new char[256];//���ڴ�Ž��
	char* decoded = d;//d���ƶ�����һ���̶���ָ��decoded
	while (*s!='\0')
	{
		int parent = 2 * n - 2;
		while (HTree[parent].lchild!=-1)
		{
			if (*s=='0')
			{
				parent = HTree[parent].lchild;//parent�������ƶ�,�����ҵ�Ҷ�ӽڵ�
			}
			else
			{
				parent = HTree[parent].rchild;
			}
			s++;
		}
		*d = HCodeTable[parent].data;//��ȡ��Ӧ�ĵ����ַ�
		d++;//d���ƶ�����һ���̶���ָ��decoded
	}
	*d = '\0';//�Ӹ��������������
	return decoded;
}

void Huffman::Encode()
{
	char* s = str;
	char* result = new char[8192];
	cout<<"�ַ�������Ϊ:\n";
	while (*s != '\0')
	{
		for (int j = 0; j < n; j++) {
			if (*s == HCodeTable[j].data)
			{
				cout << HCodeTable[j].code;
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