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

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 




int main(void){
	int t;
	scanf("%d",&t);
	vector<string> s(1000000,"");
	int i =1;
	// s[0] = "";
	int l=0;
	while(t--){
		int q;
		scanf("%d",&q);
		char x[1000000];
		if(q==1){
			scanf("%s",x);
			l+=strlen(x);
			s[i]=s[i-1];
			s[i].append(x);
			i++;
			// cout<<s[i-1]<<endl;
			// int j;
			// rep(j,0,i){
			// 	cout<<s[j]<<endl;
			// }

		}
		else if(q==2){
			int d;
			scanf("%d",&d);
			s[i]="";
			s[i].append(s[i-1],0,l-d);
			l=l-d;
			i++;
			// cout<<s[i-1]<<endl;

		}
		else if(q==3){
			int d;
			scanf("%d",&d);
			// char c[1000000] = s[i-1];
			printf("%c\n",s[i-1][d-1]);
			// cout<<s[i-1]<<endl;

		}
		else if(q==4){
			i--;
			s[i]="";
			l=s[i-1].length();
			// cout<<s[i-1]<<endl;
		}
	}
}
