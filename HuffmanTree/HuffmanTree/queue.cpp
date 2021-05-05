#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void initPQueue(pQueue** queue)
{
	*queue = (pQueue*)malloc(sizeof(pQueue));
	(*queue)->first = NULL;
	(*queue)->size = 0;
	//return;
}

void addPQueue(pQueue** queue, TYPE val, unsigned int priority)
{
	if ((*queue)->size == MAX_SZ)
	{
		printf("\nQueue is Full.\n");
		return;                      //跳出函数
	}

	pQueueNode* aux = (pQueueNode*)malloc(sizeof(pQueueNode)); //临时结点
	aux->probability = priority;
	aux->val = val;

	//若是第一个huffmanQueue队列结点  //放在最前面队首
	if ((*queue)->size == 0 || (*queue)->first == NULL)
	{
		aux->next = NULL;
		(*queue)->first = aux;
		(*queue)->size = 1;
		return;
	}

	else   //比较priority大小，从小到大顺序插入队列
	{
		//频率小于第一个结点，插最前面
		if (priority <= (*queue)->first->probability)
		{
			aux->next = (*queue)->first;
			(*queue)->first = aux;
			(*queue)->size++;
			return;
		}

		//频率大于第一结点时
		else
		{
			pQueueNode* iterator = (*queue)->first;

			//遍历下一结点，未到最后一个结点时
			while (iterator->next != NULL)
			{
				//频率比下一个结点频率小，插到其前面
				if (priority <= iterator->next->probability)
				{
					aux->next = iterator->next;
					iterator->next = aux;
					(*queue)->size++;
					return;
				}
				//频率比下一个结点频率大时，遍历下一个
				iterator = iterator->next;
			}

			//遍历最后一个结点时(没有比此频率priority小的),放到队列最后
			if (iterator->next == NULL)
			{
				aux->next = NULL;
				iterator->next = aux;
				(*queue)->size++;
				return;
			}
		}
	}

	//free(aux);  //jo
}

TYPE getPQueue(pQueue** queue)
{
	TYPE returnVal;
	if ((*queue)->size > 0)
	{
		returnVal = (*queue)->first->val;
		(*queue)->first = (*queue)->first->next;
		(*queue)->size--;
	}
	else
	{
		printf("\nQueue is empty.\n");
	}
	return returnVal;
}