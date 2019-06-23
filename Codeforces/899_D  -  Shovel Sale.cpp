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

inline int getInt(){int x; scanf("%d", &x);return x;}
inline long getLong() {long x;scanf("%ld", &x);return x;}
inline ll getLLong() {ll x;scanf("%lld", &x);return x;}
inline float getFloat() {float x;scanf("%f", &x);return x;}
inline double getDouble() {double x;scanf("%lf", &x);return x;}
inline ii getPair() {ii p; scanf("%d %d", &p.ff, &p.ss);return p;}
void getCAra(char *x) {scanf("%s", x);}
string getString() {char ch[200005]; scanf("%s", &ch); string s = string(ch); return s;}

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

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)1e5+5;
const int LOGN = 20;

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll n;
    cin>>n;
    ll nine = 0;
    ll ten = 10;
    ll need;
    f1(i,11)
    {
        need = ten/2;
        if(n>=need)
            nine = i;
        else 
        {
            ten/=10;
            need = ten/2;
            break;
        }
        ten*=10;
    }
    if(nine==0)
    {
        cout << (n-1)*n/2;
        return 0;
    }
    ll val = ten-1, ans = 0;
    while(1)
    {
        need = (val+1)/2;
        if(n<need) break;
        //cout << val << " " << need << " => " << min(n, val-1)-need+1 << "\n";
        ans+=min(n, val-1)-need+1;
        val+=ten;
    }
    cout << ans;
    return 0;
}

