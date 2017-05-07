//
//  main.cpp
//  LA 4794 - Sharing Chocolate
//
//  Created by 孟高乐 on 5/6/17.
//  Copyright © 2017 GaoleMeng. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;


const int maxn = 15;

int sum[1 << 15];
int a[maxn];


int main(int argc, const char * argv[]) {
    
    int T;
    while (scanf("%d", &T) && T){
        int x;
        int y;
        scanf("%d%d", &x, &y);
        for (int i = 0; i < T; i++){
            scanf("%d", &a[i]);
        }
        
        for (int i = 0; i < 1<<T; i++)
            for (int j = 0; i < T; i++) if (j << T & i) sum[i] += a[j];
        
        
        
        
        
        
        
        
        
        
    }
    
    
    
}
