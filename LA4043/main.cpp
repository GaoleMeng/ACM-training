#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 100 + 10;
const double eps = 1e-10;

int n, fa[maxn];
double w[maxn][maxn], Lx[maxn], Ly[maxn];
bool S[maxn], T[maxn];

struct Point{
    double x, y;
    Point(double x = 0, double y = 0):x(x), y(y){}
};

Point ant[maxn], tree[maxn];

double Dis(Point A, Point B){
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}


bool match(int i){
    S[i] = 1;
    for(int j = 1; j <= n; j++) if(fabs(Lx[i]+Ly[j]-w[i][j]) < eps && !T[j]){
        T[j] = 1;
        if(!fa[j] || match(fa[j])){
            fa[j] = i;
            return 1;
        }
    }
    return 0;
}

void update(){
    double a = 1 << 30;
    for(int i = 1; i <= n; i++) if(S[i])
        for(int j = 1; j <= n; j++) if(!T[j])
            a = min(a, Lx[i]+Ly[j]-w[i][j]);
    for(int i = 1; i <= n; i++){
        if(S[i]) Lx[i] -= a;
        if(T[i]) Ly[i] += a;
    }
}

void KM(){
    for(int i = 1; i <= n; i++) fa[i] = Lx[i] = Ly[i] = 0;
    for(int i = 1; i <= n; i++){
        while(1){
            for(int j = 1; j <= n; j++) S[j] = T[j] = 0;
            if(match(i)) break;
            else update();
            
        }
    }
}

int main()
{
	int n;
	while(cin >> n){
		memset(ant, 0, sizeof(ant));
		memset(tree, 0, sizeof(tree));
		for (int i = 0; i < n; i++) cin >> ant[i].x >> ant[i].y;
		for (int i = 0; i < n; i++) cin >> tree[i].x >> tree[i].y;

		...

	}



}
