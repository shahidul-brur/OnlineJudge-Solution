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
int s[maxn], h[maxn], par[maxn], a[maxn];
int ok;
void dfs(int u)
{
    int p = par[u];
    h[u] = h[p]+1;
    if(s[u]==-1)
    {
        int mn = -2;
        s[u] = s[p];
        for(int v:g[u])
        {
            if(mn==-2 || s[v]<mn)
                mn = s[v];
        }
        if(mn!=-2){
            //if(mn<s[p]) ok=0;
            //int can = mn - s[p];
            s[u] = s[p] + mn - s[p];
        }
    }
    a[u] = s[u] - s[p];
    for(int v:g[u])
        dfs(v);
    //cout << u << ": " << s[u] << ", " << a[u] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    par[1] = 0;
    f1(i,n-1)
    {
        int p;cin>>p;
        par[i+1] = p;
        g[p].pb(i+1);
    }
    ok=1;
    f1(i,n) {
        cin>>s[i];
        if(s[i]!=-1 && s[i]<s[par[par[i]]]) ok = 0;
    }
    if(ok==0){
        cout << "-1";
        return 0;
    }
    a[1] = s[1];
    dfs(1);
    ll tot = 0LL;
    f1(i,n) {
        if(s[i]<s[par[i]]) ok=0;
        tot+=a[i];
       // cout << i << ": " << s[i] << ", " << a[i] << "\n";
    }
     if(!ok) cout << "-1";
     else 
        cout << tot;
    return 0;
}
