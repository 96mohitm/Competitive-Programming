#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		ll a,b;
		int r =1,ca=0,cb=0;
		scanf("%lld%lld",&a,&b);
		ll ta=a,tb=b;
		int d;
		b--;
		while(a){
			d=a%2;
			a=a/2;
			ca+=d;
		}
		while(b){
			d=b%2;
			b=b/2;
			cb+=d;
		}
		if(tb<ta&&(tb==1||tb==0)){
			r=-1;
		}
		else if(ta==tb) r=0;
		else if(ta+1==tb) r=1;
		else if(ca<cb){
			// int d;
			r=cb-ca+1;
		}
		else if(ca==cb) r=1;
		else r=2;
		// printf("%d %d\n",ca,cb );
		printf("%d\n",r );
	}
}
