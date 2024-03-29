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
ll dp[maxn][3];
int n, l, r;
ll cnt_rem(int rem){
    if(l==r){
        return l%3==rem;
    }
    if(l+1==r){
        return (l%3==rem || (l+1)%3==rem);
    }
    if(l+2==r){
        return 1;
    }
    ll d = r/3 - (l-1)/3;
    if(rem==0)
        return d;
    if(rem==1){
        if(l%3!=1)
            --d;
        if(r%3==1 || (r-1)%3==1)
            ++d;
        return d;
    }
    else if(rem==2){
        if(l%3==0)
            --d;
        if(r%3==2)
            ++d;
        return d;
    }
}
ll cal(int pos, int rem){
    if(pos==n) {
        return rem==0;
    }
    ll &ret = dp[pos][rem];
    if(ret!=-1) return ret;
    ret = 0LL;
    f0(i,3){
        ll d = cnt_rem(i);
        ll now = (d * cal(pos+1, (rem+i)%3))%MOD;
        ret = (ret+now)%MOD;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>l>>r;
    mem(dp, -1);
    ll ans = cal(0,0);
    cout << ans;
    return 0;
}
