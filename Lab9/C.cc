// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define MAX 101

struct node
{
    int father;
} g[MAX];

struct edge
{
    int u;
    int v;
    int w;
} e[MAX*MAX];

struct comp_edge
{
    inline bool operator()(const edge l, const edge r) const { return l.w < r.w; };
} comp_edge_obj;

void update_father(node g[], int k)
{
    if(k != g[k].father)
    {
        update_father(g, g[k].father);
        g[k].father = g[g[k].father].father;
    }
}

int check_spanning_tree(edge e[], int m, int n, float cutoff)
{
    int min_tree = 0;
    int i = 1;
    for(int i = 1; i <= n; ++i) g[i].father = i;
    while(i <= m)
    {
        edge ed = e[i];
        ++i;
        if(ed.w < cutoff) continue;
        update_father(g, ed.u);
        update_father(g, ed.v);
        if(g[ed.u].father != g[ed.v].father)
        {
            g[g[ed.u].father].father = g[ed.v].father;
            min_tree += ed.w;
        }
    }
    for(int i = 1; i <=n; ++i)
    {
        update_father(g, i);
        if(g[i].father != g[1].father)
        {
            return -1;
        }
    }
    return min_tree;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int iter = 0; iter < T; ++iter)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        for(int i = 1; i <= n; ++i) g[i].father = i;

        for(int i = 1; i <= m; ++i)
        {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            e[i].u = x;
            e[i].v = y;
            e[i].w = w;
        }
        sort(e, e+m+1, comp_edge_obj);

        float a = 0;
        float b = e[m].w;
        int min_tree;
        while(b - a > 1)
        {
            float t = (a + b) / 2;
            if((min_tree = check_spanning_tree(e, m, n, t)) == -1) b = t;
            else a = t;
        }
        min_tree = check_spanning_tree(e, m, n, a);

        printf("%d\n", min_tree);
    }
    #ifndef ONLINE_JUDGE
    system("pause");
    #endif
}
