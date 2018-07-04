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
// #define tr(container, it) \
//     for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 

int main(void){
	int t,i,q,n,l,li,j;
	// scanf("%d",&t);
	cin>>t;
	while(t--){
		cin>>n;
		string s[n],q;
		rep(i,0,n) cin>>s[i];
		cin>>q;
		l=q.length();
		vi v;
		int r;
		while(l){
			r=0;
			rep(i,0,n){
				li=s[i].length();
				if(li<=l){
					rep(j,0,li){
						if(s[i][j]!=q[j])
							break;
					}
					if(j==li){
						r=1;
						l=l-li;
						q=q.substr(li,l);
						v.push_back(i);
						break;
					}
				}
			}
			if(i==n&&r==0)
				break;
		}
		if(l==0){
			tr(v,it) cout<<s[*it]<<" ";
			cout<<"\n";
		}
		else
			cout<<"WRONG PASSWORD\n";
	}
}