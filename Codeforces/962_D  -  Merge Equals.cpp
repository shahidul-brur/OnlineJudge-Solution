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
const int MAX = 150005;

set<pair<ll, int > > st;

vector<pair<int, ll> > arr;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	f(i, 1, n)
	{
		int x;
		cin>>x;
		st.insert(mp(x, i));
	}
	while(1)
	{
		ll v1 = (*st.begin()).ff;
		int i1 = (*st.begin()).ss;
		auto it = st.begin();
		it++;
		bool change = 0;
		while(it!=st.end())
		{
			ll v2 = (*it).ff;
			int i2 = (*it).ss;
			if(v2==v1)
			{
				st.erase(mp(v1, i1));
				st.erase(mp(v2, i2));
				st.insert(mp(v2*2, i2));
				change = 1;
				break;
			}
			arr.pb(mp(i1, v1));
			st.erase(mp(v1, i1));
			it++;
			v1 = v2;
			i1 = i2;
		}
		if(change == 0)
			break;
	}
	for(auto v:st)
	{
		arr.pb(mp(v.ss, v.ff));
	}
	cout << arr.size() << "\n";
	sort(all(arr));
	int siz = arr.size();
	f(i, 0, siz-1)
	{
		cout << arr[i].ss << " ";
	}
	return 0;
}

