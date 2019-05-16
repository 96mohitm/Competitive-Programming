#include <bits/stdc++.h>
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int dp[3000][3000];
int mindis(string a, string b, int n, int m){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0)
                dp[i][j] = j;

            else if(j==0)
                dp[i][j] = i;

            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];

            else{
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
            // cout<<dp[i][j]<<"\n";
        }
    }
    return dp[n][m];
}
void solve(){
    int t;
    cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b;
        // cout<<a<<b<<"\n";
        cout<<(mindis(a, b, a.length(), b.length()))<<"\n";
    }
}

int main(void){
    fast();
    #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif
    solve();
}