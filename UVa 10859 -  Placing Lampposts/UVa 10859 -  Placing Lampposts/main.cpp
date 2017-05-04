//
//  main.cpp
//  UVa 10859 -  Placing Lampposts
//
//  Created by 孟高乐 on 5/3/17.
//  Copyright © 2017 GaoleMeng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>


using namespace std;

const int maxn = 1000+10;
int n, m;
int T;


int vis[1010][2];
int d[1010][2];

vector<int> adj[maxn];


int dp(int root, int take, int fa){
    
    if (vis[root][take]) return d[root][take];
    vis[root][take] =  1;
    
    int& ans = d[root][take];
    ans = 2000;
    cout << "haha" <<enl;
    
    for (int i = 0; i < adj[root].size(); i++){
        if (adj[root][i] != fa){
            ans += dp(adj[root][i], 1, root);
        }
    }
    if (fa >= 0 && !take) ans++;
    
    cout << "sss" <<endl;
    
    if (take || fa < 0){
        int ano = 0;
        for (int i = 0 ; i < adj[root].size(); i++){
            if (adj[root][i]!=fa){
                ans += dp(adj[root][i], 0, root);
            }
        }
        if ( fa >= 0 ) ano++;
        ans = min(ano, ans);
        
    }
    
    return ans;
}


int main() {
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++){
            adj[i].clear();
        }
        int total = m;
        cout << "second level"<< endl;
        while (m--){
            int x, y;
            scanf("%d%d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        memset(vis, 0, sizeof(vis));
        cout << "first level"<< endl;
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (!vis[i][0]){
                ans += dp(i, 0, -1);
            }
        }
        
        printf("%d %d %d", ans/2000, total-ans%2000, ans%2000);
        
    }
    return  0;
    
    
    
    
    
}
