#include <bits/stdc++.h>
#define ll long long int

using namespace std;
int main(void){
	ll a,b,c,x,r=0;
	int n;
	scanf("%lld%lld%lld",&a,&b,&c);
	scanf("%d",&n);
	while(n--){
		scanf("%lld",&x);
		if(x>b&&x<c)
			r++;
	}
	printf("%lld\n",r);
}