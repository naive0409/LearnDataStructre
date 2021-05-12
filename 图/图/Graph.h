#pragma once
#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;

template <class T, int N> class MGraph
{
public:
	MGraph(const char* filename);  //构造函数
	void DFS(int v);        //从v出发深度优先
	void BFS(int v);        //从v出发广度优先
	void PrintGraph();

	void SetVisited() { memset(visited, 0, N * sizeof(int)); }//清空数组
	int GetVisited(int i) { return visited[i]; }

	int GetVNum() { return vNum; }

private:
	T vertex[N];//数据
	int arc[N][N];//边
	int visited[N];
	int vNum, arcNum;      //顶点数、边数
};

template <class T, int N>//构造函数
MGraph<T, N>::MGraph(const char* filename)
{
	ifstream in(filename);
	int i, j;
	in >> vNum >> arcNum;//txt第一行分别是节点数和边数
	for (int i = 0; i < vNum; i++)
	{
		in >> vertex[i];//每个节点存的内容
	}

	memset(arc, 0, N * N * sizeof(int));
	while (!in.eof())//判断文件结束
	{
		in >> i >> j;
		arc[i][j] = 1;//txt一行中数字两两成对，代表一条边，连接两个节点
	}
	in.close();

}

template <class T, int N>//打印图
void MGraph<T, N>::PrintGraph()
{
	for (int i = 0; i < vNum; i++)
		cout << "v" << vertex[i] << " ";//从第一个到最后一个节点打印其内容
	cout << endl;
	for (int i = 0; i < vNum; i++)
	{
		for (int j = 0; j < vNum; j++)
			cout << arc[i][j] << " ";//打印一个矩阵，以行列代表每个边链接的两个节点
		cout << endl;
	}
}

template <class T, int N>//从v出发深度优先
void MGraph<T, N>::DFS(int v)
{

	/*
	cout << 'v' << v+1 << ' ';
	//1最开始的第一步单拿出来处理/到了这个节点了
	visited[v] = 1;//2访问过了

	for (int i=0;i<vNum;i++)
		if (arc[v][i]==1 && visited[i]==0)
			//3如果某个节点i与本结点v之间有边相连，且没有被访问过
			DFS(i);
			//4就走到这个节点，如此重复这个过程

	return;

	/*
	能走到return这步，说明在前面的循环里一直没有触发3的条件，
	说明与这个节点相邻的所有节点都访问过了，或者这是个死胡同
	这样的话就回溯，沿原路返回
	*/


	

	/*以上为递归，以下为非递归*/

	int Stack[100]; 	int top = -1;
	cout << 'v' << v + 1 << ' ';//最开始的第一步单拿出来处理
	visited[v] = 1;//v:现在所在的节点
	Stack[++top] = v;//入栈 
	while (top != -1)//只要栈不空，就重复
	{
		int i;
		for (i = 0; i < vNum; i++)//搜索可用的节点
		{
			//如果某个节点i与本结点v之间有边相连，且没有被访问过
			if (arc[v][i] == 1 && visited[i] == 0)
			{
				v = i;//（相当于递归）走到这个节点i上
				Stack[++top] = v;//入栈 
				cout << 'v' << v + 1 << ' ';
				visited[v] = 1;
				break;//(*)
				//如果找到了能走的路，就往前走一步，兵器退出循环（停止搜索可用的节点）
			}
		}

		/*
		与(*)配合：退出循环时i=vNum,说明前边循环每次都不符合if的条件，
		即这个节点v相邻的所有节点都访问过了，或者这是个死胡同
		*/
		if (i == vNum)
		{
			top--;
			v = Stack[top];//沿着原路退回
		}//出栈 
	}

}

template <class T, int N>//从v出发广度优先
void MGraph<T, N>::BFS(int v)
{
	
	int Queue[100];
	int f, r;//front,rear
	f = r = -1;
	Queue[++r] = v;//入队 
	visited[v] = 1;

	while (f != r) //队列不空 
	{
		v = Queue[++f];//出队
		cout << 'v' << v + 1 << ' ';
		//某节点出队时，它的所有未访问的邻接点入队
		for (int i = 0; i < vNum; i++)
			if (arc[v][i] == 1 && visited[i] == 0)
			{ 
				visited[i] = 1;
				Queue[++r] = i;
			}
	}

}
