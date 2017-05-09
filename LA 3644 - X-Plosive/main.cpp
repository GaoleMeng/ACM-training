#include <iostream>

using namespace std;

int uf[100000+10];

int find(int x){

	if (uf[x] != x){
		uf[x] = find(uf[x]);
		return uf[x];
	}
	else{
		return uf[x];
	}
}


int main(){

	int x, y;
	while(scanf("%d", &x)){
		for (int i = 0; i <= 100000; i++){
			uf[i] = i;
		}
		int count = 0;

		if (x != -1){
			scanf("%d", &y);

			if (x == y) count ++;
			else{
				x = find(x);
				y = find(y);
				if (x == y) count++;
				else{
					uf[x] = y;
				}
			}


			scanf("%d", &x);
		}
		printf("%d\n", count);
	}



}