#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef unsigned long long int ul;

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
int a[50001];
struct Tree{
	ll prefix = INT_MIN, sufix=INT_MIN, total=0, best=INT_MIN;
};
Tree t[200006];
//building the segment tree
void build(int n, int s, int e){
	if(s==e){
		t[n].prefix = a[s];
		t[n].sufix = a[s];
		t[n].total = a[s];
		t[n].best = a[s];
		return;
	}
	int m = (s+e)>>1;
	build(2*n, s, m);
	build(2*n +1, m+1, e);
	t[n].prefix = max(t[2*n].prefix , t[2*n].total + t[2*n +1].prefix);
	t[n].sufix = max(t[2*n +1].sufix, t[2*n +1].total + t[2*n].sufix);
	t[n].total = t[2*n].total + t[2*n +1].total;
	t[n].best = max(t[2*n].sufix + t[2*n +1].prefix ,max(t[2*n].best, t[2*n +1].best));
}

Tree query(int n, int s, int e, int qs, int qe){
	Tree re;
	if(s>e||qs>e||qe<s){
		re.prefix = re. sufix = re.best = INT_MIN;
		re.total = 0;
		return re;
	}
	//complete overlap
	if(s>=qs && e<=qe){
		return t[n];
	}
	int m = (s+e)>>1;
	Tree l = query(2*n, s, m, qs, qe);
	Tree r = query(2*n +1, m+1, e, qs, qe);
	re.prefix = max(l.prefix, l.total + r.prefix);
	re.sufix = max(r.sufix, r.total + l.sufix);
	re.best = max(l.sufix + r.prefix, max(l.best, r.best));
	// return max(t[2*n].sufix + t[2*n+1].prefix ,max(l.best,r.best));
	re.total = l.total + r.total;
	return re;
}

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	int n,i;
	get(n);
	rep(i,1,n+1) get(a[i]);
	build(1,1,n);
	// rep(i,1,6) pls(t[i].max);
	int q;
	get(q);
	while(q--){
		int a,b;
		get(a);get(b);
		Tree r = query(1,1,n,a,b);
		pln(r.best);
	}
}
