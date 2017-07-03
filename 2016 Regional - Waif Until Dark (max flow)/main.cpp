#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 300 + 10;
const int INF = 1 << 30;

struct Edge{
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f){}
};

struct EdmondsKarp {

    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn];
    int p[maxn];
    
    void init(int n){
        for(int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void addEdge(int from, int to, int cap){
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    int Maxflow(int s, int t){
        int flow = 0;
        for (;;){
            memset(a, 0, sizeof(a));
            queue<int> Q;
            Q.push(s);
            a[s] = INF;
            while(!Q.empty()){
                int x = Q.front(); Q.pop();
                for (int i = 0; i < G[x].size(); i++){
                    Edge& e = edges[G[x][i]];
                    if (!a[e.to] && e.cap > e.flow){
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x], e.cap - e.flow);
                        Q.push(e.to);
                    }
                }
                if (a[t]) break;
            }
            if (!a[t]) break;
            for (int u = t; u!=s; u = edges[p[u]].from){
                edges[p[u]].flow += a[t];
                edges[p[u]^1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
};


int main (){

    int n,m,p;
    while(cin >> n >> m >> p){
        EdmondsKarp thisg;
        thisg.init(n+m+p+3);

        for (int i = 0; i < n; i++){
            thisg.addEdge(0, i+1, 1);
        }


        for (int i = 0; i < n; i ++){
            int toys;
            cin >> toys;
            for(int j = 0; j < toys; j++){
                int tmp;
                cin >> tmp;
                thisg.addEdge(i+1, n+tmp, 1);
            }
        }


        int checklist[m];
        int flowlist[p];
        memset(flowlist, 0, sizeof(flowlist));
        memset(checklist, 0, sizeof(checklist));

        for (int i = 0; i < p; i++){
            int l;
            cin >> l;
            int r;
            for (int j = 0; j < l; j++){
                int tmp;
                cin >> tmp;
                thisg.addEdge(n+tmp, i+n+m+1, 1);
                checklist[tmp-1] = 1;
            }
            cin >> r;
            flowlist[i] = r;
        }
        

        
        for (int i = 0;i < m; i++){
            if (!checklist[i]){
                thisg.addEdge(i+n+1, n+m+p+1, 1);
            }
        }

        for (int i = 0; i < p; i++){
            thisg.addEdge(i+1+n+m, n+m+p+2, flowlist[i]);
        }
        thisg.addEdge(n+m+p+1, n+m+p+2, INF);
        cout << thisg.Maxflow(0, n+m+p+2) << "\n";
    }
}