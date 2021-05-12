//#include <iostream>
//#include <fstream>
//#include <memory.h>
//using namespace std;
//
//template <class T, int N> class MGraph
//{
//public:
//	MGraph(const char* filename);  //构造函数
//	void DFS(int v);        //从v出发深度优先
//	void BFS(int v);        //从v出发广度优先
//	void PrintGraph();
//	void Setvisited() { memset(arc, 0, N * N * sizeof(int)); };
//	int Getvisited(int i) { return visited[i]; };
//	int vNum, arcNum;      //顶点数、边数
//
//private:
//	T vertex[N];
//	int arc[N][N];
//	int visited[N];
//};
//template <class T, int N>
//MGraph<T, N>::MGraph(const char* filename)  //构造函数
//{
//	ifstream in(filename);
//	int i, j;
//	in >> vNum >> arcNum;
//	for (int i = 0; i < vNum; i++)
//	{
//		in >> vertex[i];
//	}
//
//	memset(arc, 0, N * N * sizeof(int));
//	while (!in.eof())
//	{
//		in >> i >> j;
//		arc[i][j] = 1;
//	}
//	in.close();
//
//}
//template <class T, int N>
//void MGraph<T, N>::PrintGraph()
//{
//	for (int i = 0; i < vNum; i++)
//		cout << "v" << vertex[i] << " ";
//	cout << endl;
//	for (int i = 0; i < vNum; i++)
//	{
//		for (int j = 0; j < vNum; j++)
//			cout << arc[i][j] << " ";
//		cout << endl;
//	}
//}
//
//template <class T, int N>
//void MGraph<T, N>::DFS(int v)//从v出发深度优先
//{
//	int Stack[100]; int top = -1;
//
//	cout << 'v' << v+1 << ' ';
//	visited[v] = 1;
//
//	for (int i=0;i<vNum;i++)
//		if (arc[v][i]==1 && visited[i]==0)
//			DFS(i);
//
//	return;
//
//	/*
//	cout << 'v' << v + 1 << ' ';
//	visited[v] = 1;
//	Stack[++top] = v;
//
//	while (top != -1)
//	{
//		int i = 0;
//		for (i = 0; i < vNum; i++)
//			if (arc[v][i] == 1 && visited[i] == 0)
//			{
//				v = i;
//				Stack[++top] = v;
//				cout << 'v' << v + 1 << ' ';
//				visited[v] = 1;
//				break;
//			}
//		if (i == vNum)
//		{
//			top--;
//			v = Stack[top];
//		}
//
//	}*/
//}
//template <class T,int N>
//void MGraph<T,N>::BFS (int v)    //从v出发广度优先
//{
//	int queue[100];
//	int f, r;
//	f = r = -1;
//	queue[++r] = v;//v入队
//	visited[v] = 1;
//	while (f!=r)
//	{
//		v = queue[++f];
//		//出队
//		cout << 'v' << v + 1 << ' ';
//		for (int i = 0; i < vNum; i++)
//			if (arc[v][i] == 1 && visited[i] == 0)
//			{
//				visited[v] = 1;
//				queue[++r] = i;
//			}
//		//v邻接点入队
//	}
//
//}
//
//int main()
//{
//	MGraph<char,5> g("abc.txt");
//	g.PrintGraph();
//	g.Setvisited();
//	//for (int i=0;i<g.vNum;i++)
//	//{
//	//	if(g.Getvisited(i)==0)
//	//	g.DFS(i);
//	//}
//	g.BFS(0);
//}
