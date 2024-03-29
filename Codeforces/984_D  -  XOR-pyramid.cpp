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
const int maxn = (int)5e3+2;
const int LOGN = 20;
int dp[maxn][maxn],a[maxn], fn[maxn][maxn];
int cal(int l, int r)
{
    if(l==r) return dp[l][r] = a[l];
    if(l>r) return 0;
    int &ret = dp[l][r];
    if(ret!=-1) return ret;
    ret = fn[l][r];
    ret = max(ret, cal(l,r-1));
    ret = max(ret, cal(l+1,r));
    return ret;
}
int cal_fn(int l, int r)
{
    if(l==r) return fn[l][r] = a[l];
    int &ret = fn[l][r];
    if(ret!=-1) return ret;
    ret = cal_fn(l,r-1) ^ cal_fn(l+1,r);
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    f1(i,n) cin>>a[i];
    mem(fn,-1);
    cal_fn(1,n);
    mem(dp,-1);
    cal(1,n);
    int q, l, r;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout << dp[l][r] << "\n";
    }
    return 0;
}
