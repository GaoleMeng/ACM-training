#include <cstdio>  
#include <algorithm> 
#include <iostream> 
  
using namespace std;  
  
const int maxn = 500 + 10;  
const int INF = 0x3f3f3f3f;  
  
int N, w[maxn][maxn], lx[maxn], ly[maxn], fa[maxn];  
bool S[maxn], T[maxn];  
  
bool match(int i){  
    S[i] = 1;  
    for(int j = 1; j <= N; j++) if(lx[i] + ly[j] == w[i][j] && !T[j]){  
        T[j] = 1;  
        if(!fa[j] || match(fa[j])){  
            fa[j] = i;  
            return 1;  
        }  
    }  
    return 0;  
}  
  
void update(){  
    int a = INF;  
    for(int i = 1; i <= N; i++) if(S[i])  
        for(int j = 1; j <= N; j++) if(!T[j])  
            a = min(a, lx[i] + ly[j] - w[i][j]);  
    for(int i = 1; i <= N; i++){  
        if(S[i]) lx[i] -= a;  
        if(T[i]) ly[i] += a;  
    }  
}  
  
void KM(){  
    for(int i = 1; i <= N; i++){  
        fa[i] = lx[i] = ly[i] = 0;  
        for(int j = 1; j <= N; j++) lx[i] = max(lx[i], w[i][j]);  
    }  
    for(int i = 1; i <= N; i++)  
        while(1){  
            for(int j = 1; j <= N; j++) S[j] = T[j] = 0;  
            if(match(i)) break;  
            else update();  
        }  
}  
void read(){  
    for(int i = 1; i <= N; i++)  
        for(int j = 1; j <= N; j++) scanf("%d", &w[i][j]);  
}  
void solve(){  
    for(int i = 1; i < N; i++) printf("%d ", lx[i]); printf("%d\n", lx[N]);  
    for(int i = 1; i < N; i++) printf("%d ", ly[i]); printf("%d\n", ly[N]);  
    int sum = 0;  
    for(int i = 1; i <= N; i++) sum += lx[i] + ly[i];  
    printf("%d\n", sum);  
}  
  


int main()
{
	while(cin >> N){

		for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                cin >> w[i][j];
            }
        }
        
        
        w[1][1] = 2;
         w[1][2] = 3;
         w[1][3] = 4;
         w[2][1] = 4;
         w[2][2] = 4;
     w[2][3] = 4;
        KM();
        for(int i = 1; i < N; i++) cout << lx[i] << " ";
        cout << lx[N] << "\n";
        for(int i = 1; i < N; i++) cout << ly[i] << " ";
        cout << ly[N] << "\n"; 
        int sum = 0;  
        for(int i = 1; i <= N; i++) sum += lx[i] + ly[i];  
        cout << sum << "\n";	
    }
}
