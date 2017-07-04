
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 100000000;
const int maxn = 3*1000+5;

int n,m,u,v,c,t,p[maxn],a[maxn],inq[maxn],d[maxn];
struct Edge {
    int from, to, cap, flow, cost;
    Edge(int u,int v,int c,int f,int w):from(u),to(v),cap(c),flow(f),cost(w) {}
};
vector<Edge> edges;
vector<int> g[maxn];
void init() {
    for(int i=0;i<maxn;i++) g[i].clear();
    edges.clear();
}
void AddEdge(int from, int to, int cap, int cost) {
    edges.push_back(Edge(from,to,cap,0,cost));
    edges.push_back(Edge(to,from,0,0,-cost));
    t = edges.size();
    g[from].push_back(t-2);
    g[to].push_back(t-1);
}
bool BellmanFord(int s,int t,int& flow, ll& cost) {
    for(int i=0;i<maxn;i++) d[i] = INF;
    memset(inq,0,sizeof(inq));
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        for(int i = 0; i < g[u].size(); i++) {
            Edge& e = edges[g[u][i]];
            if(e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                d[e.to] = d[u] + e.cost ;
                p[e.to] = g[u][i];
                a[e.to] = min(a[u],e.cap - e.flow);
                if(!inq[e.to]) { Q.push(e.to); inq[e.to] = 1; }
            }
        }
    }
    if(d[t] == INF) return false;
    flow += a[t];
    cost += (ll)d[t] *(ll)a[t];
    for(int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u]^1].flow -= a[t];
    }
    return true;
}

int MincostMaxflow(int s,int t, ll& cost) {
    int flow = 0; cost = 0;
    while(BellmanFord(s,t,flow,cost)) ;
    return flow;
}
int main() {
    while(~scanf("%d%d",&n,&m)&&n) {
        init();
        for(int i=2;i<=n-1;i++) {
            AddEdge(i,i+n,1,0);   //拆点法
        }
        for(int i=1;i<=m;i++) {
            scanf("%d%d%d",&u,&v,&c);//由假结点连向真结点。
            if(u != 1 && u != n) AddEdge(u+n,v,1,c);
            else AddEdge(u,v,1,c);
        }
        ll ans ;
        AddEdge(0,1,2,0);
        AddEdge(n,2*n+1,2,0);
        MincostMaxflow(0,2*n+1,ans);
        printf("%lld\n",ans);//在uva上用I64d会PE
    }
    return 0;
}
