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
	int n;
	get(n);
	vl a(n),b(n);
	rep(i,0,n)
		get(a[i]);
	rep(i,0,n)
		get(b[i]);
	vsort(a);
	vsort(b);
	int i=n-1;
	int j=n-1;
	int t = 2*n;
	ll as=0,bs=0;
	for(int k=0;k<t;k++){
		if(k&1){//b chance
			if(i==-1)
				bs+=b[j--];
			else if(j==-1)
				i--;
			else if(b[j]>a[i])
				bs+=b[j--];
			else
				i--;
		}
		else{//a chance
			if(i==-1){
				j--;
			}
			else if(j==-1)
				as+=a[i--];
			else if(a[i]>b[j]){
				as+=a[i--];
			}
			else{
				j--;
			}
		}
	}
	ll r = as - bs;
	pln(r);
}
