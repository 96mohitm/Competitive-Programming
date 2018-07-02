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
#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 


int main(void){
	int t,n,i,j;
	scanf("%d",&n);
	while(n){
		int a[n];
		rep(i,0,n) scanf("%d",&a[i]);
		stack<int> s;
		j=1;
		rep(i,0,n){
			if(a[i]==j) j++;
			else{
				s.push(a[i]);
			}
			while(s.empty()==0&&s.top()==j){
				j++;
				s.pop();
			}
		}
		while(s.empty()!=1){
			if(s.top()==j){
				s.pop();
				j++;
			}
			else{
				break;
			}
		}
		if(s.empty())	printf("yes\n");
		else printf("no\n");
		scanf("%d",&n);
	}
}
