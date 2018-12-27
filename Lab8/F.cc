#include <bits/stdc++.h>
#include <list>

using namespace std;

#define MAX 1001

struct edge
{
    int n;
    int w;
};

struct node
{
    list<edge> chd;
    long long l = -1;
};

void iter_graph(node g[], int root)
{
    g[root].l = 0;
    for(list<edge>::iterator it = g[root].chd.begin(); it != g[root].chd.end(); it++)
    {
        if(g[it->n].l == -1)
            iter_graph(g, it->n);
        long long t = g[it->n].l + it->w;
        if(t > g[root].l) g[root].l = t;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int iter = 0; iter < T; ++iter)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        node g[MAX];
        for(int i = 0; i < m; ++i)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            g[x].chd.push_back({y, z});
        }

        long long max = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(g[i].l == -1) iter_graph(g, i);
            if(g[i].l > max) max = g[i].l;
        }

        printf("%lld\n", max);
    }
    #ifdef DEBUG
    system("pause");
    #endif
}
