#pragma once
#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;

template <class T, int N> class MGraph
{
public:
	MGraph(const char* filename);  //���캯��
	void DFS(int v);        //��v�����������
	void BFS(int v);        //��v�����������
	void PrintGraph();

	void SetVisited() { memset(visited, 0, N * sizeof(int)); }
	int GetVisited(int i) { return visited[i]; }

	int GetVNum() { return vNum; }

private:
	T vertex[N];
	int arc[N][N];
	int visited[N];
	int vNum, arcNum;      //������������
};

template <class T, int N>//���캯��
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

template <class T, int N>//��ӡͼ
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

template <class T, int N>//��v�����������
void MGraph<T, N>::DFS(int v)
{

	cout << 'v' << v+1 << ' ';
	visited[v] = 1;

	for (int i=0;i<vNum;i++)
		if (arc[v][i]==1 && visited[i]==0)
			DFS(i);

	return;
	
	/*����Ϊ�ݹ顢����Ϊ�ǵݹ�*/

	//int Stack[100]; 	int top = -1;
	//cout << 'v' << v + 1 << ' ';
	//visited[v] = 1;
	//Stack[++top] = v;//��ջ 
	//while (top != -1)
	//{
	//	int i;
	//	for (i = 0; i < vNum; i++)
	//		if (arc[v][i] == 1 && visited[i] == 0)
	//		{
	//			v = i;
	//			Stack[++top] = v;//��ջ 
	//			cout << 'v' << v + 1 << ' ';
	//			visited[v] = 1;
	//			break;
	//		}
	//	if (i == vNum) { top--; v = Stack[top]; }//��ջ 
	//}

}

template <class T, int N>//��v�����������
void MGraph<T, N>::BFS(int v)
{
	
	int Queue[100];
	int f, r;
	f = r = -1;
	Queue[++r] = v;//��� 
	visited[v] = 1;
	while (f != r) //���в��� 
	{
		v = Queue[++f];//����
		cout << 'v' << v + 1 << ' ';
		for (int i = 0; i < vNum; i++)  //find v ����δ���ʵ��ڽӵ㣬��� 
			if (arc[v][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				Queue[++r] = i;
			}
	}

}
