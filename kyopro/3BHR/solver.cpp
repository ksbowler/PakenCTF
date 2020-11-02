#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct enemy {
	long long x;
	long long y;
	int p;
	set<long long> save;
};

int main(void){
	long long h,w,n,i,ans=0,bef,death=0,j;
	cin >> h >> w >> n;
	vector<enemy> e(n);
	multiset<long long> hh;
	multiset<long long> ww;
	set<long long> dead;
	for (i=0;i<n;i++) {
		cin >> e[i].x >> e[i].y >> e[i].p;
	}
	for (i=0;i<n;i++) {
		if (e[i].p == 1) {
			for (j=0;j<n;j++) {
				if (e[j].p == 0 && e[i].x == e[j].x) {
					e[j].save.insert(i);
				}
			}
		} else {
			for (j=0;j<n;j++) {
				if (e[j].p == 1 && e[i].y == e[j].y) {
					e[j].save.insert(i);
				}
			}
		}
		//if (e[i].p == 1) hh.insert(e[i].y);
		//else ww.insert(e[i].x);
	}
/*for (i=0;i<n;i++) {
	cout << e[i].x << e[i].y << e[i].p << "set save : ";
	for (auto x : e[i].save) {
		cout << x << " ";
	}
	cout << endl;
}*/
	
	while (true) {
		for (i=0;i<n;i++) {
			if(dead.count(i) > 0) continue;
			if(e[i].save.size() == 0) {
				dead.insert(i);
				for (j=0;j<n;j++) {
					if(dead.count(j) > 0) continue;
					if(e[j].save.count(i) > 0) e[j].save.erase(i);
				}
			}
		}

		if(death == dead.size()) break;
		death = dead.size();
	}
	cout << dead.size() << endl;
}
