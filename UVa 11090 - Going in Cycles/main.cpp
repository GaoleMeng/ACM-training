#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iomanip> 


using namespace std;
const int maxn = 50+10;

struct Edge  
{  
    int from,to;  
    double dist;  
};  


struct Bellman_ford  
{  
    int n,m;  
    vector<Edge>edges;  
    vector<int>G[maxn];  
    double d[maxn];  
    int inq[maxn],cnt[maxn];  
    void init(int n)  
    {
        this->n=n;  
        for(int i=0;i<n;i++) G[i].clear();  
        edges.clear();  
    }  
    void add(int u,int v,double dist)  
    {  
        edges.push_back((Edge){u,v,dist});  
        m=edges.size();  
        G[u].push_back(m-1);  
    }  
    bool circle()  
    {  
        queue<int>Q;
        memset(inq, 0, sizeof(inq));
        memset(cnt, 0, sizeof(cnt));

        for(int i=0;i<n;i++)
        {  
            d[i]=cnt[i]=0;
            inq[i]=1;
            Q.push(i);  
        }
        while(!Q.empty())  
        {  
            int u=Q.front();Q.pop();  
            inq[u]=0;  
            for(unsigned int i=0;i<G[u].size();i++)  
            {  
                Edge& e=edges[G[u][i]];  
                if(d[e.to]>d[e.from]+e.dist)  
                {  
                    d[e.to]=d[e.from]+e.dist;  
                    if(!inq[e.to])  
                    {
                        inq[e.to]=1;  
                        Q.push(e.to);  
                        if(++cnt[e.to]>n) return true;  
                    }  
                }  
            }  
        }  
        return false;  
    }  
};



Bellman_ford graph;
bool test(double x){
	for (int i = 0; i < graph.m; i++){
		graph.edges[i].dist-=x;
	}
	bool tmp = graph.circle();
	for (int i = 0; i < graph.m; i++){
		graph.edges[i].dist+=x;
	}

	return tmp;
}


int main(){

	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		int n, m;
		cin >> n >> m;
		Bellman_ford graphh;
		graphh.init(n);
		graph = graphh;
		

		double max = 0;

		while (m--){
			int a,b,c;
			cin >> a >> b >> c;
			a--;
			b--;
			graph.add(a,b,c);
			max = max > c ? max : c;
		}
		if (!test(max+1)) {
			cout << "Case #"<< i+1 << ": No cycle found.\n";
		}

		else{
			double L = 0, R = max;
			while (R - L > 1e-3){
				double M = L + (R - L) / 2;
				if (test(M)) R = M;
				else{
					L = M;
				}
			}
			cout << std::fixed;
			cout << "Case #" << i+1 << ": ";
			cout << setprecision(2) << L << "\n";
		}
	}
}