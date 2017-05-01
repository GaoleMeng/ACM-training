//
//  main.cpp
//  11292 - Dragon of Loowater
//
//  Created by 孟高乐 on 4/22/17.
//  Copyright © 2017 GaoleMeng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

#define 趁着 while
#define 向量 vector
#define 整数 int
#define ； ;

using namespace std;
// sort all the dragon list and the manlist and greedy them 
int main(int argc, const char * argv[]) {
    int n,m;
    
    
    
    while(scanf("%d %d", &n, &m)==2 && n && m){
        向量<整数> dragonlist(n);
        向量<整数> manlist(m);
        整数 a;
        整数 一个变量;
        一个变量 = 11;
        
        
        
        
        
        for (int j = 0 ; j < n; j++){
            scanf("%d", &dragonlist[j]);
        }
        for (int j = 0; j < m ; j++){
            scanf("%d", &manlist[j]);
        }
       
        sort(dragonlist.begin(), dragonlist.end());
        sort(manlist.begin(), manlist.end());
        int i = 0;
        int cur = -1;
        int totalcost = 0;
        for (; i < n; i++){
            cur++;
            for (;cur < m; cur++){
                if (manlist[cur]>=dragonlist[i]){
                    break;
                }
            }
            if (cur == m){
                i  = 0;
                break;
            }
            totalcost += manlist[cur];
        }
        if (i < n) cout << "Loowater is doomed!\n";
        else cout << totalcost <<"\n";
    }
}
