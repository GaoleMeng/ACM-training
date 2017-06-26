#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=1001;
int n1,n2,k;
//n1,n2为二分图的顶点集,其中x∈n1,y∈n2
int map[N][N],vis[N],link[N];
//link记录n2中的点y在n1中所匹配的x点的编号
int find(int x)
{
    int i;
    for(i=1;i<=n2;i++)
    {
        if(map[x][i]&&!vis[i])//x->i有边,且节点i未被搜索
        {
            vis[i]=1;//标记节点已被搜索
            //如果i不属于前一个匹配M或被i匹配到的节点可以寻找到增广路
            if(link[i]==0||find(link[i]))
            {
                link[i]=x;//更新
                return 1;//匹配成功
            }
        }
    }
    return 0;
}
int main()
{
    int i,x,y,s=0;
    scanf("%d%d%d",&n1,&n2,&k);
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&x,&y);
        map[x][y]=1;
    }
    for(i=1;i<=n1;i++)
    {
        memset(vis,0,sizeof(vis));
        if(find(i))
            s++;
    }
    printf("%d\n",s);
    return 0;
}

