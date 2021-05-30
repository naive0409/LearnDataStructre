#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int V, E;
//V顶点数，E边的数量
int color[32];// = {0};
//表示节点颜色的数组，其中1表示一种颜色，-1是另一种颜色，初始化数值是0
//(现在只能判断两种颜色行不行)
vector<int> G[32];//存储图的信息
bool dfs(int v, int c);
//深度优先遍历

void sovle();

int main()
{
    //scanf("%d %d", &V, &E);
    cin >> V >> E;//V表示顶点数，E表示边的数量
    for (int i = 0; i < E; i++)
    {
        int f, t;
        //scanf("%d %d", &f, &t);
        cin >> f >> t;//这个边链接哪两个结点
        G[f].push_back(t);//创建无向图
        G[t].push_back(f);//无向图
    }
    sovle();
    return 0;
}

void sovle()
{
    for (int i = 0; i < V; i++)
    {
        if (color[i] == 0)//从没有涂色的节点开始深度优先搜索
        {
            if (!dfs(i, 1))
            {
                printf("no");
                return;
            }
        }
    }
    printf("yes");
}
bool dfs(int v, int c)
{
    color[v] = c;//将节点v置为一种颜色
    for (int i = 0; i < G[v].size(); i++)
    {
        if (color[G[v][i]] == c)
            //如果和节点v相连的其他节点也是同样的颜色，说明涂色不能完成
        {
            return false;
        }
        if ((color[G[v][i]] == 0) && (!dfs(G[v][i], -c)))
            //如果相邻节点未涂色，但涂色后结果非法，也说明涂色无法完成
        {
            return false;
        }
    }
    return true;//涂色完成
}
