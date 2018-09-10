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

ll merge(int a[], int s, int m, int e){
	int i = s;
	int j = m+1;
	int k =	0;
	int temp[e-s+1];
	ll incnt = 0;
	while(i<=m&&j<=e){
		if(a[i]<=a[j])
			temp[k++] = a[i++];
		else{
			temp[k++] = a[j++];
			incnt += (ll)((ll)m+(ll)1-(ll)i);
		}
	}
	while(i<=m)
		temp[k++] = a[i++];
	while(j<=e)
		temp[k++] = a[j++];
	for(int i=s;i<=e;i++)
		a[i] = temp[i-s];
	return incnt;
}

ll mergesort(int a[], int s, int e){
	if(s<e){
		int m = (s+e)>>1;
		ll l = mergesort(a, s, m);
		ll r = mergesort(a, m+1, e);
		ll c = merge(a,s,m,e);
		return (l+r+c);
	}
	return (ll)0;
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
		int n;
		get(n);
		int a[n];
		rep(i,0,n) get(a[i]);
		ll result = mergesort(a,0,n-1);
		// rep(i,0,n) pln(a[i]);
		// pln("");
		pln(result);
	}
}
