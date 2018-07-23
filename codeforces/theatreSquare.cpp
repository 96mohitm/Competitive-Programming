#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(void){
	ll n,m,a;
	scanf("%lld%lld%lld",&n,&m,&a);
	n=ceil((double)n/a);
	m=ceil((double)m/a);
	ll r;
	r=n*m;
	printf("%lld\n",r );
}