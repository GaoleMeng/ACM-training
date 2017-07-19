#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef unordered_set<int> Set;
vector<Set> cache;
unordered_map<Set, int> setMap;

int searchSet(Set a){
    if(setMap.count(a)){
        return setMap[a];
    }
    else{
        cache.push_back(a);
        setMap[a] = cache.size()-1;
        return cache.size();
    }
}

int main(){
    int N;
    cin >> N;

    while(N--){
        int n;
        cin >> n;
        
        deque<Set> com;
        
        while(n--){
            string thisline;
            cin >> thisline;

            if (thisline[0] == 'P'){
                com.push_back(Set());
            }
            else if (thisline[0] == 'D'){
                com.push_back(com.back());
            }
            else{
                Set c;
                Set a = com.back();
                com.pop_back();
                Set b = com.back();
                com.pop_back();
                set_union(a.begin(), a.end(), b.begin(), b.end(), )
                


            }





        }





    }



}