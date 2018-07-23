#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;


#define rep(i, a, b) \
for( i = int(a); i< int(b); i++)


int main(void){
	int r,i;
	char c[20];
	scanf("%s",c);
	int l = strlen(c);
	r=1;
	rep(i, 0, l){
		if(c[i]=='7'){
			r+=pow(2,l-i-1);
		}
	}
	rep(i,1,l) r+=pow(2,i);
	printf("%d\n",r);
}