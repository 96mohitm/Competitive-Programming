#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

typedef unsigned long long int ul;

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define vget(v) rep(i, 0, v.z) get(v[i]);
#define vsort(v) sort(v.begin(), v.end())
#define get(x) cin >> x
#define put(x) cout << x
#define pls(x) cout << x << ' '
#define pln(x) cout << x << "\n"
#define vget(v) rep(i, 0, v.z) get(v[i]);
#define rep(i, begin, end)                              \
    for (__typeof(end) i = (begin) - ((begin) > (end)); \
         i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define watch(x) cout << (#x) << " is " << (x) << endl

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
struct point
{
    int left, right, block, ind;
};

bool cmp(const point &l, const point &r)
{
    if (l.block < r.block)
        return 1;
    else if (l.block > r.block)
        return 0;
    else
        return l.right < r.right;
}

void solve()
{
    int n;
    get(n);
    vector<int> v(n);
    rep(i, 0, n)
        get(v[i]);
    int q;
    get(q);
    vector<point> qu(q);
    int block_size = sqrt(n);
    rep(i, 0, q)
    {
        get(qu[i].left);
        get(qu[i].right);
        qu[i].left--;
        qu[i].right--;
        qu[i].block = qu[i].left / block_size;
        qu[i].ind = i;
    }
    sort(qu.begin(), qu.end(), cmp);

    int left = 0, right = 0, answer = 1;
    vector<int> solution(q), h(1000001);
    h[v[0]] = 1;

    for (const point &p : qu)
    {
        while (left < p.left)
        {
            h[v[left]]--;
            // subtract.
            if (h[v[left]] == 0)
                --answer;
            ++left;
        }
        while (left > p.left)
        {
            // first decrementing left as left is not included.
            --left;
            h[v[left]]++;
            // add
            if (h[v[left]] == 1)
                ++answer;
        }
        while (right < p.right)
        {
            right++;
            h[v[right]]++;
            // add
            if (h[v[right]] == 1)
                answer++;
        }
        while (right > p.right)
        {
            h[v[right]]--;
            // subtract.
            if (h[v[right]] == 0)
                answer--;
            right--;
        }
        solution[p.ind] = answer;
    }
    for (int a : solution)
        pln(a);
}

int main(void)
{
    fast();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
}
