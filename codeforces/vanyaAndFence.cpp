#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n,h;
	scanf("%d%d",&n,&h);
	int arr[n],i,j=0;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(arr[i]>h)
			j=j+2;
		else
			j++;
	}
	printf("%d\n",j );
}