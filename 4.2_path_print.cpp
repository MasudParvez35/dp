//Author: A_S_M_M@sud_P@rvez
#include <bits/stdc++.h>
using namespace std;
#define MP ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Forn(i,a,n) for (int i = a; i < n; i++)
#define Fors(i,s) for (int i = 0; i < s.size(); i++)
#define all(v) v.begin(), v.end()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / __gcd(a, b)))
#define vpprint(vp) {Fors(i,vp) {cout << vp[i].ff << " " << vp[i].ss << endl;}}
#define mpprint(mp) for (auto it : mp) {cout <<it.ff << " " << it.ss << endl;}
#define arprint(a,n) {for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;}
#define vprint(v) {for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;}
#define gt greater<int>()
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define endl "\n"
#define mod 1000000007
#define sp(n) fixed << setprecision(n)
#define Erase(s) s.erase(unique(s.begin(), s.end()), s.end())
int Ceil(int a, int b) {return a % b == 0 ? a / b : a / b + 1;}
#define yes cout << "Yes" << endl
#define no  cout << "No" << endl
#define int long long int
const int Mx = 2e5+35;
//%%%%%%%%%%%p%%%a%%%r%%%v%%%e%%%z%%%%%%%%%%//
vector <int> ar[Mx];
int vis[Mx], par[Mx];
void bfs(int n) {
    queue <int> q;
    q.push(n);
    vis[n] = 1;
    while(q.size()) {
        int node = q.front();
        q.pop();
        for (auto child : ar[node]) {
            if (!vis[child]) {
                vis[child] = 1;
                q.push(child);
                par[child] = node;
            }
        }
    }
}
void solve()
{
    vector <pair<int,int>> vp, pp;
    vector <int> v, v1, v2;
    map <int, int> mp, mm;
    string s = "", t = "";
    int n, m, sm = 0, c = 0, ans = 0, mx = 0, mi = 1e18;
    int a, b;
    cin >> n >> a >> b;
    Forn(i,1,n) {
        int u, v;
        cin >> u >> v;
        ar[u].pb(v);
        ar[v].pb(u);
    }
    bfs(a);
    int x = b;
    while(x != 0) {
        v.pb(x);
        x = par[x];
    }
    reverse(all(v));
    vprint(v);
}
signed main()
{
    //freopen("input.txt","r",stdin);
    MP;
    int T = 1;
    //cin >> T; for (int i = 1; i <= T; i++)
    solve();

    cerr<<endl<<(float)clock()/(float)CLOCKS_PER_SEC<<" sec"<<endl;
    return 0;
}
