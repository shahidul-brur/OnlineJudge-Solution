/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define ull      unsinged long long
#define vi       vector<int>
#define vll      vector<ll>
#define ii       pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<int, int>
#define mli       map<ll, int>
#define msi       map<string, int>

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
#define mod             1000000007
#define N               10005
#define inf             1e9
ll nCr[35][35];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    nCr[1][0] = nCr[1][1] = 1LL;
    for(int i = 2;i<=30;i++)
    {
        nCr[i][0] = nCr[i][i] = 1LL;
        for(int j = 1;j<i;j++)
            nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
    }
    int t, n, k;
    cin>>t;
    rep1(cas, t)
    {
        cin>>n>>k;
        cout << "Case " << cas << ": ";
        if(k>n)
        {
            cout << "0\n";
        }
        else 
        {
            ll ans = nCr[n][k];
            //cout << ans << "\n";
            for(int i = 0;i<k;i++)
            {
                ans*=(n-i);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

