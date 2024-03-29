#include<bits/stdc++.h>
using namespace std;
 
const int MX = 200002;
int ara[4*MX+5]; // array of Euler path
int n; // total nodes
int siz; // size of Euler path array
int col[MX+5]; // col of a node
int posStart[MX+5]; // starting position of a node in Euler array
int posEnd[MX+5]; // Ending position of a node in Euler array
int tree[4*MX+5][2]; // segment tree
bool lazy[4*MX];
vector<int> g[MX+5]; // adjacency graph
void dfs(int u, int par)
{
    ara[++siz] = col[u]; 
    posStart[u] = siz;
    
    int s = g[u].size();
    for ( int i = 0; i < s ; i++ )
    {
        int v = g[u][i];
        if(v!=par)
            dfs(v, u);
    }
    posEnd[u] = siz;
}
void propagate(int node, int b, int e)
{
    if(lazy[node]==0)
        return;
    swap(tree[node][0], tree[node][1]);
    if(b!=e){
        lazy[2*node]^=1;
        lazy[2*node+1]^=1;
    }
    lazy[node] = 0;
}

void build(int node, int b, int e)
{
    if (b == e){
        tree[node][0] = (ara[b]==0);
        tree[node][1] = (ara[b]==1);
        lazy[node] = 0;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(Left, b, mid);
    build(Right, mid + 1, e);
    tree[node][0] = tree[Left][0] + tree[Right][0];
    tree[node][1] = tree[Left][1] + tree[Right][1];
}
 
int query(int node, int b, int e, int l, int r)
{
    propagate(node, b, e);
    if(l>e || r<b)
        return 0;
    if(b>=l && e<=r) 
        return tree[node][1];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    return query(Left, b, mid, l, r)+query(Right, mid + 1, e, l, r);
}
 
void update(int node, int b, int e, int l,int r)
{
    propagate(node, b, e);
    if(l>e || r<b)
        return;
    if(b>=l && e<=r){
        lazy[node] ^= 1;
        propagate(node, b, e);
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, l, r);
    update(Right, mid + 1, e, l, r);
    tree[node][0] = tree[Left][0] + tree[Right][0];
    tree[node][1] = tree[Left][1] + tree[Right][1];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", " w", stdout);
    scanf("%d", &n);
    for( int i = 2 ; i <= n ; i++ )
    {
        int v;
        scanf("%d", &v);
        g[i].push_back(v);
        g[v].push_back(i);
    }
    for( int i = 1 ; i <= n ; i++ )
        scanf("%d", &col[i]);
    siz = 0;
    dfs(1, 0);
    build(1, 1, siz);
    int q;
    scanf("%d", &q);
    while(q--)
    {
        char tp[10];
        scanf("%s", tp);
        if( tp[0] == 'p' )
        {
            int node;
            scanf("%d", &node);
            update(1, 1, n, posStart[node], posEnd[node]);
        }
        else
        {
            int node;
            scanf("%d", &node);
            printf("%d\n", query(1, 1, n, posStart[node], posEnd[node]));
        }
    }
    return 0;
}
