#include <iostream>
#include <cmath>
using namespace std;

int prime(int m, int n){
	int arr[1000000001],i,j;
	for(i=0;i<=n;n++){
		arr[i]=1;
	}
	i=0;
	arr[0]=0;arr[1]=0;
	for(;i<=sqrt(n);i++){
		if(arr[i]){
			for(j=0;j*i<=n;j++){
				arr[j*i]=0;
			}
		}
	}
	return arr[1000000001];


}

int main(){
	int t,m,n,i,j,arr[1000000001];
	cin >> t;
	for(i=0;i<t;i++){
		cin>>m>>n;
		arr[1000000001] = prime(m, n);
		for (j=n;j<=m;j++){
			if(arr[j]) cout<<j<<endl;
		}
	}
	return 0;
}