//
//  main.cpp
//  UVa 11137 - Ingenuous Cubrency
//
//  Created by 孟高乐 on 5/7/17.
//  Copyright © 2017 GaoleMeng. All rights reserved.
//

#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    long long int li[22];
    for (long long int i = 1; i <= 21; i++){
        li[i] = i * i * i;
    }

    while (scanf("%d", &n)!=EOF){
        long long int f[n+1];
        
        
        for (long long int i = 0; i < n+1; i++){
            f[i] = 1;
        }
        
        for (long long int i = 2; i <= 21; i++){
            for (long long int j = 0; j <= n; j++){
                if (j-li[i] >= 0) f[j] += f[j-li[i]];
            }
        }
        
        printf("%lld\n", f[n]);
        
        
    }
    
}
