#include <bits/stdc++.h>
using namespace std;
 
typedef long long 		ll;
typedef long double 	ld;
typedef vector<int> 	vi;
typedef vector<ll> 		vl;
typedef vector<vi> 		vvi;
typedef vector<ll> 		vl;
typedef vector<vl> 		vvl;
typedef pair<int, int> 	pii;

typedef unsigned long long int 	ul;

#define MOD 1000000007
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define vget(v) rep(i, 0, v.z) get(v[i]);
#define vsort(v) sort(v.begin(), v.end())
#define get(x) cin >> x
#define put(x) cout << x
#define pls(x) cout << x << ' '
#define pln(x) cout << x << "\n"
#define vget(v) rep(i, 0, v.z) get(v[i]);
#define rep(i, begin, end) \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define watch(x) cout << (#x) << " is " << (x) << endl

void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
// bool cmp(const pii a,const pii b ){
// 	return a.first < b.first;
// }
// x = lower_bound(vp.begin(), vp.end(), val,[](pii lhs, pii rhs) -> bool { return lhs.first < rhs.first; });
int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	int n,m,d;
	get(n);get(m);get(d);
	vi a(n);
	set<pii > vp;
	rep(i,0,n){
		get(a[i]);
		// vp[i].first =a[i];
		// vp[i].second =i;
		vp.insert({a[i], i});
	}
	// vsort(vp);
	int i=1;
	while(sz(vp)){
		// int j=0;
		a[vp.begin()->second]=i;
		int tm=vp.begin()->first;
		vp.erase (vp.begin());
		while(1){
			pii val = {tm+d+1,0};
			// auto it = lower_bound(vp.begin(), vp.end(), val,[](pii lhs, pii rhs) -> bool { return lhs.first < rhs.first; });
			auto it = vp.lower_bound(val);
			if(it == vp.end()){
				
				break;
			}

			// if(vp[j].first>tm+d){
			tm=it->first;
			a[it->second]=i;
			vp.erase (it);
			// }
		}
		i++;
	}
	i--;
	pln(i);
	rep(k,0,n)
		pls(a[k]);
}