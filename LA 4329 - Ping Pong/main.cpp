#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

int c[100001];
int lowerbit(int x){
	return x & (-x);
}

int sum (int x){
	int ret  = 0;
	while (x > 0){
		ret += c[x];
		x-=lowerbit(x);
	}
	return ret;

}

void add(int x, int d){
	
	while(x <= 100000){
		c[x]+=d;
		x += lowerbit(x);
	}
}


int main(){
	
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		vector<int> a;
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++){
			int tmp;
			scanf("%d", &tmp);
			a.push_back(tmp);
		}
		vector<int> left;
		vector<int> right;
		for (int i = 0; i < n; i++){
			add(a[i], 1);
			left.push_back(sum(a[i]-1));
		}
		memset(c, 0, sizeof(c));
		reverse(a.begin(), a.end());
		for (int i = 0; i < n; i++){
			add(a[i], 1);
			right.push_back(sum(a[i]-1));
		}
		reverse(right.begin(), right.end());
		long long int count = 0;
		for (int i = 1; i < n-1; i++){
			count += (long)left[i]*(long)(n-i-1-right[i]) + (long)(i-left[i])*(long)right[i];
		}
		printf("%lld\n", count);




	}





}