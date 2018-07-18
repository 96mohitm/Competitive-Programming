#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

#define rep(i, a, b) \
for( i = ll(a); i< int(b); i++)
 
typedef vector<ll> vl; 
// typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define watch(x) cout << (#x) << " is " << (x) << endl

int main(void){
	int n,t,i,j;
	scanf("%d",&n);
	vl a(n+1,0);
	rep(i,1,n+1){
		a[i]=a[i-1];
		t= sqrt(i);
		// watch(t);
		rep(j,1,t+1){
			if(i%j==0) a[i]++;
		}
	}
	// rep(i,0,n+1)
	printf("%lld\n",a[n] );
}