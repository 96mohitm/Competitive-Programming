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
	int a[n];
	if(n<3){
		rep(i,1,n+1)
			pls(i);
		pln("");
		rep(i,1,n+1)
			pls(i);
	}
	else{
		int s[n],m[n];
		s[0]=n;
		//smaller array
		rep(i,1,n){
			s[i]=i;
		}
		//for larger array
		if(n&1){
			rep(i,0,n)	m[i]=1+i;
			int i=0,j=n/2;
			j--;
			while(i<j){
				swap(m[i],m[i+1]);
				i++;
			}
			j=(n/2)+2;//3
			i = (n/2);//2
			while(i<n-1)
				m[i++]=j++;
			m[n-1] = (n/2)+1;
		}
		else{// n is even.
			rep(i,0,n)	m[i]=1+i;
			int i=0,j=n/2;
			j--;
			while(i<j){
				swap(m[i],m[i+1]);
				i++;
			}
			j=n-1;
			i=n/2;
			while(i<j){
				swap(m[i], m[i+1]);
				i++;
			}
		}
		rep(i,0,n) pls(m[i]);
		pln("");
		rep(i,0,n) pls(s[i]);
	}
}
