#include <bits/stdc++.h>

using namespace std;

int main(void){
	int t,n,m,i,j,tm,x;
	cin>>t;
	int arr[200];
	for(i=0;i<200;i++){
			arr[i]=0;
		}
	while(t--){

		for(i=0;i<200;i++){
			arr[i]=0;
		}
		arr[0]=1;
		cin>>n;
		tm=0;
		x=0;
		if(n==1)
			cout<<1;
		else{
		m=1;
		for(i=1;i<=n;i++){
			for(j=0;j<m;j++){
				x=arr[j]*i+tm;
				arr[j]=x%10;
				tm=x/10;
			}
			while(tm>0){
				arr[m]=tm%10;
				m++;
				tm=tm/10;
			}
		}
		i=m-1;
		for(;i>=0;i--){
			cout<<arr[i];
		}
	}
		cout<<endl;
	}
}