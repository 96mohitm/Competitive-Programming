#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef unsigned long long int ul;

#define MOD 1000000007
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define vget(v) rep(i, 0, v.z) get(v[i]);
#define vsort(v) sort(v.begin(), v.end())
#define get(x) cin >> x
#define put(x) cout << x
#define pls(x) cout << x << ' '
#define pln(x) cout << x << "\n"
#define vget(v) rep(i, 0, v.z) get(v[i]);
#define rep(i, begin, end) \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define watch(x) cout << (#x) << " is " << (x) << endl
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int a[100005];
/*
sum is the total sum of the given segment.
total is the number of substrings.
*/
struct Tree{
	ll sum=0,prefix[3] = {0},sufix[3]={0},total=0;
};
Tree tr[400006];
void build(int n, int s, int e){
	if(s==e){
		tr[n].prefix[a[s]] = tr[n].sufix[a[s]] = 1;
		if(a[s]==0) tr[n].total =1;
		tr[n].sum = a[s];
		return;
	}
	int m = (s+e)>>1;
	build(2*n, s, m);
	build(2*n +1, m+1, e);
	tr[n].sum = (tr[2*n].sum + tr[2*n+1].sum)%3;
	int i,j;
	//for computing the prefix and sufix array of the node.
	rep(i,0,3){
		tr[n].prefix[i] += tr[2*n].prefix[i];
		tr[n].sufix[i] += tr[2*n +1].sufix[i];
		int x = (tr[2*n].sum + i)%3;
		tr[n].prefix[x] += tr[2*n + 1].prefix[i];
		x = (tr[2*n+1].sum +i)%3;
		tr[n].sufix[x] += tr[2*n].sufix[i];
	}
	//computing the total number of substrings divisible by 3.
	tr[n].total = tr[2*n].total + tr[2*n+1].total;//1
	rep(i,0,3){
		rep(j,0,3){
			if((i+j)%3==0){
				tr[n].total += tr[2*n].sufix[i]*tr[2*n+1].prefix[j];
			}
		}
	}
}
void update(int n, int s, int e, int p, int v){
	//nooverlap case
	if(s>e||s>p||e<p)
		return;
	if(s==e){
		rep(i,0,3){
			tr[n].prefix[i]=0;
			tr[n].sufix[i]=0;
		}
		tr[n].prefix[v] = tr[n].sufix[v] = 1;
		if(v==0) tr[n].total =1;
		else tr[n].total = 0;
		tr[n].sum = v;
		return;
	}
	int m = (s+e)>>1;
	update(2*n, s, m,p,v);
	update(2*n +1, m+1, e,p,v);
	tr[n].sum=0;
	tr[n].prefix[0]=tr[n].prefix[1]=tr[n].prefix[2] = 0;
	tr[n].sufix[0]=tr[n].sufix[1]=tr[n].sufix[2]=0;
	tr[n].total=0;
	tr[n].sum = (tr[2*n].sum + tr[2*n+1].sum)%3;
	int i,j;  
	//for computing the prefix and sufix array of the node.
	rep(i,0,3){
		tr[n].prefix[i] += tr[2*n].prefix[i];
		tr[n].sufix[i] += tr[2*n +1].sufix[i];
		int x = (tr[2*n].sum + i)%3;
		tr[n].prefix[x] += tr[2*n + 1].prefix[i];
		x = (tr[2*n+1].sum +i)%3;
		tr[n].sufix[x] += tr[2*n].sufix[i];
	}
	//computing the total number of substrings divisible by 3.
	tr[n].total = tr[2*n].total + tr[2*n+1].total;
	rep(i,0,3){
		rep(j,0,3){
			if((i+j)%3==0){
				tr[n].total += tr[2*n].sufix[i]*tr[2*n+1].prefix[j];
			}
		}
	}
}
Tree query(int n, int s, int e, int qs, int qe){
	Tree re;
	if(s>e||s>qe||e<qs){
		re.sum = re.total =0;
		rep(i,0,3){
			re.prefix[i] = re.sufix[i] =0;
		}
		return re;
	}
	if(s>=qs&&e<=qe){
		return tr[n];
	}
	int m = (s+e)>>1;
	Tree l = query(2*n,s,m,qs,qe);
	Tree r = query(2*n+1,m+1,e,qs,qe);
	re.sum = (l.sum + r.sum)%3;
	int i,j;  
	//for computing the prefix and sufix array of the node.
	rep(i,0,3){
		re.prefix[i] += l.prefix[i];
		re.sufix[i] += r.sufix[i];
		int x = (l.sum + i)%3;
		re.prefix[x] += r.prefix[i];
		x = (r.sum +i)%3;
		re.sufix[x] += l.sufix[i];
	}
	//computing the total number of substrings divisible by 3.
	re.total = l.total + r.total;
	rep(i,0,3){
		rep(j,0,3){
			if((i+j)%3==0){
				re.total += l.sufix[i]*r.prefix[j];
			}
		}
	}
	return re;
}
int main(void){
	fast();
	#ifndef ONLINE_JUDGE
	 freopen("input.txt", "r", stdin);
	 freopen("output.txt", "w", stdout);
	#endif
	int n,m,i;
	get(n);get(m);
	char c[n+1];
	get(c);
	rep(i,1,n+1){
		a[i] = c[i-1]-'0';
		a[i]%=3;
	}
	build(1,1,n);
	// rep(i,1,10){
	// 	pln(tr[i].total);
	// }
	// int q;
	// get(q);
	// watch(m);
	while(m--){
		int x,y,z;
		// watch(x);
		get(x);get(y);get(z);
		if(x==1){
			z %=3;
			update(1,1,n,y,z);
		}
		else if(x==2){
			Tree r = query(1,1,n,y,z);
			pln(r.total);
		}
	}
}
