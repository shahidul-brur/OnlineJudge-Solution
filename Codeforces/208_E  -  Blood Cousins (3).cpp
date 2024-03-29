#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> pii;

const int MAX=1e5+17,lg=17;
int n,par[MAX][lg],dep[MAX],cnt[MAX],siz[MAX],ans[MAX];
vector<int>g[MAX];
vector<pii>queries[MAX];
void dfs_depth(int u)
{
    siz[u] = 1;
    for(auto v:g[u])
    {
        dep[v] = dep[u] + 1;
        par[v][0] = u;
        dfs_depth(v);
        siz[u] += siz[v];
    }
}
bool isBig[MAX];
void add(int v,int x=1)
{
    cnt[ dep[v] ] += x;
    for(auto u:g[v])
        if(!isBig[u])
            add(u,x);
}
void dfs_cal(int v, bool big)
{
    int mx=-1,bigChild = -1;
    for(auto u:g[v])
        if(mx<siz[u])
            bigChild = u, mx = siz[u];
    for(auto u:g[v])
        if(u != bigChild)
            dfs_cal(u, 0);
    if(bigChild != -1)
        isBig[bigChild]=1,dfs_cal(bigChild,1);
    add(v, +1);
    for(auto q:queries[v])
        ans[ q.ss ] = cnt[ q.ff ] - 1;
    if(bigChild != -1)
        isBig[bigChild] = 0;
    if(!big)
        add(v, -1);
}
main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1,p; i<=n; i++)
        cin>>p,g[p].pb(i);
    dfs_depth(0);
    for(int i=1; i<lg; i++)
        for(int v=1; v<=n; v++)
            par[v][i] = par[ par[v][i-1] ][i-1];
    int nq;
    cin>>nq;
    for(int v,h,idx=0; idx<nq; idx++)
    {
        cin>>v>>h;
        int d = dep[v];
        if(h<=dep[v]-1){
            for(int i=0; i<lg; i++)
                if(h & (1<<i))
                    v = par[v][i];
            queries[v].pb({d,idx});
            //cout << idx << " : " << v << " " << h+dep[v] << "\n";
        }
    }
    dfs_cal(0, 0);
    for(int i=0; i<nq; i++)
        cout << ans[i] <<' ';
    cout<<'\n';
    return 0;
}
