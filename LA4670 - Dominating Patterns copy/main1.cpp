#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
	

int f[100];


int idx(char c){
	return c-'a';
}

void find(char* str, char* ss){

	int j = 0;
	int m = strlen(ss);
	for (int i = 0; i < strlen(str); i++){
		while (j && ss[j]!=str[i]) j = f[j];
		if (ss[j]==str[j])j++;
		if (j == m) printf("find at %d", j-m+1);
	}
}

void getfail(char* ss){
	f[0] = 0;
	f[1] = 0;
	for (int i = 1; i < strlen(ss); i++){
		int j = f[i];
		while (j && ss[i] != ss[j]) j = f[j];

		f[i+1] = P[]
	}



}



int main(){

}
