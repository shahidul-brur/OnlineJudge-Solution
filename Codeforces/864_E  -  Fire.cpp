/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define ull      unsinged long long
#define vi       vector<int>
#define vll      vector<ll>
#define ii       pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<int, int>
#define mli       map<ll, int>
#define msi       map<string, int>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
//             0123456789
const int MX = 100000;
struct info{
    int last, price, time, id;
}item[105];
int dp[105][2005], n;
ii nex[105][2005];
bool select[105][2005];
vi ans;
int cal(int pos, int time)
{
    if(pos>n)
        return 0;
    int &ret = dp[pos][time];
    if(ret!=-1)
        return ret;
    int way1 = cal(pos+1, time);
    int way2 = 0;
    if(time+item[pos].time<item[pos].last)
        way2 = item[pos].price+cal(pos+1, time+item[pos].time);
    if(way2>way1)
        select[pos][time] = 1, nex[pos][time] = {pos+1, time+item[pos].time};
    else select[pos][time] = 0, nex[pos][time] = {pos+1, time};
    ret = max(way1, way2);
    return ret;
}

void print(int pos, int time)
{
    if(select[pos][time])
        ans.pb(item[pos].id);
    if(nex[pos][time].first!=-1)
        print(nex[pos][time].first, nex[pos][time].second);
}
bool cmp(info a, info b)
{
    return a.last<b.last;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    mem(dp, -1);
    mem(nex, -1);
    f(i, 1, n)
    {
        cin>>item[i].time;
        cin>>item[i].last;
        cin>>item[i].price;
        item[i].id = i;
    }
    sort(item+1, item+n+1, cmp);
    cout << cal(1, 0) << "\n";
    print(1, 0);
    cout << ans.sz << "\n";
    f(i, 0, (int)ans.sz-1)
        cout << ans[i] << " ";
    return 0;
}

