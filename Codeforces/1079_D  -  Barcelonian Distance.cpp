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
double dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int a,b,c;
    double ax,ay,bx,by;
    cin>>a>>b>>c;
    cin>>ax>>ay;
    cin>>bx>>by;
    double ans = abs(ax-bx) + abs(ay-by);
    int a1=0,a2=0,b1=0,b2=0;
    double ap1x,ap1y,ap2x,ap2y,bp1x,bp1y,bp2x,bp2y;
    if(a!=0){
        //cerr << " a)\n";
        a1 = 1;
        b1 = 1;
        ap1y = ay;
        ap1x = (-c-b*ay)/(a*1.0);
        
        bp1y = by;
        bp1x = (-c-b*by)/(a*1.0);
//        cout << ap1x << ", " << ap1y << "\n";
//        cout << bp1x << ", " << bp1y << "\n";
    }
    if(b!=0)
    {
//        cerr << " b)\n";
        a2 = 1;
        b2 = 1;
        ap2x = ax;
        ap2y = (-c-a*ax)/(b*1.0);
        
        bp2x = bx;
        bp2y = (-c-a*bx)/(b*1.0);
//        cout << ap2x << ", " << ap2y << "\n";
//        cout << bp2x << ", " << bp2y << "\n";
    }
    double d;
    if(a1==1 && b1==1){
//        cerr << "1\n";
        d = dis(ax, ay, ap1x,ap1y) + dis(bx, by, bp1x, bp1y) + dis(ap1x,ap1y, bp1x, bp1y);
        ans = min(ans, d);
    }
    if(a1==1 && b2==1){
//        cerr << "2\n";
        d = dis(ax,ay,ap1x,ap1y) + dis(bx,by,bp2x,bp2y) + dis(ap1x,ap1y, bp2x, bp2y);
        ans = min(ans, d);
    }
    
    //
    if(a2==1 && b1==1){
//        cerr << "3\n";
        d = dis(ax, ay, ap2x,ap2y) + dis(bx, by, bp1x, bp1y) + dis(ap2x,ap2y, bp1x, bp1y);
        ans = min(ans, d);
    }
    if(a2==1 && b2==1){
//        cerr << "4\n";
        d = dis(ax,ay,ap2x,ap2y) + dis(bx,by,bp2x,bp2y) + dis(ap2x,ap2y, bp2x, bp2y);
        ans = min(ans, d);
    }
    cout << fixed << setprecision(15) << ans;
    return 0;
}
