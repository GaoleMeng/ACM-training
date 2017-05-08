//
//  main.cpp
//  UVa 11174
//
//  Created by 孟高乐 on 5/8/17.
//  Copyright © 2017 GaoleMeng. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    while(num--){
        int n, m;
        cin >> n >> m;
        int jie = 1;
        for (int i = 2; i <= n; i++){
            jie *= i;
            jie = jie % 1000000007;
        }
        
        
        
        
        
        
    }
}
