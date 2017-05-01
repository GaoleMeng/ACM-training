//
//  main.cpp
//  10795-A different task
//
//  Created by 孟高乐 on 4/29/17.
//  Copyright © 2017 GaoleMeng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;



long long int helper(vector<int>& start, int stable, int fi){
    if (stable == -1) return 0;
    if (start[stable]==fi) return helper(start, stable-1, fi);
    return helper(start, stable-1, 6-fi-start[stable])+(1<<(stable));
}




int main(int argc, const char * argv[]) {
    
    int disk;
    int casenum = 0;
    scanf("%d", &disk);
    while (disk!=0){
        vector<int> start;
        vector<int> end;
        for (int i = 0; i < disk; i++){
            int temp;
            scanf("%d", &temp);
            start.push_back(temp);
        }
        for (int i = 0; i < disk; i++){
            int temp;
            scanf("%d", &temp);
            end.push_back(temp);
        }
        int k = disk-1;
        while(k >= 0 && end[k]==start[k]) k--;
        long long ans = 0;
        if (k==-1) printf("Case %d: %d\n", ++casenum, 0);
        else{
            int other = 6-end[k]-start[k];
            ans = helper(start, k-1, other)+helper(end, k-1, other)+1;
            printf("Case %d: %lld\n", ++casenum, ans);
        }
        scanf("%d", &disk);
    }
    return 0;
}
