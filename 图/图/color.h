#pragma once

#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class graph {
private:
	int V, E;
	//V顶点数，E边数
	int color[32] = {0};
	//颜色：初始化数值是0（未涂色），数字表示不同颜色
	vector<int> G[32];

public:
	bool DFSColorize(int v, int c);//判断，dfs
	void paint();//主程序
	graph(int V,int E);//构造
};

graph::graph(int V, int E)
{
	this->V = V;
	this->E = E;
	for (int i = 0; i < E; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;//这个边链接哪两个结点
		//创建无向图
		this->G[node1].push_back(node2);
		this->G[node2].push_back(node1);
	}
}

void graph::paint()
{
	for (int i = 0; i < V; i++)
	{
		if (color[i] == 0)//从没有涂色的节点
		{
			int colorNumber = 1;
			//从一种颜色开始尝试，如果不成功就增加一种颜色
			while (1)
			{
				if (DFSColorize(i, colorNumber++))
				{
					cout << "涂色最少需要" << colorNumber << "种颜色";
					return;
				}

			}
		}
	}
}

bool graph::DFSColorize(int index, int aColor)
{
	color[index] = aColor;//将节点v置为一种颜色
	for (int i = 0; i < G[index].size(); i++)
	{
		//遍历各个相邻节点

		if (color[G[index][i]] == aColor)
			//v有相邻同色节点则不符合要求
		{
			return false;
		}

		if ((color[G[index][i]] == 0) && (!DFSColorize(G[index][i], -aColor)))
			//相邻未涂色的节点涂色后不符合要求则不符合要求
		{
			return false;
		}

	}

	return true;//符合题目的条件，能够涂色
}