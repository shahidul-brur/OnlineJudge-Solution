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
const int maxn = (int)2e5+5;
const int LOGN = 20;
vi blankB, B;
vi blankW, W;
int p[105];
int p2[105];
int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    cin>>n;
    f1(i,n/2)
    {
        int x;
        cin>>x;
        p[x] = 1;
        p2[x] = 1;
    }
    int cnt = 0; // even->odd
    for(int i = 2;i<=n;i+=2)
    {
        if(p[i]==0) continue;
        int put = 0;
        for(int j = 1;j<i;j+=2)
        {
            if(p[j]==0)
            {
                p[j] = 1;
                cnt+=abs(i-j);
                put = 1;
                break;
            }
        }
        if(put==1) continue;
        for(int j = i+1;j<=n;j+=2)
        {
            if(p[j]==0)
            {
                p[j] = 1;
                cnt+=abs(i-j);
                put = 1;
                break;
            }
        }
    }
    int ans = cnt;
    
    cnt = 0; // odd->even
    for(int i = 1;i<=n;i+=2)
    {
        if(p2[i]==0) continue;
        int put = 0;
        for(int j = 2;j<i;j+=2)
        {
            if(p2[j]==0)
            {
                p2[j] = 1;
                cnt+=abs(i-j);
                put = 1;
                break;
            }
        }
        if(put==1) continue;
        for(int j = i+1;j<=n;j+=2)
        {
            if(p2[j]==0)
            {
                p2[j] = 1;
                cnt+=abs(i-j);
                put = 1;
                break;
            }
        }
    }
    ans = min(ans, cnt);
    cout << ans << "\n";
    return 0;
}