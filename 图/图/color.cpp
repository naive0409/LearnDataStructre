#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX_i = 10000+1;
int V, E;//V表示顶点数，E表示边的数量
int color[MAX_i];//表示节点颜色的数组，其中1表示一种颜色，-1是另一种颜色，初始化数值是0
vector<int> G[MAX_i];//存储图的信息
bool dfs(int v, int c);//深度优先搜索遍历图的每一个节点
void sovle();
int main(void)
{
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; i++)
    {
        int f, t;
        scanf("%d %d", &f, &t);
        G[f].push_back(t);
        G[t].push_back(f);//无向图
    }
    sovle();
    return 0;
}
void sovle()
{
    for(int i = 0; i < V; i++)
    {
        if(color[i] == 0)//从没有涂色的节点开始深度优先搜索
        {
            if(!dfs(i, 1))
            {
                printf("no");
                return ;    
            }    
        }    
    }
    printf("yes");    
}
bool dfs(int v, int c)
{
    color[v] = c;//将节点v置为一种颜色
    for(int i = 0; i < G[v].size(); i++)
    {
        if(color[G[v][i]] == c)//如果和节点v相连的其他节点也是同样的颜色，说明涂色不能完成
        {
            return false;
        }
        if((color[G[v][i]] == 0) && (!dfs(G[v][i], -c)))//如果相邻节点未涂色，但涂色后结果非法，也说明涂色无法完成
        {
            return false;
        }
    }
    return true;//涂色完成
}
————————————————
版权声明：本文为CSDN博主「zzuli_xiaomingke」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/zzuli_xiaomingke/article/details/81275097