#include <iostream>
#include <vector>
#include <string.h>
#include <cstdio>

using namespace std;
typedef long long ll;


const int maxn = 1000000+10;
char str[maxn];
int f[maxn];

int main(){
	int n, kase = 0;
	while (scanf("%d", &n) == 1 && n){
		memset(str, 0, sizeof(str));
		for (int i = 0; i < n; i++){
			scanf("%c", &str[i]);
		}
		f[0] = f[1] = 0;
		for (int i = 1; i < n; i++){
			int j = f[i];
			while(j && str[j]!=str[i]) j = f[j];
			f[i+1] = (str[i] == str[j]) ? j+1: 0; 
		}
		printf("Test case #%d\n", ++kase);
		for (int i = 2; i <= n; i++){
			if (f[i]>0 && i  % (i-f[i])==0) printf("sfsdfs");
			printf("\n");
		}





	}


	return 0;

}