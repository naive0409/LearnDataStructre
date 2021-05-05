#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include "huffman.h"

#define TYPE htNode *
#define MAX_SZ 256

//（按频率排序的）队列结点
typedef struct _pQueueNode
{
	TYPE val;
	unsigned int probability;
	struct _pQueueNode* next;
}pQueueNode;

//队列
typedef struct _pQueue
{
	unsigned int size;
	pQueueNode* first;
}pQueue;


//初始化huffman队列
void initPQueue(pQueue** queue);       //二级指针*****//

//增加结点到队列
void addPQueue(pQueue** queue, TYPE val, unsigned int priority);

//获取队列中第一个(出现频率值probability最小的)结点
TYPE getPQueue(pQueue** queue);

#endif