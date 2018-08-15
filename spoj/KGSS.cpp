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
ll a[100001];
struct Tree{
	ll m1,m2;
};
Tree tr[400005];
void build(int n, int s, int e){
	if(s==e){
		tr[n].m1 = a[s];
		tr[n].m2 = INT_MIN;
		return;
	}
	int m = (s+e)>>1;
	build(2*n,s,m);
	build(2*n+1,m+1,e);
	int arr[4];
	arr[0]=tr[2*n].m1;
	arr[1]=tr[2*n].m2;
	arr[2]=tr[2*n+1].m1;
	arr[3]=tr[2*n+1].m2;
	sort(arr,arr+4);
	tr[n].m1 = arr[3];
	tr[n].m2 = arr[2];
}
void update(int n, int s, int e, int p, int v){
	if(s>e||s>p||e<p)
		return;
	if(s==e){
		tr[n].m1 = v;
		return;
	}
	int m = (s+e)>>1;
	update(n*2,s,m,p,v);
	update(2*n+1,m+1,e,p,v);
	int arr[4];
	arr[0]=tr[2*n].m1;
	arr[1]=tr[2*n].m2;
	arr[2]=tr[2*n+1].m1;
	arr[3]=tr[2*n+1].m2;
	sort(arr,arr+4);
	tr[n].m1 = arr[3];
	tr[n].m2 = arr[2];
}
Tree query(int n, int s, int e, int qs, int qe){
	Tree nw;
	if(s>e||s>qe||e<qs){
		nw.m1 = INT_MIN;nw.m2 = INT_MIN;
		return nw;
	}
	if(s>=qs&&e<=qe){
		return tr[n];
	}
	int m = (s+e)>>1;
	Tree l = query(2*n, s,m,qs,qe);
	Tree r = query(2*n+1,m+1,e,qs,qe);
	int arr[4];
	arr[0]=l.m1;
	arr[1]=l.m2;
	arr[2]=r.m1;
	arr[3]=r.m2;
	sort(arr,arr+4);
	nw.m1 = arr[3];
	nw.m2 = arr[2];
	return nw;
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
	int q;
	get(q);
	while(q--){
		char c;
		int x,y;
		get(c);
		if(c=='Q'){
			get(x);get(y);
			Tree r = query(1,1,n,x,y);
			pln(r.m1+r.m2);
		}
		else if(c=='U'){
			get(x);get(y);
			update(1,1,n,x,y);
		}
	}
}
