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

int a[200005];

struct tree{
	int m;
	int l;
	int r;
};

tree t[800024];
void build(int n, int s, int e){
	if(s == e){
		if(a[s] == 1){
			t[n].m = t[n].l = t[n].r =1;
		}
		else{
			t[n].m = t[n].l = t[n].r =0;
		}
		return;
	}
	int m = (s+e)>>1;
	build(2*n,s,m);
	build(2*n+1,m+1,e);
	t[n].m = max(max(t[2*n].m, t[2*n+1].m) , t[2*n].r + t[2*n+1].l);
	if(t[2*n].m == m-s+1)
		t[n].l = t[2*n].m + t[2*n + 1].l;
	else
		t[n].l = t[2*n].l;
	if(t[2*n +1].m == e - m)
		t[n].r = t[2*n +1].m + t[2*n].r;
	else
		t[n].r = t[2*n +1].r;
}

tree query(int n, int s, int e, int qs, int qe){
	tree ans;
	ans.m=ans.l=ans.r=0;
	if(s>e || qs > e||qe <s)
		return ans;
	if(qs<=s&&qe>=e)
		return t[n];
	int m = (s+e)>>1;
	tree lt = query(2*n, s, m, qs, qe);
	tree rt = query(2*n +1, m+1, e, qs, qe);
	ans.m = max(max(lt.m, rt.m) , lt.r + rt.l);
	if(lt.m == m-s+1)
		ans.l = lt.m + rt.l;
	else
		ans.l = lt.l;
	if(rt.m == e - m)
		ans.r = rt.m + lt.r;
	else
		ans.r = rt.r;
	return ans;
}


void solve(){
	int n,q,k;
	get(n);get(q);get(k);
	rep(i,1,n+1) get(a[i]);
	rep(i,n+1,2*n+1){
		a[i] = a[i-n];
	}
	build(1,1,2*n);
	string s;
	get(s);
	int shift =0;
	rep(i,0,q){
		if(s[i]=='!'){
			shift++;
			shift = shift % n;
		}
		else{
			tree res = query(1,1,2*n,n+1-shift, 2*n-shift);
			if(res.m > k)
				pln(k);
			else
				pln(res.m);
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

