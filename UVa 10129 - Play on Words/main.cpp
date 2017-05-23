#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;


int ru[26];
int chu[26];
int p[26];
bool vis[26];

int findset(int x) {
    return p[x] != x ? p[x] = findset(p[x]) : x;
}

int main(){
    int N;
    cin >> N;
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    while(N--){
        int n;
        cin >> n;
        for(int i = 0; i < 26; i++) p[i] = i;
        memset(ru, 0, sizeof(ru));
        memset(chu, 0, sizeof(chu));
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < n; i++){
            string tmp;
            cin >> tmp;
            chu[tmp[0] - 'a'] ++;
            ru[tmp.back() - 'a'] ++;
            int x = findset(tmp[0] - 'a');
            int y = findset(tmp.back() - 'a');
            vis[tmp[0] - 'a'] = vis[tmp.back() - 'a'] = true;
            if (x !=  y) p[x] = y;
        }
        int theset;
        for (int i = 0; i < 26; i++){
            if (vis[i]){
                theset = findset(i);
                break;
            }
        }


        bool flag = false;
        for (int i = 0; i < 26; i++){
            if (vis[i] && findset(i) != theset){
                cout << "The door cannot be opened.\n";
                flag = true;
                break;
            }
        }
        if (flag){
            continue;
        }else{
            bool rudayuchu = false;
            bool chudayuru = false;
            int count = 0;
            bool enter = false;
            for (int i = 0; i < 26; i++){
                if (ru[i] != chu[i]){
                    if (ru[i]==chu[i]-1 && !rudayuchu){
                        count++;
                        rudayuchu = true;
                    }
                    else if (chu[i] == ru[i] - 1 && !chudayuru){
                        count++;
                        chudayuru = true;
                    }
                    else{
                        cout << "The door cannot be opened.\n";
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) continue;
            if (count == 1){
                cout << "The door cannot be opened.\n";
                continue;
            }
            else{
                cout << "Ordering is possible.\n";
            }

        }

        
        



    }



}
