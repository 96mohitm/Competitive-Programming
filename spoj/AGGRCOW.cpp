#include <bits/stdc++.h>
using namespace std;
//validating function
int func(int num, int a[], int n, int c){
	int cow=1;
	int pos= a[0];
	for(int i=1;i<n;i++){
		if(a[i]-pos>=num){
			cow++;
			if(cow==c)
				return 1;
			pos=a[i];
		}
	}
	return 0;
}

int main(void){
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	int t;
	scanf("%d",&t);
	while(t--){
		int n,c;
		scanf("%d%d",&n,&c);
		int a[n];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int s=0, l=a[n-1],mx=-1;
		while(l>s){
			int mid=(s+l)/2;
			if(func(mid,a,n,c)){
				if(mid>mx)
					mx= mid;
				s=mid+1;
			}
			else
				l=mid;
		}
		printf("%d\n",mx );
	}
}