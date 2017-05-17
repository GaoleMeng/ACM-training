#include <cstdio>
#include <cstring>
  
const int maxnode = 1000 * 4000 + 10;
long long ans;
  
  struct Tire
  {
     int son[maxnode], bro[maxnode], tot[maxnode];
     char ch[maxnode];
     int sz;
     void clear() { sz = 1; son[0] = bro[0] = tot[0] = 0; }
 
     void insert(char* s)
     {
         int u = 0, v, n = strlen(s);
         tot[0]++;
         for(int i = 0; i <= n; i++)
         {
             bool found = false;
             for(v = son[u]; v; v = bro[v])
                 if(ch[v] == s[i]) { found = true; break; }
             if(!found)
             {
                 v = sz++;
                 son[v] = 0;
                 bro[v] = son[u];
                 son[u] = v;
                 tot[v] = 0;
                 ch[v] = s[i];

             }
             ans += (tot[u] - 1 - tot[v]) * (2 * i + 1);
            if(i == n) ans += tot[v] * (2 * i + 2);
             u = v;
             tot[u]++;
         }
     }
 }tire;
 
 const int maxl = 1000 + 10;
 char s[maxl];
 
 int main()
 {
     //freopen("in.txt", "r", stdin);
 
     int n, kase = 0;
    while(scanf("%d", &n) == 1 && n)
     {
        tire.clear();
         ans = 0;
         for(int i = 0; i < n; i++) { scanf("%s", s); tire.insert(s); }
         printf("Case %d: %lld\n", ++kase, ans);
     }
 
     return 0;
 }