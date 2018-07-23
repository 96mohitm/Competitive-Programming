#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) \
for(i = int(a); i< int(b); i++)

int main(void){
	char c[30];
	int i;
	scanf("%s",c);
	// printf("%s\n",c);
	int l = strlen(c);
	i=0;
	if(c[i]=='9') i++;

	rep(i,i,l) {
		int x =c[i]-'0';
		// printf("%d",x);
		if(9-x<x){
			x=9-x;
			c[i] = x+'0';
		}
	}
	printf("%s",c);
}