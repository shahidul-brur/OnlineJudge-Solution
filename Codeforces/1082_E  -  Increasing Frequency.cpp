#include<bits/stdc++.h>
using namespace std;
const int maxn = (int)5e5+5;
const int LOGN = 20;
int cnt[maxn], a[maxn], freq[maxn], last[maxn];
inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}
int main()
{
    int n=read(), c=read(), cfreq,ans;
    for(int i=1;i<=n;i++){
        a[i] = read();
        cnt[i] = cnt[i-1]+(a[i]==c);
    }
    ans = cnt[n];
    for(int i=1;i<=n;i++)if(a[i]!=c){
        freq[a[i]]++;
        last[a[i]]=(last[a[i]]==0)?i:last[a[i]];
        cfreq = cnt[i]-cnt[last[a[i]]-1];
        if(cfreq>=freq[a[i]]){
            freq[a[i]] = 1;
            last[a[i]] = i;
            cfreq = 0;
        }
        ans = max(ans, cnt[n]-cfreq+freq[a[i]]);
    }
    printf("%d",ans);
    return 0;
}