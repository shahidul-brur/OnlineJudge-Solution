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
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
*/
using namespace std;

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

inline int Int(){int x; scanf("%d", &x);return x;}
inline long Long() {long x;scanf("%ld", &x);return x;}
inline ll LLong() {ll x;scanf("%lld", &x);return x;}
inline float Float() {float x;scanf("%f", &x);return x;}
inline float Double() {double x;scanf("%lf", &x);return x;}
inline ii Pair() {ii p; scanf("d %d", &p.ff, &p.ss);return p;}
void S(char *x) {scanf("%s", x);}

void pI(int x) {printf("%d", x);}
void pL(long x) {printf("%ld", x);}
void pLL(ll x) {printf("%lld", x);}
void pUL(ull x) {printf("%llu", x);}
void pF(float x) {printf("%f", x);}
void pD(double x) {printf("%f", x);}
void pS(char x[]) {printf("%s", x);}
#define pCas printf("Case %d:",cas)
#define NL printf("\n")
#define SP printf(" ")

#define I Int()
#define L Long()
#define LL LLong()
#define F Float()
#define D Double()
#define P Pair()

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)5e5+5;
const int LOGN = 20;
int ara[maxn];
int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t=I;
    while(t--)
    {
        int n = I, x = I;
        int len = n+5;
        f1(i,n) 
        {
            ara[i]=I;
            if(ara[i]>=x) 
                len = 1;
        }
        if(len==1)
        {
            pI(len);NL;
            continue;
        }
        ll s = 0LL;
        int b = 0;
        f1(i,n)
        {
            cout << i << " : " << ara[i] << " => " << s << " - > ";
            if(s==0 && ara[i]<=0 && ara[i] < x)
            {
                s = 0LL;
                cout << "0\n";
                continue;
                
                
            }
            if(s==0 || ara[i]>=s+ara[i])
            {
                b = i;
                s = ara[i];
            }
            else 
                s+=ara[i];
            if(s<0 && s<x) 
                s = 0LL;
            while(b<i && s-ara[b]>=x )
            {
                //cout << " \n\t[ " << s  << " - " << s-ara[b] << " .. ok]";
                s-=ara[b];
                ++b;
            }
            cout << s << " ( ";
            if(s>=x)
            {
                len = min(len, i-b+1);
            }
            cout << b << " -- " << len << ")\n";
        }
        if(len==n+5)
            puts("-1");
        else 
        {
            pI(len);NL;
        }
    }
    return 0;
}
