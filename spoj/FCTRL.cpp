#include <bits/stdc++.h>
using namespace std;
int main(void){
	int t;
	long long int n,i,m,sum;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		m=0;
		sum=0;
		for(i=1;;i++){
			m=n/pow(5,i);
			if(m==0)
				break;
			sum+=m;
		}
		printf("%lld\n",sum);
	}
}