#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
 
 
#define rep(i, a, b) \
for( i = int(a); i< int(b); i++)
#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
 
 
 
int main(void){
	int t,n,i,k;
	ll r;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		char a[n+1];
		scanf("%s",a);
		ll w[n];
		rep(i,0,n-1){
			if(a[i]!=a[i+1])
				w[i]=1;
			else
				w[i]=0;
			// printf("%d",w[i] );
		}
		rep(i,1,n){
			w[i]+=w[i-1];
		}
		r=w[k-1];
		rep(i,k,n-1){
			r=r+(w[i]-w[i-k]);
		}
		printf("%lld\n",r );
	}
}
