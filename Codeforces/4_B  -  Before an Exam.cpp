/************************************************************
* Problem:   
* Link:                                                     
* Verdict:   
* Date:                                                     
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

int main()
{
    //fast;
    //in;
    //out;
    int d, sum, l[32], h[32], i, les=0, high=0, day[32];
    cin>>d>>sum;
    for(i=0;i<d;i++)
    {
        cin>>l[i]>>h[i];
        les+=l[i];
        high+=h[i];
    }
    if(sum<les || sum>high)
        cout << "NO\n";
    else
    {
        for(i=0;i<d;i++)
        {
            day[i] = l[i];
            sum-=l[i];
        }
        for(i=0;sum>0 && i<d;i++)
        {
            if(sum+day[i]<=h[i])
            {
                day[i]+=sum;
                sum=0;
                break;
            }
            else
            {
                day[i] = h[i];
                sum -=(h[i] - l[i]);
            }
        }
        cout << "YES\n";
        cout << day[0];
        for(i=1;i<d;i++)
        {
            cout << " " << day[i];
        }
        cout << "\n";
    }
    return 0;
}