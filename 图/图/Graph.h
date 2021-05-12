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

	void SetVisited() { memset(visited, 0, N * sizeof(int)); }//�������
	int GetVisited(int i) { return visited[i]; }

	int GetVNum() { return vNum; }

private:
	T vertex[N];//����
	int arc[N][N];//��
	int visited[N];
	int vNum, arcNum;      //������������
};

template <class T, int N>//���캯��
MGraph<T, N>::MGraph(const char* filename)
{
	ifstream in(filename);
	int i, j;
	in >> vNum >> arcNum;//txt��һ�зֱ��ǽڵ����ͱ���
	for (int i = 0; i < vNum; i++)
	{
		in >> vertex[i];//ÿ���ڵ�������
	}

	memset(arc, 0, N * N * sizeof(int));
	while (!in.eof())//�ж��ļ�����
	{
		in >> i >> j;
		arc[i][j] = 1;//txtһ�������������ɶԣ�����һ���ߣ����������ڵ�
	}
	in.close();

}

template <class T, int N>//��ӡͼ
void MGraph<T, N>::PrintGraph()
{
	for (int i = 0; i < vNum; i++)
		cout << "v" << vertex[i] << " ";//�ӵ�һ�������һ���ڵ��ӡ������
	cout << endl;
	for (int i = 0; i < vNum; i++)
	{
		for (int j = 0; j < vNum; j++)
			cout << arc[i][j] << " ";//��ӡһ�����������д���ÿ�������ӵ������ڵ�
		cout << endl;
	}
}

template <class T, int N>//��v�����������
void MGraph<T, N>::DFS(int v)
{

	/*
	cout << 'v' << v+1 << ' ';
	//1�ʼ�ĵ�һ�����ó�������/��������ڵ���
	visited[v] = 1;//2���ʹ���

	for (int i=0;i<vNum;i++)
		if (arc[v][i]==1 && visited[i]==0)
			//3���ĳ���ڵ�i�뱾���v֮���б���������û�б����ʹ�
			DFS(i);
			//4���ߵ�����ڵ㣬����ظ��������

	return;

	/*
	���ߵ�return�ⲽ��˵����ǰ���ѭ����һֱû�д���3��������
	˵��������ڵ����ڵ����нڵ㶼���ʹ��ˣ��������Ǹ�����ͬ
	�����Ļ��ͻ��ݣ���ԭ·����
	*/


	*/

	/*����Ϊ�ݹ飬����Ϊ�ǵݹ�*/

	int Stack[100]; 	int top = -1;
	cout << 'v' << v + 1 << ' ';//�ʼ�ĵ�һ�����ó�������
	visited[v] = 1;//v:�������ڵĽڵ�
	Stack[++top] = v;//��ջ 
	while (top != -1)//ֻҪջ���գ����ظ�
	{
		int i;
		for (i = 0; i < vNum; i++)
		{
			//���ĳ���ڵ�i�뱾���v֮���б���������û�б����ʹ�
			if (arc[v][i] == 1 && visited[i] == 0)
			{
				v = i;//���൱�ڵݹ飩�ߵ�����ڵ�i��
				Stack[++top] = v;//��ջ 
				cout << 'v' << v + 1 << ' ';
				visited[v] = 1;
				break;//(*)
				//����ҵ������ߵ�·������ǰ��һ����Ȼ���˳�ѭ��
			}
		}

		//��(*)��ϣ��˳�ѭ��ʱi
		if (i == vNum)
		{
			top--;
			v = Stack[top];//����ԭ·�˻�
		}//��ջ 
	}

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
