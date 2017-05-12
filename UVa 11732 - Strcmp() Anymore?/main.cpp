/*
 * Author: Gatevin
 * Created Time:  2015/2/12 15:37:01
 * File Name: Mononobe_Mitsuki.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;

/*
 * 对于比较函数
 * int strcmp(char *s, char *t)
 * {
 *    int i;
 *    for (i=0; s[i]==t[i]; i++)
 *        if (s[i]=='\0')
 *            return 0;
 *    return s[i] - t[i];
 * }
 * 现在所说的字符串都要加上'\0'计算
 * 要注意如果字符串S == T比较次数为2*L (L为字符串长度)
 * 因为L次都比较了S[i] == T[i] && S[i]是否为'\0'
 * 如果S和T相同部分长度为L但不一样,比较次数为2*L - 1(第L组没有比较'\0')
 */

/*
 * 对于此题使用常规Trie树会超时
 * 这里使用了左儿子右兄弟的树的表示方法
 */
#define maxn 4444444

struct TreeNode
{
    char value;//节点字符
    int same_cnt;//如果有多个串在此点结尾, 记录在此结尾的串的数量-1
    int count;//count记录当前节点有多少个串覆盖过
    int lchild;//指向第一个儿子
    int rchild;//指向相邻的下一个兄弟
};

struct Trie
{
    int root, L;//L为当前Trie中的节点数
    lint ans;//最终的答案
    TreeNode node[maxn];
    int newnode(char value)//建立值为value的新节点,返回节点下标
    {
        node[L].lchild = node[L].rchild = -1;
        node[L].same_cnt = node[L].count = 0;
        node[L++].value = value;
        return L - 1;
    }
    void init()
    {
        ans = 0LL, L = 0;
        root = newnode(0);
        return;
    }
    void insert(char *s)//一边插入一边统计比较次数
    {
        int len = strlen(s);
        int now = node[root].lchild;//从root向下一层
        int same = 1, save = root;//same判断当前插入的串和之前的串是否有相同
        for(int i = 0; i <= len; i++)
        {
            if(now == -1)//当前s[i]的节点不存在,直接新建
            {
                node[save].lchild = newnode(s[i]);
                now = node[save].lchild;
                node[now].count = 1;
                same = 0;//新建了节点一定没有重复
            }
            else
            {
                if(i) ans += node[now].count;//对于相同长度L > 0的对象来说比较次数要少一次
                ans += node[now].count++;
                while(node[now].rchild != -1 && node[now].value != s[i])//沿右指针检查兄弟节点
                    now = node[now].rchild;
                if(node[now].value != s[i])//没有找到s[i]能对应的节点
                {
                    node[now].rchild = newnode(s[i]);//在同一层新建兄弟节点
                    now = node[now].rchild;
                    same = 0;//新建节点,无重复
                }
            }
            save = now;//save记录当前now节点的父亲节点
            now = node[save].lchild;//继续向下
        }
        if(same) node[save].same_cnt++;//相同的串出现了
        ans += node[save].same_cnt;
    }
};

Trie trie;
char in[1010];

int main()
{
    int N, cas = 1;
    while(scanf("%d", &N), N)
    {
        trie.init();
        for(int i = 0; i < N; i++)
            scanf("%s", in), trie.insert(in);
        printf("Case %d: %lld\n", cas++, trie.ans);
    }
    return 0;
}
