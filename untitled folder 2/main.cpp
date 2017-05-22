#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long int mod = 1e9+7;
typedef long long ll;

int main() {
    long long int N;
    cin >> N;
    vector<long long int> nums(N);
    if(N==1){
        cout << 0 <<"\n";
        return 0;
    }
    
    
    for (int i = 0; i < N; i++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    long long int m[300000+10];
    
    
    m[0] = 1;
    for (int i = 1; i < N; i++){
        m[i] = (m[i-1] << 1) % mod;
    }
    
    vector<ll> my_nums(N-1);
     
     for (int i = 1; i < N; i++)
     {
     my_nums[i-1] = nums[i] - nums[i - 1];
     }
     ll ans = 0;
     for (int i = 0; i < N-1; i++)
     {
     ans += (((my_nums[i]) % mod) * (m[N-1]-1)) % mod;
     }
     cout << ans << "\n";
}

