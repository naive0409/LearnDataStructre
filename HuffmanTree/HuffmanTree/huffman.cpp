#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Huffman.h"
#include "queue.h"

//����huffman�����,�γ�table����
void traversalTree(htNode* treeNode, hlTable** table, int k, char code[256])
{
	//����ǰ���ڵ�����Ҷ��Ϊ�գ�������ΪҶ�ӽڵ㣩 
	if (treeNode->left == NULL && treeNode->right == NULL)
	{
		//codeβ����\0,�����½��aux
		code[k] = '\0';
		hlNode* aux = (hlNode*)malloc(sizeof(hlNode));
		aux->code = (char*)malloc(sizeof(char) * (strlen(code) + 1));
		strcpy(aux->code, code);
		aux->symbol = treeNode->symbol;
		aux->next = NULL;

		//table���ӵ�һ��aux���
		if ((*table)->first == NULL)
		{
			(*table)->first = aux;
			(*table)->last = aux;
		}
		//tableβ������aux��� ���γ�table����
		else
		{
			(*table)->last->next = aux;
			(*table)->last = aux;
		}
	}

	//����ǰ���ڵ���Ҷ�Ӳ�Ϊ�գ�code�м�0�����µݹ����
	if (treeNode->left != NULL)
	{
		code[k] = '0';
		traversalTree(treeNode->left, table, k + 1, code);
	}
	//����ǰ���ڵ���Ҷ�Ӳ�Ϊ�գ�code�м�1�����µݹ����
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
	//�ַ����ִ���ͳ��(�����ַ���Ӧ��ASCII���Ӧ�����ͷ�Χ:0 - 127)
		int* probability = (int*)malloc(sizeof(int) * 256);     //256��int�ڴ�ռ�

		//��ʼ��
	for (int i = 0; i < 256; i++)
	{
		probability[i] = 0;
	}
	//ʹ��ASCII��������ֵ��Ϊ����ͳ��
	for (int j = 0; inputString[j] != '\0'; j++)
	{
		probability[(unsigned char)inputString[j]]++;
	}

	//��ʼ��huffman���е�ͷָ��
	pQueue* huffmanQueue;
	initPQueue(&huffmanQueue);

	//�������е�ASCIII��(0-256)��Ӧ���ַ��������ִ�����Ϊ0������htNode��� ���뵽huffman������ȥ
	for (int k = 0; k < 256; k++)
	{
		if (probability[k] != 0)
		{
			htNode* aux = (htNode*)malloc(sizeof(htNode));
			aux->left = NULL;
			aux->right = NULL;
			aux->symbol = (char)k;         //ASCIII������ת���ַ�

			addPQueue(&huffmanQueue, aux, probability[k]);
		}
	}

	free(probability);

	//����huffman��
	while (huffmanQueue->size != 1)
	{
		int priority = huffmanQueue->first->probability;
		priority += huffmanQueue->first->next->probability;  //ǰ�������Ƶ��(��С����ֵ)�ĺ������µ�huffman�����Ƶ��

		htNode* left = getPQueue(&huffmanQueue);
		htNode* right = getPQueue(&huffmanQueue);

		htNode* newNode = (htNode*)malloc(sizeof(htNode));
		newNode->left = left;
		newNode->right = right;

		addPQueue(&huffmanQueue, newNode, priority);
	}

	//������ʣ���һ����㼴Ϊ�����
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
		traversal = table->first;  //ÿ���ַ�����Ҫ��Table�е�һ��λ������
		while (traversal->symbol != stringToEncode[i])  //���ַ� ȫ����
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

	//���ַ���0��/1�ң�����huffman��
	for (int i = 0; stringToDecode[i] != '\0'; i++)
	{
		//���������һ��Ҷ�ӽڵ� ��Ϊ�������ַ�
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