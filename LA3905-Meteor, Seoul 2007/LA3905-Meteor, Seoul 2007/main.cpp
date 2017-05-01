//
//  main.cpp
//  LA3905-Meteor, Seoul 2007
//
//  Created by 孟高乐 on 5/1/17.
//  Copyright © 2017 GaoleMeng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class event{
public:
    double time;
    bool whetherleft;
};

struct func{
    bool operator() (const event& a, const event& b){
        if (a.time < b.time) return true;
        if (a.time == b.time && b.whetherleft==true) return true;
        return false;
    }
};

int minnum(int x, int y){
    return x < y? x:y;
}

int maxnum(int x, int y){
    return x > y? x:y;
}


int w,h,n;

void update(int x, int y, int a, int b, double& L, double& R){
    if (a==0) {
        if (x>=w || x<=0) R=L-1;
        return;
    }
    if (b==0) {
        if (y>=h || y<=0) R=L-1;
        return;
    }
    if (a > 0){
        L = maxnum(L, -(double)x/a);
        R = minnum(R, (double)(w-x)/a);
    }
    if (a < 0){
        L = maxnum(L, (double)(w-x)/a);
        R = minnum(R, (double)(-x)/a);
    }
    if (b > 0){
        L = maxnum(L, -(double)y/b);
        R = minnum(R, (double)(h-y)/b);
    }
    if (b < 0){
        L = maxnum(L, (double)(h-y)/b);
        R = minnum(R, (double)(-y)/b);
    }
}


int main(int argc, const char * argv[]) {
    int T;
    scanf("%d",&T);
    while(T--){

        scanf("%d%d%d", &w,&h,&n);
        vector<event> events;
        
        while (n--){
            double L = 0, R = 1e9;
            int x,y,a,b;
            scanf("%d%d%d%d",&x,&y,&a,&b);
            update(x, y, a, b, L, R);
            if (R > L){
                event tmp1;
                event tmp2;
                tmp1.time = L;
                tmp1.whetherleft = true;
                tmp2.time = R;
                tmp2.whetherleft = false;
                events.push_back(tmp1);
                events.push_back(tmp2);
            }
        }
        func myfunc;
        sort(events.begin(), events.end(), myfunc);
        int cnt = 0, ans = 0;
        
        for (auto& x: events){
            if (x.whetherleft) {cnt++; ans = maxnum(ans, cnt);}
            else cnt--;
        }
        printf("%d\n", ans);
        
    }
    
}
