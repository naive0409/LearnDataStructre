#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;

template <class T,int N> class MGraph
{
public:
      MGraph(const char* filename);  //构造函数
      void DFS (int v);        //从v出发深度优先
      void BFS (int v);        //从v出发广度优先
      void PrintGraph();
private:
      T vertex[N];
      int arc[N][N];
      int vNum, arcNum;      //顶点数、边数
};
template <class T,int N>
MGraph<T,N>::MGraph(const char* filename)  //构造函数
{
	ifstream in(filename);
	int i,j;
	in>>vNum>>arcNum;
	for (int i=0;i<vNum;i++)
	{
		in>>vertex[i];
	}
	 
	memset(arc,0,N*N*sizeof(int));
	while (!in.eof())
	{
		in>>i>>j;
		arc[i][j] = 1;
	}
	in.close();

}
template <class T,int N>
void MGraph<T,N>::PrintGraph()
{
	for (int i=0;i<vNum;i++)
		cout<<"v"<<vertex[i]<<" ";
	cout<<endl;
	for (int i=0;i<vNum;i++)
	{
		for (int j=0;j<vNum;j++)
			cout<<arc[i][j]<<" ";
		cout<<endl;
	}
}

template <class T,int N>
void MGraph<T,N>::DFS (int v)//从v出发深度优先
{
	
}
template <class T,int N>
void MGraph<T,N>::BFS (int v)    //从v出发广度优先
{
}

int main()
{
	MGraph<char,5> g("abc.txt");
	g.PrintGraph();
}
