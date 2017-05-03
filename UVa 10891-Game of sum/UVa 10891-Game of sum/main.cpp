//
//  main.cpp
//  UVa 10891-Game of sum
//
//  Created by Cartman on 2017/5/3.
//  Copyright © 2017年 Cartman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int S[maxn], A[maxn], d[maxn][maxn], vis[maxn][maxn], n;



int dp(int i, int j){
    if (vis[i][j]) return d[i][j];
    vis[i][j] = 1;
    int m = 0;
    for (int k = i+1; k <= j; k++) m = min(m, dp(k,j));
    for (int k = i; k < j; k++) m = min(m, dp(i, k));
    d[i][j] = S[j]-S[i-1]-m;
    return d[i][j];
    
}




int main(int argc, const char * argv[]) {
    while (scanf("%d",&n) && n){
        S[0] = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &A[i]);
            S[i] = S[i-1] + A[i];
        }
        
        memset(vis, 0, sizeof(vis));
        printf("%d\n", 2*dp(1,n)-S[n]);
    
    }
    return 0;
    
    
    
}
