/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
| Blog: shahidul-brur.blogspot.com  |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define vi       vector<int>
#define pii      pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define F(i, a, b)      for(int i=a;i<=b;i++)
#define rep(i, k)       for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define FORR(i, b, a)   for(int i=b;i>=a;i--)
#define FOR(i, a, b)    for(int i=a;i<=b;i++)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define ll              long long
#define ull             unsinged long long
#define mod             1000000007
#define N               1000005
#define inf             1e9
ll n, ans, k;
ll p(ll b)
{
    ll v = 1LL;
    
    rep(i, b)
    {
        v*=2;
    }
    return v;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    while(cin>>n>>k)
    {
        ans = -1*1LL;
        rep1(i, n)
        {
            ll a = p(i-1);
            ll d = a*2;
            if(k==a)
            {
                ans = i;
                break;
            }
            if((k-a)%d==0)
            {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

