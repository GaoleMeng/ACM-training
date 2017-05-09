#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;


class item{
public:
	int sum;
	int bx;
	item(){
		sum = 0;
		bx = 0;
	}
	item (int a, int b): sum(a), bx(b){};
};

class func{
public:
	bool operator()(const item& a, const item& b){
		return a.sum > b.sum;
	}
};




void merge(vector<int>& a, vector<int>& b, vector<int>& c, int k){
	priority_queue<item, vector<item>, func> pq;
	for (int i = 0; i < k; i++){
		item tmp;
		tmp.sum = a[i] + b[0];
		tmp.bx = 0;
		pq.push(tmp);
	}

	for (int i = 0; i < k; i++){
		c[i] = pq.top().sum;
		item tmp;
		if (pq.top().bx == k-1) break;
		tmp.sum = pq.top().sum - b[pq.top().bx] + b[pq.top().bx+1];
		tmp.bx = pq.top().bx + 1;
		pq.pop();
		pq.push(tmp);

	}
}




int main(){
	int k;
	while(scanf("%d",  &k) == 1){
		vector<vector<int> > ma;
		ma.resize(k);
		for (int i = 0; i < k; i++){
			ma[i].resize(k);
			for (int j = 0; j < k; j++){
				cin >> ma[i][j];
			}
			sort(ma[i].begin(), ma[i].end());
		}
		for (int i = 1; i < k; i++){
			merge(ma[0], ma[i], ma[0], k);
		}

		cout << ma[0][0];
		for (int i = 1; i < k; i++){

			cout << " " << ma[0][i];

		}
		cout << "\n";


		





	}
	return 0;



}