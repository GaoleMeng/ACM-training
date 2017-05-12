#include "algorithm"
#include "iostream"
#include "cstring"
#include "cstdio"
#include "string"
#include "stack"
#include "cmath"
#include "queue"
#include "set"
#include "map"
 
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
 
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
 
const int inf=0x3f3f3f3f;
const int maxn=1e6+5;
const int mod=20071027;
 
char str[maxn];
char word[maxn];
int dp[maxn];
int n;
 
 
 
struct Trie
{
    int sz;
    int ch[maxn][26];
    int val[maxn];
 
 
    void Init()
    {
        sz=1;
        val[0]=0;
        memset(ch[0],0,sizeof ch[0]);
 
    }
 
    void Insert(char *s)
    {
        int n = strlen(s);
        int u = 0;
        for(int i=0;i<n;++i)
        {
            if( ch[u][ s[i]-'a' ] ==0 )
            {
                memset(ch[sz],0,sizeof ch[sz]);//!!
                val[sz]=0;
                ch[u][ s[i]-'a' ] = sz;
                sz++;
            }
            u = ch[u][ s[i]-'a' ];
        }
        val[u]=n;
        //printf("insert:%s\n",s);
    }
 
    void Search(char * s,int k,int l)
    {
        int u = 0;
        for(int i=0;i<l;++i)
        {
            if( ch[u][ s[i]-'a' ]==0 )return;
            u = ch[u][ s[i]-'a' ];
            if( val[u] )
            {
                dp[k] = ( dp[k] + dp[k+val[u] ] )%mod;
            }
        }
    }
}trie;
 
int main()
{
    //freopen("in.txt","r",stdin);
    int cs=1;
    while( scanf("%s",&str)!=EOF )
    {
        trie.Init();
 
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%s",&word);
            trie.Insert(word);
        }
        int len = strlen(str);
        dp[len]=1;
        for(int i=len-1;i>=0;--i)
        {
            dp[i]=0;
            trie.Search(str+i,i,len-i);
        }
        printf("Case %d: %d\n",cs++,dp[0]);
    }
 
    return 0;
}