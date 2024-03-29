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
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const ll MOD = 998244353;
ll a[505];
map<ll, ll> cnt;
long long my_sqrt(long long x)
{
    long long y = (long long) (sqrtl((long double) x) + 0.5);
    while (y * y < x) y++;
    while (y * y > x) y--;
    if (y * y == x) return y;
    return -1;
}

long long my_crt(long long x)
{
    long long y = (long long) (powl((long double) x, 1.0 / 3.0) + 0.5);
    while (y * y * y < x) y++;
    while (y * y * y > x) y--;
    if (y * y * y == x) return y;
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    f1(i,n)
    {
        cin>>a[i];
    }
    sort(a+1, a+1+n);
    set<ll> div;
    ll ans = 1;
    f1(i,n)
    {
        ll x = a[i];
        ll r = my_sqrt(x);
        ll rr =  -1;
        if(r>0) rr = my_sqrt(r);
        ll r3 = my_crt(x);
        if(rr>0)
        {
            cnt[rr]+=4;
            div.insert(rr);
            x = 1;
        }
        else if(r>0)
        {
            cnt[r]+=2;
            div.insert(r);
            x = 1;
        }
        else if(r3>0)
        {
            cnt[r3]+=3;
            x = 1;
            div.insert(r3);
        }
        else
        {
            f1(j,n)
            {
                ll y = a[j];
                if(y==x) continue;
                ll g = __gcd(x,y);
                if(g>1)
                {
                    ll d2 = x/g;
                    div.insert(g);
                    div.insert(d2);
                    cnt[g]++;
                    cnt[d2]++;
                    x = 1;
                    break;
                }
            }
        }
        if(x>1)
        {
            int c = 1;
            while(i+1<=n && a[i+1]==a[i])
            {
                c++;
                i++;
            }
            ans = (ans*(c+1)*(c+1))%MOD;
        }
    }
    for(ll d:div)
        ans = (ans * (cnt[d]+1))%MOD;
    cout<< ans;
    fflush(stdout);
    return 0;
}
