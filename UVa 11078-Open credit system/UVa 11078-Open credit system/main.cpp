//
//  main.cpp
//  UVa 11078-Open credit system
//
//  Created by 孟高乐 on 5/1/17.
//  Copyright © 2017 GaoleMeng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        vector<int> nums;
        nums.reserve(n);
        if (n == 0) printf("0\n");
        
        while(n--){
            int tmp;
            scanf("%d", &tmp);
            nums.push_back(move(tmp));
        }
        
        
        int max = nums[0];
        int ans = 0x80000000;
        for (int i = 1; i < nums.size(); i++){
            ans = ans > (max - nums[i]) ? ans : (max - nums[i]);
            max = max > nums[i] ? max : nums[i];
        }
        
        
        printf("%d\n", ans);
    }
    return 0;
}
