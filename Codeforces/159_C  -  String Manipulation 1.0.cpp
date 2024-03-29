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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;
ordered_set pos[28];
bool del[maxn];
int bit[28][maxn],ln;
void upd(int t, int pos)
{
    while(pos<=ln){
        bit[t][pos]++;
        pos+=pos&-pos;
    }
}
int qur(int t, int pos)
{
    int ret = 0;
    while(pos>0){
        ret+=bit[t][pos];
        pos-=pos&-pos;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int k;
    string tm, s;
    cin>>k>>tm;
    f0(i,k)
        s+=tm;
    ln = s.length();
    f0(i,ln)
        pos[s[i] - 'a'].insert(i);
    int n;
    cin>>n;
    while(n--)
    {
        int p;
        string ch;
        cin>>p>>ch;
        int t = ch[0]-'a';
        --p;
        int val = *pos[t].find_by_order(p);
        pos[t].erase(val);
//        del[pos[t][p-1]] = 1;
//        upd(t,p);
    }
    set<int> rem;
    f0(i,26)
        for(int v:pos[i])
            rem.insert(v);
    for(int i:rem)
        cout << s[i];
    return 0;
}