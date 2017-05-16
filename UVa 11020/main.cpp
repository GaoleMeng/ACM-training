#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;
const int maxn = 15000+10;
int nums[maxn];

struct people{
    
    int x;
    int y;
    bool operator < (const people& rhs) const{
        return x < rhs.x || (x==rhs.x && y < rhs.y);
    }
};




int main(){
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        int n;
        cin >> n;
        memset(nums,  0, sizeof(nums));
        multiset<people> S;
        cout << "Case #"<<i+1<<":\n";
        for (int i = 0; i < n;i++){
            int x, y;
            cin >> x >> y;
            people tmp;
            tmp.x = x;
            tmp.y = y;
            auto it = S.lower_bound(tmp);
            if (it == S.begin() || (--it)->y > y ){
                S.insert(tmp);
                it = S.upper_bound(tmp);
                while(it != S.end() && it->y > y) S.erase(it++);
            }
            cout << S.size() << "\n";
        }
        cout << "\n";
        
    }
    return 0;
    
    
}
