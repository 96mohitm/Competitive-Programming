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
//recursive
int minsteps(int n){
	if(n==1)
		return 0;

	if(n%6==0)
		return min(minsteps(n-1)+1,min(minsteps(n/2)+1,minsteps(n/3)+1 ));
	if(n%2==0)
		return min(minsteps(n-1)+1,minsteps(n/2)+1);
	if(n%3==0)
		return min(minsteps(n-1)+1,minsteps(n/3)+1);

	return minsteps(n-1)+1;
}
int mx = 20000001;
int arr[20000001];
void bottomup(){
	arr[1]=0;
	for(int i=2;i<mx;i++){
		if(i%6==0){
			arr[i] = min(arr[i-1]+1,min(arr[i/2]+1,arr[i/3]+1 ));
		}
		else if(i%2==0){
			arr[i] = min(arr[i/2]+1, arr[i-1]+1);
		}
		else if(i%3==0){
			arr[i] = min(arr[i/3]+1, arr[i-1]+1);
		}
		else
			arr[i] = arr[i-1]+1;
	}
}
// int minsteps()

int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	bottomup();
	int t;
	get(t);
	rep(i,0,t){
		int n;
		get(n);
		pls("Case");put(i+1);put(": ");pln(arr[n]);
	}
}
