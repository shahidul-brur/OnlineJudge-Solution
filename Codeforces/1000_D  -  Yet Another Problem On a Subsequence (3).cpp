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
using namespace std;

typedef long long ll;
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
const int MOD = 998244353;
const int maxn = 1002;
ll ncr[maxn][maxn], b[maxn];
int a[maxn];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin>>n;
    f1(i,n) cin>>a[i];
    ncr[0][0] = 1;
    f1(i,n)
    {
        ncr[i][0] = ncr[i][i] = 1;
        f1(j,i-1)
            ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % MOD;
    }
    b[n+1] = 1; // dummy, for single sequence
    ll ans = 0;
    fr(i,n-1,1)
    {
        if(a[i]<=0) continue;
        f2(j,i+a[i],n)
            b[i] = (b[i] + b[j+1]*ncr[j-i][a[i]]%MOD)%MOD;
        ans = (ans + b[i])%MOD;
    }
    cout << ans;
    return 0;
}
