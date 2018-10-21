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
int tree[400005] = {0};
int a[100005];

int n;
/*
Function for building the segment tree.
node - index of tree[] aay
start and end is the starting and ending index of the a[] aay.
*/
void build_tree(int node, int start, int end){
	//initialing the leaves.
	if(start == end){
		tree[node] = start;
		return;
	}
	//recursively initialize the segment tree in bottom up manner.
	int mid = (start + end) >> 1;
	build_tree(2*node , start, mid);
	build_tree(2*node + 1, mid + 1, end);
	// tree[node] = max(a[tree[2*node]], a[tree[2*node + 1]]);
	if(a[tree[2*node]] > a[tree[2*node + 1]]){
		tree[node] = tree[2*node];
	}
	else
		tree[node] = tree[2*node +1];
}
/*
Function for computing the result of the given query.
*/
int query(int node, int start, int end, int qstart, int qend){
	//No overlap
	if(start > end || qstart > end || qend < start)
		return 0;
	//Complete Overlap
	if(qstart <= start && qend >= end)
		return tree[node];
	//Partial overlap
	int mid = (start + end) >> 1;
	int q1 = query(2*node, start, mid, qstart, qend);
	int q2 = query(2*node + 1, mid+1, end, qstart, qend);
	// return max(a[q1], a[q2]);
	if(a[q1]>a[q2])
		return q1;
	else
		return q2;
}



int maxa(int a[], int s, int e){
	// int r=0;
	// int pos=s;
	// rep(i,s,e){
	// 	if(r<a[i]){
	// 		r=a[i];
	// 		pos=i;
	// 	}
	// }
	int r = query(1, 1, n, s, e);
	// watch(a[r]);
	return r;
}

int total(int a[], int s, int e){
	int p = maxa(a,s,e);
	// watch(p);
	if(s==p || e==p)
		return 1;
	// if()
	int left = total(a, s, p-1);
	int right = total(a,p+1,e);
	int r = min(left, right) +1;
	return r;
}


void solve(){
	a[0] = INT_MIN;
	int t;
	get(t);
	while(t--){
		// int n;
		get(n);
		// int a[n+1];
		rep(i,1,n+1)
			get(a[i]);
		build_tree(1, 1, n);
		int r;
		r = total(a,1,n);
		pln(r);
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
