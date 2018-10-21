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

void fast(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int parent[51];
int size[51];

void make_set(int v){
	parent[v] = v;
	size[v] =1;
}

int find_set(int v){
	if(v==parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
//optimazations using sizes
void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(size[a] < size[b])
			swap(a,b);
		parent[b] = a;
		size[a] +=size[b];
	}
}


void solve(){
	int t;
	get(t);
	while(t--){
		int n;
		get(n);
		int a[n],hash[51];
		rep(i,0,51){
			hash[i] = 0;
			make_set(i);
		}
		int sg;
		rep(i,0,n){
			get(a[i]);
			hash[a[i]]++;
			sg=hash[a[i]];
		}
		if(n==1){
			pln("0");
			pln(a[0]);
			continue;
		}
		else if(sg==n){
			pln("1");
			if(a[0]==47)
				pls("43");
			else
				pls("47");
			rep(i,1,n)
				pls(a[i]);
			pln("");
			continue;
		}
		rep(i,0,n-1){
			rep(j,0,n){
				if(__gcd(a[i],a[j]) == 1){
					union_sets(i,j);
				}
			}
		}
		int x = find_set(0);
		x = size[x];
		if(x == n){
			pln("0");
			rep(i,0,n)
				pls(a[i]);
			pln("");
		}
		else{
			pln("1");
			if(a[1]==43)
				pls("47");
			else
				pls("43");
			rep(i,1,n)
				pls(a[i]);
			pln("");
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
