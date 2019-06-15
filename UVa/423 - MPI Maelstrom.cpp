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
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
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
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define AIN(A, B, C) assert(IN(A, B, C))
#define INF 1000000000
int dr[]={0, 0, 1, -1, 1, 1, -1, -1};
int dc[]={1, -1, 0, 0, 1, -1, 1, -1};
ll bigmod(ll num,ll pow,ll mod){ll rem=1;while(pow>0){if(pow%2==1){rem=(rem*num)%mod;}pow/=2;num=(num*num)%mod;}return rem;}
ll inverse_mod(ll divisor, ll mod){return bigmod(divisor,mod-2, mod);}

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main()
{
   //fast;
   in;
   //out;
   char value[30];
   int N, i, j, k, cost[102][102], total;
   while(scanf("%d", &N)!=EOF)
   {
       cost[1][1]=0;
       for(i=2;i<=N;i++)
       {
           cost[i][i]=0;
           for(j=1;j<i;j++)
           {
               scanf("%s", value);
               if(value[0]=='x')
                    cost[i][j]=cost[j][i]=INF;
               else cost[i][j]=cost[j][i]=atoi(value);
           }
       }
       for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                for(k=1;k<=N;k++)
                    cost[i][j]=min(cost[i][j], cost[i][k]+cost[k][j]);
       for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                printf("%d ", cost[i][j]);
            }
            printf("\n");
        }
       total=0;
       for(i=2;i<=N;i++)
            if(cost[1][i]!=INF)
                total+=cost[1][i];
       printf("%d\n", total);
       
   }
   
   return 0;
}