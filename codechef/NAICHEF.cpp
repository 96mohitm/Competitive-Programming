#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		double n,a,b;
		scanf("%lf%lf%lf",&n,&a,&b);
		// printf("%d,%d\n",n,a,b);
		int arr[(int)n],i;
		double ca=0,cb=0,pa,pb,r;
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
			if(arr[i]==a) ca++;
			if(arr[i]==b) cb++;
		}
		// ca = count(arr,arr+(int)n,a);
		// cb = count(arr,arr+(int)n,b);
		// printf("%lf,%lf\n",ca,cb );
		pa=ca/n;pb=cb/n;
		r=pb*pa;
		printf("%lf\n",r );
	}
} 
