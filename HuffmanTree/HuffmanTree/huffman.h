#pragma once
#ifndef _HUFFMAN_H
#define _HUFFMAN_H

//huffman�����ڵ�ṹ
typedef struct _htNode
{
	char symbol;
	struct _htNode* left, * right;
}htNode;

//huffman�� �����
typedef struct _htTree
{
	htNode* root;
}htTree;


//label���
typedef struct _hlNode
{
	char symbol;
	char* code;
	struct _hlNode* next;
}hlNode;

//label��
typedef struct _hlTable
{
	hlNode* first;
	hlNode* last;
}hlTable;


//ʹ��ָ���ַ���inputString������huffman��
htTree* buildTree(char* inputString);

//ʹ�ô�����huffmanTree��������hlTable��
hlTable* buildTable(htTree* huffmanTree);

//ʹ��table����ָ���ַ���stringToEncode���б���ѹ��(���ַ�����ɶ�������)
void encode(hlTable* table, char* stringToEncode);

//ʹ��huffman tree����ѹָ���ı���stringToDecode
void decode(htTree* tree, char* stringToDecode);

#endif