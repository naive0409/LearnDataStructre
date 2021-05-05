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
		return;                      //��������
	}

	pQueueNode* aux = (pQueueNode*)malloc(sizeof(pQueueNode)); //��ʱ���
	aux->probability = priority;
	aux->val = val;

	//���ǵ�һ��huffmanQueue���н��  //������ǰ�����
	if ((*queue)->size == 0 || (*queue)->first == NULL)
	{
		aux->next = NULL;
		(*queue)->first = aux;
		(*queue)->size = 1;
		return;
	}

	else   //�Ƚ�priority��С����С����˳��������
	{
		//Ƶ��С�ڵ�һ����㣬����ǰ��
		if (priority <= (*queue)->first->probability)
		{
			aux->next = (*queue)->first;
			(*queue)->first = aux;
			(*queue)->size++;
			return;
		}

		//Ƶ�ʴ��ڵ�һ���ʱ
		else
		{
			pQueueNode* iterator = (*queue)->first;

			//������һ��㣬δ�����һ�����ʱ
			while (iterator->next != NULL)
			{
				//Ƶ�ʱ���һ�����Ƶ��С���嵽��ǰ��
				if (priority <= iterator->next->probability)
				{
					aux->next = iterator->next;
					iterator->next = aux;
					(*queue)->size++;
					return;
				}
				//Ƶ�ʱ���һ�����Ƶ�ʴ�ʱ��������һ��
				iterator = iterator->next;
			}

			//�������һ�����ʱ(û�бȴ�Ƶ��priorityС��),�ŵ��������
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