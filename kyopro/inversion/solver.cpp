#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
long long mod = 1000000007;
int main(void){
	long long n,k,i,m,len,j,t,l;
	cin >> n >> k;
	//要素n,転倒数kを求めるプログラム
	vector<long long> v,a;
	m = (n*(n-1)/2);
	v.resize(m+1);
	a.resize(m+1);
	v.assign(m+1,-1);
	a.assign(m+1,0);
	v[0] = 1;
	v[1] = 1;
	len = 2;
	for (i=3;i<=n;i++) {
		t = (i*(i-1))/2;
//cout << "t : " << t << endl;
//cout << "for j, len, t : " << len << " " << t << endl;
		for(j=0;j+len-1<=t;j++) {
//cout << "for j\n";
			for (l=0;l<len;l++) {
//cout << "for l\n";
				a[j+l] += v[l];
				a[j+l] = a[j+l]%mod;
			}
		}
		v = a;
		a.assign(m+1,0);
		len = t+1;
	}
	cout << v[k] << '\n';
/*for (i=0;i<=m;i++) cout << v[i] << " ";
cout << endl;*/
}
