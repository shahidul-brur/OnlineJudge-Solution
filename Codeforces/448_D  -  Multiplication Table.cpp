#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll r, c, k;
ll cnt(ll v)
{
    ll tot = 0LL;
    for(ll i = 1;i<=r;i++)
    {
        //cout << i << " => " << min(c, v/i) << "\n";
        tot+=min(c, v/i);
        //if(tot>k)
           // return tot;
    }
    return tot;
}
int main()
{
    while(cin>>r>>c>>k)
    {
        ll b = 1, e = r*c;
ll ans=r*c;
        ll pre = -1;
        while(b<=e)
        {
            ll mid = (b+e)/2LL;
            //cout << mid << "\n=======\n";
            ll cur = cnt(mid);
            //cout << ".......\n\n" << cur << "\n\n";
            if(cur>=k)
            {
                ans=mid;
                e=mid-1;
            }
            else
                b=mid+1;
        }
     cout<< ans;
     }
    return 0;
}
