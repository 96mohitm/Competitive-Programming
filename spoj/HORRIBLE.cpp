#include <bits/stdc++.h>
using namespace std;
 
typedef long long 		ll;
typedef long double 	ld;

typedef pair<int, int> 	pii;
typedef vector<int> 	vi;
typedef vector<pii>		vpi;
typedef vector<ll> 		vl;
typedef vector<vi> 		vvi;
typedef vector<ll> 		vl;
typedef vector<vl> 		vvl;

typedef unsigned long long int 	ul;

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
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

ll a[100001];
ll tr[400005];
ll lz[400005];


void build(int n, int s, int e){
	if(s==e){
		tr[n] = a[s];
		return;
	}
	int m =(s+e)>>1;
	build(2*n, s, m);
	build(2*n+1, m+1, e);
	tr[n] = tr[2*n] + tr[2*n+1];
}

void update(int n, int s, int e, int qs, int qe, ll v){
	//first resolve the lazy value
	if(lz[n]!=0){
		tr[n] = tr[n] + ((ll)(e-s+1))*lz[n];

		if(s!=e){
			lz[2*n]+=lz[n];
			lz[2*n+1]+=lz[n];
		}
		lz[n]=0;
	}
	//no ovlp
	if(s>qe||e<qs||s>e){
		return;
	}
	//complete
	if(s>=qs&&e<=qe){
		tr[n] = tr[n] + ((ll)(e-s+1))*v;
		if(s!=e){
			lz[2*n]+=v;
			lz[2*n+1]+=v;
		}
		return;
	}

	//leave
	if(s==e){
		tr[n]+=v;
		return;
	}
	int m = (s+e)>>1;
	update(2*n,s,m,qs,qe,v);
	update(2*n+1,m+1,e,qs,qe,v);
	tr[n] = tr[2*n]+tr[2*n+1];
}

ll query(int n, int s, int e, int qs, int qe){
	if(lz[n]!=0){
		tr[n] = tr[n] + ((ll)(e-s+1))*lz[n];

		if(s!=e){
			lz[2*n]+=lz[n];
			lz[2*n+1]+=lz[n];
		}
		lz[n]=0;
	}
	if(s>qe||e<qs||s>e){
		return 0;
	}
	if(s>=qs&&e<=qe){
		return tr[n];
	}
	int m =(s+e)>>1;
	ll l = query(2*n, s, m, qs, qe);
	ll r = query(2*n+1, m+1, e, qs, qe);
	ll tt = l+r;
	return tt;
}


void solve(){
	int t;
	get(t);
	while(t--){
		int n,q;
		get(n);get(q);
		rep(i,0,400005){
			tr[i]=lz[i]=0;
		}
		while(q--){
			int r,qs,qe;
			ll v;
			get(r);
			if(!r){
				get(qs);get(qe);get(v);
				update(1,1,n,qs,qe,v);
			}
			else{
				get(qs);get(qe);
				pln(query(1,1,n,qs,qe));
			}
		}
	}
}

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	solve();
}
