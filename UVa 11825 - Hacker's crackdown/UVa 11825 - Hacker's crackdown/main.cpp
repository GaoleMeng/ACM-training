//
//  main.cpp
//  UVa 11825 - Hacker's crackdown
//
//  Created by 孟高乐 on 5/3/17.
//  Copyright © 2017 GaoleMeng. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;


const int maxn = 16;
int P[maxn];

int n;


bool cover(int S0){
    int cover = 0;
    for (int i = 0; i < n; i++){
        if (S0 & (1<<i)){
            cover|=P[i];
        }
    }
    return cover == (1<<n)-1;
}




int main(int argc, const char * argv[]) {
    int kk = 0;
    while (scanf("%d", &n) == 1 && n){
        kk++;
        for (int i = 0; i < n; i++){
            int m, x;
            scanf("%d", &m);
            P[i] = 1 << i;
            while(m--){
                scanf("%d", &x);
                P[i] |= 1 << x;
            }
        }
        
        int F[1<<n];
        F[0] = 0;
        
        for (int i = 0; i < 1<<n; i++ ){
            F[i] = 0;
            for (int S0 = i; S0; S0 = (S0-1)&i){
                if (cover(S0)) F[i] = max(F[i], F[i^S0]+1);
            }
        }
        
        printf("Case %d: %d\n", kk, F[1<<n-1]);
    
        
    }
    
    
    
    
    
    
    
}
