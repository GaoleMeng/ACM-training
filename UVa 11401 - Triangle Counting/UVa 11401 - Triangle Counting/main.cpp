//
//  main.cpp
//  UVa 11401 - Triangle Counting
//
//  Created by 孟高乐 on 5/6/17.
//  Copyright © 2017 GaoleMeng. All rights reserved.
//

#include <iostream>
using namespace std;



int main(int argc, const char * argv[]) {
    int n;
    long long int f[1000000+10];
    long long int sum = 0;
    for (long long int i = 4; i <= 1000000; i++){
        sum += ( (i-1)*(i-2)/2 - (i-1)/2  )/2;
        f[i] = sum;
    }
    
    
    
    while(scanf("%d", &n) && n >= 3){
        printf("%lld\n", f[n]);
    }
}
