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

	void SetVisited() { memset(visited, 0, N * sizeof(int)); }
	int GetVisited(int i) { return visited[i]; }

	int GetVNum() { return vNum; }

private:
	T vertex[N];
	int arc[N][N];
	int visited[N];
	int vNum, arcNum;      //顶点数、边数
};

template <class T, int N>//构造函数
MGraph<T, N>::MGraph(const char* filename)
{
	ifstream in(filename);
	int i, j;
	in >> vNum >> arcNum;
	for (int i = 0; i < vNum; i++)
	{
		in >> vertex[i];
	}

	memset(arc, 0, N * N * sizeof(int));
	while (!in.eof())
	{
		in >> i >> j;
		arc[i][j] = 1;
	}
	in.close();

}

template <class T, int N>//打印图
void MGraph<T, N>::PrintGraph()
{
	for (int i = 0; i < vNum; i++)
		cout << "v" << vertex[i] << " ";
	cout << endl;
	for (int i = 0; i < vNum; i++)
	{
		for (int j = 0; j < vNum; j++)
			cout << arc[i][j] << " ";
		cout << endl;
	}
}

template <class T, int N>//从v出发深度优先
void MGraph<T, N>::DFS(int v)
{

	cout << 'v' << v+1 << ' ';
	visited[v] = 1;

	for (int i=0;i<vNum;i++)
		if (arc[v][i]==1 && visited[i]==0)
			DFS(i);

	return;
	
	/*以上为递归、以下为非递归*/

	//int Stack[100]; 	int top = -1;
	//cout << 'v' << v + 1 << ' ';
	//visited[v] = 1;
	//Stack[++top] = v;//入栈 
	//while (top != -1)
	//{
	//	int i;
	//	for (i = 0; i < vNum; i++)
	//		if (arc[v][i] == 1 && visited[i] == 0)
	//		{
	//			v = i;
	//			Stack[++top] = v;//入栈 
	//			cout << 'v' << v + 1 << ' ';
	//			visited[v] = 1;
	//			break;
	//		}
	//	if (i == vNum) { top--; v = Stack[top]; }//出栈 
	//}

}

template <class T, int N>//从v出发广度优先
void MGraph<T, N>::BFS(int v)
{
	
	int Queue[100];
	int f, r;
	f = r = -1;
	Queue[++r] = v;//入队 
	visited[v] = 1;
	while (f != r) //队列不空 
	{
		v = Queue[++f];//出队
		cout << 'v' << v + 1 << ' ';
		for (int i = 0; i < vNum; i++)  //find v 所有未访问的邻接点，入队 
			if (arc[v][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				Queue[++r] = i;
			}
	}

}
