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

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	int t;
	get(t);
	int h,w,i,j;
	while(t--){
		get(h);get(w);
		int a[h][w];
		rep(i,0,h)
			rep(j,0,w)
				get(a[i][j]);

		rep(i,1,h){
			rep(j,0,w){
				// int r=a[i][j];
				int n=0;
				if(j>0)
					n=a[i-1][j-1];
				if(j< w-1 && n<a[i-1][j+1])
					n=a[i-1][j+1];
				if(n<a[i-1][j])
					n=a[i-1][j];
				a[i][j]+=n;
			}
		}
		int k = h-1;
		int r=0;
		rep(j,0,w){
			if(r<a[k][j])
				r=a[k][j];
		}
		pln(r);
	}
}
