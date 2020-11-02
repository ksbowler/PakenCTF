#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct hen {
	int st;
	int go;
	long long cost = 0;
};

long long n,m,k,ans=0;
int visited[125];

/*bool cycle(vector<hen>& h, vector<int>& c) {
	long long cy[n][2],i,j;
	for (i=0;i<n;i++) {
		cy[i][0] = 0;
		cy[i][1] = 0;
	}
	for (i=0;i<c.size();i++) {
		if (c[i] == -1) continue;
		cy[h[c[i]].st][0] = 1;
		cy[h[c[i]].go][1] = 1;
	}
	for (i=0;i<n;i++) {
		if (cy[i][0] == 0 || cy[i][1] == 0) return false;
	}
	return true;
}

long long dp(vector<hen>& h, vector<int>& c, long long tc) {
	// v.erase(std::remove(v.begin(), v.end(), value_to_remove), v.end());
	long long i,ans=0,cc;
	if (cycle(h,c)) return tc;
	for (i=m;i<h.size();i++) {
		//cout << h[i].cost << endl;
		vector<int> temp = c;
		temp.push_back(i);
		if (maxc < tc+h[i].cost) continue;
		cc = dp(h,temp,tc+h[i].cost);
		if (cc < maxc) {
			maxc = cc;
			cout << maxc << endl;
		}
	}
	return maxc;
}

bool asc( const hen& left, const hen& right ){
	return left.cost < right.cost;
}

long long dfs(vector<hen>& h, int goal, int now, long long tcost) {
	if (now == goal) return tcost;
	//startからgoalまで行く,tcはその時のコスト,visは訪れた町数
	long long i,temp,maxc=25343439950;
	for (i=0;i<m+k;i++) {
		if (h[i].st == now) {
			temp = dfs(h,goal,h[i].go,tcost+h[i].cost);
			if (temp < maxc) maxc = temp;
		}
	}
	return maxc;
}*/

//int visited[n+1];


bool dfs(vector<hen>& h, int goal, int now) {
	if (goal == now) return true;
	long long i;
	for(i=0;i<m+k;i++) {
		if (h[i].st == now) {
			if (visited[h[i].go] == 0) {
				visited[h[i].go] = 1;
				if (dfs(h,goal,h[i].go)){
					ans += h[i].cost;
					return true;
				}
			}
		}
	}
	return false;
}

int main(void){
	long long i,j,temp;
	cin >> n >> m >> k;
	vector<hen> h(m+k);
	//vector<int> c(m+k);
	//c.assign(m+k,-1);
	//int vv[n+1];
	//for (i=0;i<=n;i++) vv[i] = 0;
	for (i=0;i<m;i++) {
		cin >> h[i].st >> h[i].go;
		//vv[h[i].st]++;
		//vv[h[i].go]++;
		//c[i] = i;
	}
	for (j=m;j<m+k;j++) {
		cin >> h[j].st >> h[j].go >> h[j].cost;
		//vv[h[j].st]++;
		//vv[h[j].go]++;
	}
	//sort(h.begin(),h.end(),asc);
	//vector<int> visited(n,-1);
	//ans = dfs(h,0,121,1,visited);
	//cout << "pakenCTF{" << ans << "}\n";
	/*for (i=1;i<=n;i++) {
		cout << i << " : " << vv[i] << endl;
	}*/
	//for(i=0;i<m+k;i++) {
//cout << h[i].st << endl;
	for (j=0;j<=n;j++) visited[j] = 0;
	//if (dfs(h,121,84)) {
//cout <<  h[i].st << " " << h[i].go << endl;
	
//cout << h[i].st << " " << temp << endl;
		/*if (temp < ans) {
			ans = temp;
		}*/
	bool tes = dfs(h,121,84);
	cout << "pakenCTF{" << ans << "}\n";
}
