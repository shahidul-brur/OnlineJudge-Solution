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
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
const int MX = 105;
int a[MX], dp[MX][3], n;
int cal(int idx, int prev)
{
    if(idx>n)
        return 0;
    if(dp[idx][prev]!=-1)
        return dp[idx][prev];
    int ret = 110;
    f(i, 0, 2)
    {
        if(i==0)
            ret = min(ret, 1+cal(idx+1, i));
        else if((a[idx]==3 || a[idx]==i) && prev!=i)
            ret = min(ret, cal(idx+1, i));
    }
    return dp[idx][prev] = ret;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin>>n){
    f(i, 1, n) cin>>a[i];
    mem(dp, -1);
    cout << cal(1, 0) << "\n";
    }
    return 0;
}

