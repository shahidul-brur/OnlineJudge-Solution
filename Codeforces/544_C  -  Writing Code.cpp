#include<bits/stdc++.h>
using namespace std;
#define f(i, a, b) for(int i = (a); i<=(b);i++)
int dp[505][505], a[505], ans, n, m, b, mod;
int main()
{
	cin>>n>>m>>b>>mod;
	f(i, 1, n) cin>>a[i];
	dp[0][0] = 1;
	f(i, 1, n) f(j, 0, m) f(k, 0, b-a[i])
		dp[j+1][k+a[i]] = (dp[j+1][k+a[i]] + dp[j][k])%mod;
	f(i, 0, b) 
		ans = (ans + dp[m][i])%mod;
	cout << ans << "\n";
	return 0;
}