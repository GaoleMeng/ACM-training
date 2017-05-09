#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
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
		for (int i = 1; i <= n; i++){
			uf[i] = i;
		}

		char x[9];
		scanf("%s", x);
		while (x[0] != 'O'){
			if (x[0] == 'E'){
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
			scanf("%s", x);
		}
	}


}