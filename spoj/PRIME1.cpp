#include <bits/stdc++.h>
using namespace std;

int main(void){
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		int r = ceil(sqrt(m));
		int arr[r+1] ;
		int sr = ceil(sqrt(r));
		// cout<<sr<<ensdl;
		for(int i=0;i<r+1;i++) arr[i] = 1;
		arr[0]=0;arr[1]=0;
		for(int i=2;i<=sr;i++){
			if(arr[i]==1){
				for(int j=2*i;j<r+1;j+=i)
					arr[j]=0;
			}
		}
		// cout<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<arr[4];
		// printf("%d",r);
		int s = m-n+1;
		int prime[s];
		for(int i=0;i<s;i++) prime[i]=1;
		for(int i=2;i<r+1;i++){
			 // printf("i=%d\n",arr[i );
			if(arr[i]==1){
				// printf("i=%d\n",i );
				int b = n/i;
				b=i*b;
				if(b<n) b+=i;
				if(b==i) b+=i;
				for(int j=b;j<=m;j+=i){
					// printf("j=%d\n",j );
					prime[j-n]=0;
					// printf("%d\n",(n-j) );
				}
			}
		}
		if(n==1) prime[0]=0;
		for(int i=0;i<s;i++){
			if(prime[i]==1)
				printf("%d\n",(i+n) );
		}
		printf("\n");
	}
}
