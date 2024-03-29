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
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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
vi d[5002], td[5002];
int n,m, dest[5002];
int dst(int a, int b){
    if(b<a) b+=n;;
    return b-a;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    f1(i,m){
        int s, t;
        cin>>s>>t;
        d[s].pb(t);
    }
    
    f1(i,n)if(d[i].size()>1){
        vii v;
        for(int x:d[i]){
            v.pb(mp(dst(i,x), x));
        }
        sort(all(v));
        d[i].clear();
        for(ii p:v) d[i].pb(p.ss);
    }
    f1(i,n){
        f1(j,n) {
            td[j] = d[j]; 
            dest[j] = 0;
        }
        int del = 0, cur = i;
        int tim = 0, book = 0;
        //cout << i;
        while(1){
            if(td[cur].size()>0){
                del++;
                book++;
                dest[td[cur].back()]++;
                //cout << "(" << td[cur].back() << "),";
                td[cur].pop_back();
            }
            book-=dest[cur];
            dest[cur] = 0;
            if(del==m && book==0){
                break;
            }
            tim++;
            cur++;
            if(cur>n) cur = 1;
            //cout << " -> "<< cur ;
        }
        //cout << " : ";
        cout << tim << " ";
    }
    return 0;
}