//
//  main.cpp
//  UVa 11174
//
//  Created by 孟高乐 on 5/8/17.
//  Copyright © 2017 GaoleMeng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
long long quickPow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1)
            ans=(ans*a)%1000000007;
        a=(a*a)%1000000007;
        b=b>>1;
    }
    return ans;
}



int node[40000+1];   // node[i] represent the number of son of i including itself.
vector<int> adj[40000+1]; // adjacent list of the graph

int dfs(int u){
    
 //   cout << u <<endl;
    if (adj[u].size()==0){
        node[u] = 1;
        return 1;
    }
    
    int sum = 0;
    for (int i = 0; i < adj[u].size(); i++){
        sum += dfs(adj[u][i]);
    }
    sum++;
    node[u] = sum;
    return sum;
    
}



int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    while(num--){
        int n, m;
        cin >> n >> m;
        long long int jie = 1;
        long long int sum = 1;
        
       // int f[n+1];
        
        memset(node, 0, sizeof(node));
        memset(adj, 0, sizeof(adj));
        
        
        
        int fl[n+1]; // f[i] represent the father of i
        
        // calculate n's jiecheng.
        for (int i = 2; i <= n; i++){
            jie *= i;
            jie = jie % 1000000007;
        }
        
        for (int i = 0; i <=n; i++){
            fl[i] = 0;
        }
        
        
        // calculate the father of the son.
        for (int i = 0; i < m; i++){
            int fa, son;
            cin >> son >> fa;
            fl[son] = fa;
        }
        
        for (int i = 1; i <= n; i++){
            if (!fl[i]){
                adj[0].push_back(i);
            }
            else{
                adj[fl[i]].push_back(i);
            }
        }
        
        dfs(0);
        
        
        for(int i=1;i<=n;i++)
            sum=(sum * (node[i]))%1000000007;
        long long int ans=((jie)*quickPow(sum,1000000007-2)%1000000007)%1000000007;
        cout << ans << "\n";
    }
}
