/*==============================================*\
ID:          shahidul_brur

Name:     Md. Shahidul Islam
Study:      CSE, BRUR
Address:  Rangpur, Bangladesh

 mail: shahidul.cse.brur@gmail.com
 FB  : fb.com/shahidul.brur
 Blog: shahidul-brur.blogspot.com(in Bengali),
       shahidul-brur-en.blogspot.com(in English)
\*===============================================*/
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define all(a)  a.begin(), a.end()
#define mem(a, b)     memset(a, b, sizeof(a))
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;
vi g[maxn];
int n, m, root;
vii ans;
bool vis[maxn], took[maxn];
void dfs(int u)
{
    vis[u] = 1;
    //cout << u << ":\n======\n";
    for(int v:g[u]){
        if(vis[v]==0 && took[v]==0){
            ans.pb(mp(u,v));
            took[v] = 1;
            //cout << "took " << v << "\n";
            //cout << u << " -> " << v << "\n";
        }
    }
    for(int v:g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    f1(i,m)
    {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    //int ext = m - (n-1);
    int mx = 0;
    root=1;
    f1(i,n)
    {
        int d = g[i].size();
        if(d>mx){
            mx = d;
            root = i;
        }
    }
//    for(int v:g[root]){
//        ans.pb(mp(root, v));
//    }
    dfs(root);
    for(ii e:ans){
        cout << e.ff << " " << e.ss << "\n";
    }
    return 0;
}
