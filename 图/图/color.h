#pragma once

#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class graph {
private:
	int V, E;
	//V��������E����
	int color[32] = {0};
	//��ɫ����ʼ����ֵ��0��δͿɫ�������ֱ�ʾ��ͬ��ɫ
	vector<int> G[32];

public:
	bool DFSColorize(int v, int c);//�жϣ�dfs
	void paint();//������
	graph(int V,int E);//����
};

graph::graph(int V, int E)
{
	this->V = V;
	this->E = E;
	for (int i = 0; i < E; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;//������������������
		//��������ͼ
		this->G[node1].push_back(node2);
		this->G[node2].push_back(node1);
	}
}

void graph::paint()
{
	for (int i = 0; i < V; i++)
	{
		if (color[i] == 0)//��û��Ϳɫ�Ľڵ�
		{
			int colorNumber = 1;
			//��һ����ɫ��ʼ���ԣ�������ɹ�������һ����ɫ
			while (1)
			{
				if (DFSColorize(i, colorNumber++))
				{
					cout << "Ϳɫ������Ҫ" << colorNumber << "����ɫ";
					return;
				}

			}
		}
	}
}

bool graph::DFSColorize(int index, int aColor)
{
	color[index] = aColor;//���ڵ�v��Ϊһ����ɫ
	for (int i = 0; i < G[index].size(); i++)
	{
		//�����������ڽڵ�

		if (color[G[index][i]] == aColor)
			//v������ͬɫ�ڵ��򲻷���Ҫ��
		{
			return false;
		}

		if ((color[G[index][i]] == 0) && (!DFSColorize(G[index][i], -aColor)))
			//����δͿɫ�Ľڵ�Ϳɫ�󲻷���Ҫ���򲻷���Ҫ��
		{
			return false;
		}

	}

	return true;//������Ŀ���������ܹ�Ϳɫ
}