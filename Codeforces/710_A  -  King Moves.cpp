#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define N 1000000

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll t, n;
    char s[10];
    cin>>s;
    int c= 0;
    if(s[0]>'a')
        c++;
    if(s[0]<'h')
        c++;
    if(s[1]>'1')
        c++;
    if(s[1]<'8')
        c++;
    if(s[0]>'a' && s[1]>'1')
        c++;
    if(s[0]<'h' && s[1]<'8')
        c++;
    if(s[0]>'a' && s[1]<'8')
        c++;
    if(s[0]<'h' && s[1]>'1')
        c++;
    cout << c << "\n";
    return 0;
}

