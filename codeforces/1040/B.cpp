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
	int n,k;
	get(n);get(k);
	int t = 2*k+1;
	int a[1000];
	if(n%t==0){
		int r  = n/t;
		pln(r);
		int i=1+k;
		while(i<=n){
			pls(i);
			i+=(2*k+1);
		}
		// pln("1");
	}
	else if(k>=(n/2)){
		pln("1");
		if(n&1){
			n=n/2;
			n++;
		}
		else
			n=n/2;
		pln(n);
		// pln("2");
	}
	else{
		int s = k+1;
		int r=0,total=0,i,e;
		i=k+1;
		while(!r){
			total =0;
			e=i+k;
			int c=i;
			while(c<=n){
				a[total++] =c;
				e= c+k;
				c+=(2*k+1);
			}
			if(e>=n){
				r=1;
			}
			i--;
		}
		// total++;
		pln(total);
		rep(x,0,total)
		pls(a[x]);
		// pln("3");
	}
}
