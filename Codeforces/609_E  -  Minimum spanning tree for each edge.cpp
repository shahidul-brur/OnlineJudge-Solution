/*=================================*\
								   
	  Md. Shahidul Islam		   
		 CSE, BRUR				 
	  Rangpur, Bangladesh		  
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur		
 Blog: shahidul-brur.blogspot.com(in Bengali),
	   shahidul-brur-en.blogspot.com(in English) 
\*=================================*/
#include<bits/stdc++.h>
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
*/
using namespace std;

#define pb			  push_back
#define debug(x)	  cerr << "   ## " << #x << " = " << x << " ...\n"
#define mp			  make_pair
#define ff			  first
#define ss			  second
#define sz			  size()
#define all(a)		  a.begin(), a.end()
#define f(i, a, b)	  for(int i=(a);i<=(b);i++)
#define F(i, b, a)	  for(int i=(b);i>=(a);i--)
#define PI			  acos(-1.0)
#define EPS			  1e-6
#define mem(a, b)	  memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<float> vf;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//			  0123456789
const int MOD = 1000000007;
const int MAX = 200002;
vii adj[MAX];
vi tree[MAX];
map<ii, int> edgeId;
vector<pair<ii, int> > edgeList;
int par[MAX][18];
int level[MAX];
int mx[MAX][18];
bool included[MAX];
bool taken[MAX];
ll prim(int src)
{
	priority_queue<pair<ll, ii>, vector<pair<ll, ii> >, greater<pair<ll, ii> > > pq;
	ll mst = 0;
	pq.push(mp(0, mp(0, src)));
	while(!pq.empty())
	{
		int p = pq.top().ss.ff;
		int u = pq.top().ss.ss;
		ll w = pq.top().ff;
		//cout << p << " " << u << " " << w << "\n";
		pq.pop();
		if(!taken[u]){
			taken[u] = 1;
			if(p!=0)
			{
				included[edgeId[mp(p, u)]] = 1;
				mst+=w;
				tree[p].pb(u);
				tree[u].pb(p);
				//cout << p << " " << u << "\n";
			}
			int siz = adj[u].size();
			f(i, 0, siz-1)
			{
				pq.push(mp(adj[u][i].ss, mp(u, adj[u][i].ff)));
			}
		}
	}
	return mst;
}
void dfs(int u, int p)
{
	level[u] = level[p] + 1;
	int siz = tree[u].size();
	f(i, 0, siz-1)
	{
		int v = tree[u][i];
		if(v==p) continue;
		par[v][0] = u;
		mx[v][0] = edgeList[edgeId[mp(u, v)]].ss;
		dfs(v, u);
	}
}
void preprocess_lca_table(int n)
{
	f(j, 1, 17)
	{
		f(u, 1, n)
		{
			par[u][j] = par[par[u][j-1]][j-1];
			mx[u][j] = max(mx[u][j-1], mx[par[u][j-1]][j-1]);
		}
	}
}

int lca_mx(int u, int v)
{
	if(level[u]>level[v]) swap(u, v);
	int d = level[v] - level[u];
	//cout << d << " : ";
	int maxi  = 0;
	f(i, 0, 17)
	{
		if(d & (1<<i))
			maxi = max(mx[v][i], maxi), v = par[v][i];
	}
	if(u==v)
		return maxi;
	F(i, 17, 0)
	{
		if(par[u][i]!=par[v][i])
		{
			maxi = max(maxi, mx[u][i]);
			maxi = max(maxi, mx[v][i]);
			u = par[u][i], v = par[v][i];
		}
	}
	return maxi = max(max(maxi, mx[v][0]), mx[u][0]);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin>>n>>m;
	f(i, 0, m-1)
	{
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].pb(mp(v, w)); adj[v].pb(mp(u, w));
		edgeId[mp(u, v)] = i; edgeId[mp(v, u)] = i;
		edgeList.pb(mp(mp(u, v), w));
	}
	ll mst_cost = prim(1);
	dfs(1, 0);
	preprocess_lca_table(n);
	f(i, 0, m-1)
	{
		if(included[i]){
			cout << mst_cost << "\n";
			continue;
		}
		int u = edgeList[i].ff.ff;
		int v = edgeList[i].ff.ss;
		int w = edgeList[i].ss;
		int maxi = lca_mx(u, v);
		ll ans = mst_cost - maxi + w;
		//cout << maxi << " ";
		cout << ans << "\n";
	}
	return 0;
}


