#include <bits/stdc++.h>
#define ll long long int

using namespace std;
int main(void){
	//int t,h,i,n;
	double r,n,h,i;
	scanf("%lf%lf",&n,&h);
	for(i=1;i<n;i++){
		r=(double)sqrt((double)(i/n));
		r=(double)(h*r);
		printf("%lf ",r);
	}
	printf("\n");
}