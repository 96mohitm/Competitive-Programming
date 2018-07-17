#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define vvi vector<vi >
#define rep(i, a, b) \
for( i = int(a); i< int(b); i++)
#define MOD 1000000000

ll k,i,j,l;
vvi multiply(vvi x, vvi y){
	vvi r(k, vi(k,0));
	rep(i,0,k){
		rep(j,0,k){
			rep(l,0,k){
				r[i][j]=(r[i][j]+(x[i][l]*y[l][j])%MOD)%MOD;
			}
		}
	}
	return r;
}

vvi pow(vvi m, ll n){
	if(n==1) return m;
	if(n&1){
		return multiply(m, pow(m,n-1));
	}
	else{
		vvi x = pow(m, n/2);
		return multiply(x,x);
	}
}

int main(void){
	ll t,n;
	ll r;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&k);
		vi b(k), c(k);
		rep(i,0,k) scanf("%lld",&b[i]);
		rep(i,0,k) scanf("%lld",&c[i]);
		scanf("%lld",&n);
		if(n==0) r=0;
		else if(n<=k) r=b[n-1];
		else{
			//make T matrix
			//compute T^n-1
			//(T^n-1)*F thats.
			vvi tp(k, vi(k,0));
			rep(i,0,k-1){
				tp[i][i+1]=1;
			}
			rep(i,0,k){
				tp[k-1][i]=c[k-i-1];
			}
			tp = pow(tp, n-1);
			// rep(i,0,k){
			// 	rep(j,0,k) printf("%lld ",tp[i][j] );
			// 	printf("\n");
			// }
			r=0;
			rep(i,0,k){
				r=(r+(tp[0][i]*b[i])%MOD)%MOD;
			}
		}
		// r%=MOD;
		printf("%lld\n",r );
	}
}

