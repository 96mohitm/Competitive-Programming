#include <bits/stdc++.h>
using namespace std;
 
typedef long long 		ll;

#define get(x) cin >> x
#define pln(x) cout << x << "\n"

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	int t;
	get(t);
	while(t--){
		ll n;
		get(n);
		n = ((1LL)*(n)*(n+2)*(2*n + 1))/8;
		pln(n);
	}
}

