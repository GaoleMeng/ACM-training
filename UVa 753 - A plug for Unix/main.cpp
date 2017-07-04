#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

const int maxn = 400 + 10;
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

    void print(){
        for (int i = 0; i < edges.size(); i++){
            cout << edges[i].from << " " << edges[i].to << " " << edges[i].cap << " " << edges[i].flow << "\n"; 
        }
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


int main(){
    int N;
    cin >> N;
    while(N--){
        int n, m, k;
        cin >> n;
        string rec[n];

        EdmondsKarp thisg;
        thisg.init(n+m+k+2);
        
        for(int i = 0; i < n; i++){
            cin >> rec[i];
        }

        cin >> m;
        string device[m];
        for (int i = 0; i < m; i++){
            string trash;
            cin >> trash >> device[i];
        }

        cin >> k;
        pair<string, string> changelist[k];

        for (int i = 0; i < k; i++){
            cin >> changelist[i].first >> changelist[i].second;
        }

        for (int i = 0; i < k; i++){
            string tmp = changelist[i].second;
            for (int j = 0; j < k; j++){
                if (tmp == changelist[j].first){
                    thisg.addEdge(m+1+i, m+1+j, INF);
                }
            }
        }
        
        for (int i = 0; i < m; i++){
            thisg.addEdge(0, i+1, 1);
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < k; j++){
                if (device[i] == changelist[j].first){
                    thisg.addEdge(i+1, j+m+1, 1);
                }
            }
            for (int j = 0; j < n; j++){
                if (device[i] == rec[j]){
                    thisg.addEdge(i+1, m+k+1+j, 1);
                }
            }
        }


        for (int i = 0; i < k; i++){
            for (int j = 0; j < n; j++){
                if (changelist[i].second == rec[j]){
                    thisg.addEdge(i+1+m, m+k+1+j, INF);
                }
            }
        }

        for (int i = 0; i < n; i++){
            thisg.addEdge(i+m+k+1, m+k+n+1, 1);
        }
        //thisg.print();
        cout << m-thisg.Maxflow(0, m+k+n+1) << "\n";
        if (N!=0)
            cout << "\n";
    }
}