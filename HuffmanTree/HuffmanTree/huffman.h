#pragma once
#ifndef _HUFFMAN_H
#define _HUFFMAN_H

//huffman树树节点结构
typedef struct _htNode
{
	char symbol;
	struct _htNode* left, * right;
}htNode;

//huffman树 根结点
typedef struct _htTree
{
	htNode* root;
}htTree;


//label结点
typedef struct _hlNode
{
	char symbol;
	char* code;
	struct _hlNode* next;
}hlNode;

//label表
typedef struct _hlTable
{
	hlNode* first;
	hlNode* last;
}hlTable;


//使用指定字符串inputString，创建huffman树
htTree* buildTree(char* inputString);

//使用创建的huffmanTree树，创建hlTable表
hlTable* buildTable(htTree* huffmanTree);

//使用table表，对指定字符串stringToEncode进行编码压缩(逐字符编码成二进制数)
void encode(hlTable* table, char* stringToEncode);

//使用huffman tree，解压指定的编码stringToDecode
void decode(htTree* tree, char* stringToDecode);

#endif