#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[n];
		for(int i =0;i<n;i++)
			scanf("%d",&a[i]);
		int i=0,j;
		ll r=n;
		while(i<n-1){
			for(j=i;j<n-1;j++){
				if(a[j]<=a[j+1]){
					r+=(ll)(j-i+1);
				}
				else
					break;
			}
			i=j+1;
		}
		printf("%lld\n",r );
	}
}
*/

// Now dp solution.
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[n];
		ll b[n], r=0;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		b[0]=1;
		for(int i=1;i<n;i++){
			if(a[i-1]<=a[i])
				b[i]=b[i-1]+1l;
			else
				b[i]=1;
		}
		for(int i=0;i<n;i++){
			r+=b[i];
		}
		printf("%lld\n",r);
	}
}