#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
#define mod 1000000007
#define ll long long int
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(void){
    fast();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        ll a,b,c,n;
        cin>>a>>b>>c>>n;
        priority_queue<ll> l,r;
        l.push(1);
        ll sum = 1;
        for(int i=2; i<=n; i++){
            ll x = (a*l.top() + 1L*b*i + c)%mod;
            sum += x;
            if(l.top() < x){
                r.push(-x);
            }
            else
                l.push(x);
            while(l.size() > r.size() + 1){
                r.push(-l.top());
                l.pop();
            }
            while(r.size() > l.size()){
                l.push(-r.top());
                r.pop();
            }
        }
        cout<<sum<<"\n";
    }
}