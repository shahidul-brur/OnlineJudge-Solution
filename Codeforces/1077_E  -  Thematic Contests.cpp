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
int n,a[maxn],cnt[maxn],mx,id;
int ca[maxn];
int ocr[maxn];
vii freq;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin>>n;
    f1(i,n) cin>>a[i];
    sort(a+1, a+n+1);
    id = 1;
    f1(i,n)
    {
        if(i>1 && a[i]>a[i-1])
            ++id;
        cnt[id]++;
        ca[i] = id;
    }
    f1(i,id){
        //cout << i << ": " << cnt[i] << "\n";
        freq.pb(mp(cnt[i],i));
    }
    sort(all(freq));
    f1(i,id) ocr[i] = freq[i-1].first;
//    cout << id << " #\n";
//    f1(i,id) cout << ocr[i] << ", ";
    int ans = 0, st = 0;
    f1(i,ocr[id])
    {
        int cur = i;
        int idx = lower_bound(ocr+1, ocr+id+1, i) - ocr;
        int need = 2*i;
        while(1)
        {
            if(idx==id || ocr[id]<need) break;
            cur+=need;
            idx = lower_bound(ocr+idx+1, ocr+id+1, need) - ocr;
            need*=2;
        }
        if(cur>ans){
            ans = cur;
            st = i;
        }
    }
    //cout << st << " ";
    cout << ans;
    return 0;
}


