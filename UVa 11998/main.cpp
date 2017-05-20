#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;


class node{
public:
    string var;
};

int main(){
    
    
    string tmp;
    while(cin >> tmp){
        bool head = false;
        deque<node> dic;
        node tt;
        dic.push_back(tt);
        for (int i = 0; i < tmp.length(); i++){
            if (tmp[i] == '['){
                    node t;
                    dic.push_front(t);
                head = true;
                
            }
            else if (tmp[i] == ']'){
                    node t;
                    dic.push_back(t);
                head = false;
            }
            else{
                if (head){
                    dic.front().var.push_back(tmp[i]);
                }
                else{
                    dic.back().var.push_back(tmp[i]);
                }
            }
        }
        while (!dic.empty()){
            node tt = dic.front();
            
            cout << tt.var;
            dic.pop_front();
        }
        cout << "\n";
    }
    
    return 0;
    
    
}
