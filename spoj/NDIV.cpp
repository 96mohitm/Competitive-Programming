#include <bits/stdc++.h>
using namespace std;
int check[32000];
int prime[10000];
void seive(){
	for(int i=0;i<32000;i++)
		check[i]=1;
	for(int i=3;i<180;i+=2){
		if(check[i])
			for(int j=i*i;j<32000;j+=i)
				check[j]=0;
	}
	// for(int i=0;i<20;i++)
	// 	printf("%d\n",check[i]);
	prime[0]=2;
	int j=1;
	for(int i=3;i<32000;i+=2){
		if(check[i])
			prime[j++]=i;
	}
	// for(int i=0;i<100;i++)
	// 	printf("%d\n",prime[i]);
}
int main(void){
	seive();
	int a,b,n,count,r=0,j;
	scanf("%d %d %d",&a,&b,&n);
	for(int i=a;i<=b;i++){
		int temp=i;
		int k=0;
		int total=1;
		for(j=prime[k];j*j<=temp;j=prime[++k]){
			count=0;
			// temp=i;
			while(temp%j==0){
				count++;
				temp=temp/j;
			}
			total=total*(count+1);
			
		}
		if(temp!=1){
			//printf("ti=%d\n",i);
		    total*=2;
		}
		if(total==n){
			//printf("i=%d\n",i);
			r++;
		}
	}
	printf("%d\n",r);
}