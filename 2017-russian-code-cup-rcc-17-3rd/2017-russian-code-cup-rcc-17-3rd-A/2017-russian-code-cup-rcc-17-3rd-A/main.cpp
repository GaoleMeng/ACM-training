//
//  main.cpp
//  2017-russian-code-cup-rcc-17-3rd-A
//
//  Created by 孟高乐 on 5/6/17.
//  Copyright © 2017 GaoleMeng. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int T;
    scanf("%d",&T);
    while(T--){
        int cur;
        scanf("%d", &cur);
        string ans = "";
        while(cur > 0){
            cur --;
            int thisnum = cur % 26;
            cur /= 26;
            char ch = thisnum + 'A';
            ans = ch + ans;
        }
        cout << ans;
        printf("\n");
    }
    
}
