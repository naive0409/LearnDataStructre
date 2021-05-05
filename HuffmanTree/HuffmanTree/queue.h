#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include "huffman.h"

#define TYPE htNode *
#define MAX_SZ 256

//����Ƶ������ģ����н��
typedef struct _pQueueNode
{
	TYPE val;
	unsigned int probability;
	struct _pQueueNode* next;
}pQueueNode;

//����
typedef struct _pQueue
{
	unsigned int size;
	pQueueNode* first;
}pQueue;


//��ʼ��huffman����
void initPQueue(pQueue** queue);       //����ָ��*****//

//���ӽ�㵽����
void addPQueue(pQueue** queue, TYPE val, unsigned int priority);

//��ȡ�����е�һ��(����Ƶ��ֵprobability��С��)���
TYPE getPQueue(pQueue** queue);

#endif