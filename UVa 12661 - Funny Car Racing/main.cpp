#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
    int from, to, start, end, ti;
    Edge(int u, int v, int a, int b, int t): from(u), to(v), start(a), end(b), ti(t) {};
};

const int maxn = 300+10;
const int INF = 1e5 + 10;

struct Dijkstra {
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn];
    int d[maxn];
    int p[maxn];

    struct HeapNode {
        int d, u;
        bool operator < (const HeapNode& rhs) const{
            return d > rhs.d;
        }
    };


    void init(int n){
        this->n = n;
        for (int i = 0; i < n; i++){
            G[i].clear();     
        }
        edges.clear();
    }

    void addEdge(int from, int to, int start, int end, int t){
        if (t > start) return;
        edges.push_back(Edge(from, to, start, end, t));
        m = edges.size();
        G[from].push_back(m-1);
    }

    void dijkstra(int s){
        priority_queue<HeapNode> Q;
        for (int i = 0; i < n; i++) d[i] = INF;
        d[s] = 0;
        memset(done, 0, sizeof(done));
        Q.push((HeapNode){0, s});
        while(!Q.empty()){
            HeapNode x = Q.top(); Q.pop();
            int u = x.u;
            if(done[u]) continue;
            done[u] = true;
            for (int i = 0; i < G[u].size(); i++){
                Edge& e = edges[G[u][i]];
                int a = e.start;
                int b = e.end;
               
                int shorten  = d[u] - d[u]/(a+b)*(a+b);
                int lowesttime;
                if (shorten >= 0 && shorten <= a){
                    if (shorten + e.ti > a){
                        lowesttime = (d[u]/(a+b)+1)*(a+b)+e.ti;
                    }
                    else{
                        lowesttime = d[u] + e.ti;
                    }
                }
                else{
                    lowesttime = (d[u]/(a+b)+1)*(a+b)+e.ti;
                }
                if (lowesttime < d[e.to]){
                    d[e.to] = lowesttime;
                    Q.push((HeapNode){d[e.to], e.to});
                }
            }
        }
    }
};

int main(){
    int n,m,s,t;
    int kase = 0;
    while (cin >> n >> m >> s >> t){
        Dijkstra thisg;
        thisg.init(n);
        for (int i = 0; i < m; i++){
            int t1, t2, t3, t4, t5;
            cin >> t1 >> t2 >> t3 >> t4 >> t5;
            thisg.addEdge(t1-1, t2-1, t3, t4, t5);
        }
        thisg.dijkstra(s-1);
        cout << "Case " << ++kase << ": " << thisg.d[t-1] << "\n"; 
    }
}