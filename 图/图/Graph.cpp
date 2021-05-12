#include "Graph.h"

int main()
{
	MGraph<char, 5> g("abc.txt");
	g.PrintGraph();

	cout << "深度优先遍历：";
	g.SetVisited();

	//只有一个g.DFS(0)导致无法输出最后一个节点
	
	for (int i = 0; i < g.GetVNum(); i++)
		if (g.GetVisited(i) == 0)
			g.DFS(i);



	cout << "\n广度优先遍历：";
	g.SetVisited();
	g.BFS(0);

	return 0;
}

/*Krushal(edge ,n)
{
	int k=0; int j;
	vset[n]={0,1,2,3,4,5,6,7,8};
	while(j<n-1)
	{
		int v1 = edge[k].v1;
		int v2 = edge[k].v2;
		if (vset[v1]!=vset[v2])
		{
			j++;
			int id=vset[v2];
			for(int i=0;i<n;i++)
			  if (vset[i]==id)   	vset[i] = vset[v1];
		}
		k++;
	}
}*/



