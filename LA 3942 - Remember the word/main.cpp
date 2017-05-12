#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;




const int sigma_size = 26;
const int maxnode = 4000;
long long int d[300000+10];

struct Trie {
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int sz;
	Trie() {
		sz  = 1;
		memset(ch[0], 0, sizeof(ch[0]));
	}
	int idx(char c){
		return c-'a';
	}
	void insert(string& s, int v){
		int u = 0, len = s.length();
		for (int i = 0; i < len; i++){
			int c = idx(s[i]);
			if (!ch[u][c]){
				memset(ch[sz], 0, sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		val[u] = v;
	}
	void lookup(const string& s, int p){
		int u = 0, len = s.length();
		for (int i = p; i < len; i++){
			int c = idx(s[i]);
			if (!ch[u][c]){
				break;
			}
			u = ch[u][c];
			if (val[u]){
				if (i+1 >= s.length()){
					d[p] += (long long int)1 ;
					d[p] %= 20071027;
				}
				else{
					d[p] += d[1+i] ;
					d[p] %= 20071027;
				}
			}
		}
	}


};






 int main(){

 	
 	string str;
 	int kase = 1;
 	while (cin >> str){
 		int S;
 		cin >> S;
 		memset(d, 0, sizeof(d));
 		Trie dic;

 		for (int i = 0; i < S; i++){
 			string tmp;
 			cin >> tmp;
 			dic.insert(tmp, 1);
 		}
 		int slen = str.length();
 		for (int i = slen-1; i>=0; i--){
 			dic.lookup(str, i);
 		}
 		// for (int i =0; i< str.length(); i++){
 		// 	cout << d[i] <<" ";
 		// }
 		// cout << endl;
 		cout << "Case "<<kase++<<": "<< d[0]<<"\n"; 
 	}

 	return 0;
 }