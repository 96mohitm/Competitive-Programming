#include <bits/stdc++.h>
using namespace std;

int knapsack(int a[], int wt[], int n, int c){
	int dp[n+1][c+1];
	int i,j;
	for(i=0;i<=n;i++)
		dp[i][0]=0;
	for(i=0;i<=c;i++)
		dp[0][i]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=c;j++){
			if(j<wt[i]){
				dp[i][j]=dp[i-1][j];
			}
			else{
				dp[i][j] = max(a[i] + dp[i-1][j-wt[i]], dp[i-1][j]);
			}
		}
	}

	return dp[n][c];
}
int main(void){
	int n,c;
	scanf("%d%d",&c,&n);
	int a[n+1], wt[n+1];
	for(int i=1;i<=n;i++)
		scanf("%d%d",&wt[i],&a[i]);
	int r = knapsack(a, wt, n, c);
	printf("%d\n",r );
}