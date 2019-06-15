/************************************************************
* Problem:  UVa 160 
* Link:                                                     
* Verdict:  Accepted 
* Date:     28/10/2015                                                
* 
* Coder:     Md. Shahidul Islam
* Dept. :    Computer Science and Engineering
* Institute: Begum Rokeya University, Rangpur, Bangladesh
*
*************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define mem(a, b) memset(a, (b), sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define rep(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define inf (1 << 28)
#define ll long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define AIN(A, B, C) assert(IN(A, B, C))
#define INF 1000000000
int dr[]={0, 0, 1, -1, 1, 1, -1, -1};
int dc[]={1, -1, 0, 0, 1, -1, 1, -1};

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

int divisor[103][103], prime[102], primality[102], p;
void genPrime(int n)
{
    int i, j;
    for(i=2;i<=n;i++)
        primality[i] = 1;
    primality[0]=primality[1]=0;
    
    for(i=4;i<=n;i+=2)
        primality[i] = 0;
    int r = sqrt(n);
    for(i=3;i<=r;i+=2)
    {
        if(primality[i]==1)
        {
            for(j=i*2;j<=n;j+=i)
                primality[j] = 0;
        }
    }
    p=0;
    for(i=2;i<=n;i++)
        if(primality[i]==1)
            prime[p++] = i;
}
void countDivisor(int n)
{
    int i, j, k;
    for(j=1;j<=n;j++)
        for(k=1;k<=n;k++)
            divisor[j][k] = 0;
    for(k=2;k<=n;k++)
    {
        j=k;
        if(primality[k]==1)
            divisor[k][k] = 1;
        else
        {
            for(i=0;i<p && j>=2;i++)
            {
                while(j%prime[i]==0)
                {
                    divisor[k][prime[i]]++;
                    if(primality[j/prime[i]]==1)
                    {
                        divisor[k][j/prime[i]]++;
                        j=1;
                        break;
                    }
                    else 
                    {
                        j/=prime[i];
                    }
                }
            }
        }
    }
}
int main()
{
    //fast;
    
    genPrime(100);
    countDivisor(100);
    //in;
    //out;
    
    int n, i, cnt, k, j;
    
    while(cin>>n)
    {
        if(n==0)
            break;
        printf("%3d! =", n);
        k=0;
        for(i=0;prime[i]<=n && i<p;i++)
        {
            cnt = 0;
            for(j=2;j<=n;j++)
                cnt+=divisor[j][prime[i]];
            if(k==15)
            {
                printf("\n      ");
                k=0;
            }
            printf("%3d", cnt);
            k++;
        }
        cout <<"\n";
    }
    
    return 0;
}