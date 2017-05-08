#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){

	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		unordered_map<int, vector<int> > ma;
		for (int i = 0; i < n; i++){
			int tmp;
			scanf("%d", &tmp);
			ma[tmp].push_back(i+1);
		}
		while(m--){
			int x, y;
			scanf("%d%d", &x, &y);
			if (!ma.count(y) || x > ma[y].size()){
				printf("0\n");
				continue;
			}
			printf("%d\n",ma[y][x-1]);
		}

	}
}

