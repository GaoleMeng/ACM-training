#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int uf[20000+10];
int d[20000+10];


pair<int, int> find(int x){
	if (uf[x] != x){
		pair<int, int> tmp = find(uf[x]);
		uf[x] = tmp.first;
		d[x] = tmp.second + d[x];
		return make_pair(uf[x], d[x]);
	}
	else{
		return make_pair(x, 0);
	}
}


int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		memset(d, 0, sizeof(d));
		for (int i = 0; i < n; i++){
			uf[i] = i;
		}

		char x;
		scanf("%c", &x);
		while (x != 'O'){
			if (x == 'E'){
				int tmp;
				scanf("%d", &tmp);
				printf("%d\n", find(tmp).second);
			}
			else{
				int u, v;
				scanf("%d%d", &u, &v);
				uf[u] = v;
				d[u] = abs(u-v) % 1000;
			}
			scanf("%c", &x);
		}
	}


}