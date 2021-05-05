#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Huffman.h"
#include "queue.h"

//遍历huffman树结点,形成table链表
void traversalTree(htNode* treeNode, hlTable** table, int k, char code[256])
{
	//若当前树节点左右叶子为空（即自身为叶子节点） 
	if (treeNode->left == NULL && treeNode->right == NULL)
	{
		//code尾部加\0,定义新结点aux
		code[k] = '\0';
		hlNode* aux = (hlNode*)malloc(sizeof(hlNode));
		aux->code = (char*)malloc(sizeof(char) * (strlen(code) + 1));
		strcpy(aux->code, code);
		aux->symbol = treeNode->symbol;
		aux->next = NULL;

		//table增加第一个aux结点
		if ((*table)->first == NULL)
		{
			(*table)->first = aux;
			(*table)->last = aux;
		}
		//table尾部增加aux结点 ，形成table链表
		else
		{
			(*table)->last->next = aux;
			(*table)->last = aux;
		}
	}

	//若当前树节点左叶子不为空，code中加0，向下递归遍历
	if (treeNode->left != NULL)
	{
		code[k] = '0';
		traversalTree(treeNode->left, table, k + 1, code);
	}
	//若当前树节点右叶子不为空，code中加1，向下递归遍历
	if (treeNode->right != NULL)
	{
		code[k] = '1';
		traversalTree(treeNode->right, table, k + 1, code);
	}

}

hlTable* buildTable(htTree* huffmanTree)
{
	hlTable* table = (hlTable*)malloc(sizeof(hlTable));
	table->first = NULL;
	table->last = NULL;
	int k = 0;
	char code[256];
	traversalTree(huffmanTree->root, &table, k, code);
	return table;
}

htTree* buildTree(char* inputString)
{
	//字符出现次数统计(所有字符对应的ASCII码对应的整型范围:0 - 127)
		int* probability = (int*)malloc(sizeof(int) * 256);     //256个int内存空间

		//初始化
	for (int i = 0; i < 256; i++)
	{
		probability[i] = 0;
	}
	//使用ASCII的整型数值作为索引统计
	for (int j = 0; inputString[j] != '\0'; j++)
	{
		probability[(unsigned char)inputString[j]]++;
	}

	//初始化huffman队列的头指针
	pQueue* huffmanQueue;
	initPQueue(&huffmanQueue);

	//遍历所有的ASCIII码(0-256)对应的字符，若出现次数不为0，定义htNode结点 加入到huffman队列中去
	for (int k = 0; k < 256; k++)
	{
		if (probability[k] != 0)
		{
			htNode* aux = (htNode*)malloc(sizeof(htNode));
			aux->left = NULL;
			aux->right = NULL;
			aux->symbol = (char)k;         //ASCIII码整型转成字符

			addPQueue(&huffmanQueue, aux, probability[k]);
		}
	}

	free(probability);

	//生成huffman树
	while (huffmanQueue->size != 1)
	{
		int priority = huffmanQueue->first->probability;
		priority += huffmanQueue->first->next->probability;  //前两个结点频率(最小两个值)的和生成新的huffman树结点频率

		htNode* left = getPQueue(&huffmanQueue);
		htNode* right = getPQueue(&huffmanQueue);

		htNode* newNode = (htNode*)malloc(sizeof(htNode));
		newNode->left = left;
		newNode->right = right;

		addPQueue(&huffmanQueue, newNode, priority);
	}

	//队列中剩余的一个结点即为根结点
	htTree* hufTree = (htTree*)malloc(sizeof(htTree));
	hufTree->root = getPQueue(&huffmanQueue);
	return hufTree;
}

void encode(hlTable* table, char* stringToEncode)
{
	hlNode* traversal;

	printf("stringToEncode is: %s \n\nEncoding...\n\n", stringToEncode);

	for (int i = 0; stringToEncode[i] != '\0'; i++)
	{
		traversal = table->first;  //每个字符都需要从Table中第一个位置找起
		while (traversal->symbol != stringToEncode[i])  //逐字符 全遍历
		{
			traversal = traversal->next;
		}
		printf("%s ", traversal->code);
	}

	printf("\n");
}

void decode(htTree* tree, char* stringToDecode)
{
	htNode* traversal = tree->root;
	printf("\n\nDecoding.... \n\nstringToDecode is: %s \n\nDecoding String:\n\n", stringToDecode);

	//逐字符（0左/1右）遍历huffman树
	for (int i = 0; stringToDecode[i] != '\0'; i++)
	{
		//遍历到最后一个叶子节点 即为解码后的字符
		if (traversal->left == NULL && traversal->right == NULL)
		{
			printf("%c", traversal->symbol);
			traversal = tree->root;
		}
		if (stringToDecode[i] == '0')
		{
			traversal = traversal->left;
		}
		if (stringToDecode[i] == '1')
		{
			traversal = traversal->right;
		}
		if (stringToDecode[i] != '0' && stringToDecode[i] != '1')
		{
			printf("Input String cannot be decoded correctly\n");
			return;
		}
	}
	//if (traversal->left == NULL && traversal->right == NULL)
	//{

	//}

}