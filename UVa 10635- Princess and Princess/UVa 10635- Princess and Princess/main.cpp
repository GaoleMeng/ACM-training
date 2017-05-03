//
//  main.cpp
//  UVa 10635- Princess and Princess
//
//  Created by Cartman on 2017/5/2.
//  Copyright © 2017年 Cartman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int T;
    scanf("%d", &T);
    int i = 0;
    
    while(T--){
        i++;
        int n, p, q;
        scanf("%d%d%d", &n, &p, &q);
        vector<int> plist(p+1);
        vector<int> qlist(q+1);
        vector<int> duiyin;
        for (int i = 0; i < p+1; i++) scanf("%d", &plist[i]);
        for (int i = 0; i < q+1; i++) scanf("%d", &qlist[i]);
        unordered_map<int, int> m;
        for (int i = 0; i < p+1; i++){
            m[plist[i]] = i+1;
        }
        for (int i = 0; i < q+1; i++){
            if (m.count(qlist[i])>0) duiyin.push_back(m[qlist[i]]);
        }
        vector<int> g(duiyin.size()+1, 0x7fffffff);
        g[0] = 0x80000000;
        int ans = 0;
        for ( int i = 0; i < duiyin.size(); i++){
            int k = lower_bound(g.begin()+1 , g.end(), duiyin[i])-g.begin();
            ans = max(ans, k);
            g[k] = duiyin[i];
        }
        printf("Case %d: %d\n", i, ans);
        
        
        
    }
    
    
    
    
    
    
    
    
}
