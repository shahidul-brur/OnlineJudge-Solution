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
inline double Double() {double x;scanf("%lf", &x);return x;}
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
const int maxn = (int)3e5+5;
const int LOGN = 20;
ll l[maxn+2], r[maxn+2];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, mx = 0;
    cin>>n;
    f0(i, n)
    {
        string s;
        cin>>s;
        int ln = s.length();
        mx = max(ln, mx);
        stack<char> stk;
        f0(j, ln)
        {
            char ch = s[j];
            if(stk.empty()) stk.push(ch);
            else if(ch == '(')
            {
                stk.push(ch);
            }
            else if(ch == ')')
            {
                if(stk.top()== '(')
                {
                    stk.pop();
                }
                else stk.push(ch);
            }
        }
        int si = stk.size();
        if(si==0)
        {
           // cout << "0 ..\n";
            l[0]++, r[0]++;
            continue;
        }
        char c1 = stk.top(); stk.pop();
        bool inval = 0;
        while(!stk.empty())
        {
            char c2 = stk.top(); stk.pop();
            if(c1!=c2)
                inval = 1;
        }
        if(inval) continue;
        if(c1 == '(')
        {
            l[si]++;
            //cout << "L ..\n";
        }
        else 
        {
            r[si]++;
            //cout << "R ..\n";
        }
    }
    ll ans = 0LL;
    f0(i, mx+1)
    {
        //cout << i << " : " << l[i] << " " << r[i] << "\n";
        ans+=1LL*l[i]*r[i];
    }
    cout << ans;
    return 0;
}

