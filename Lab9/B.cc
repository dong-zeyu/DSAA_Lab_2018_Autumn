// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define MAX 101

struct node
{
    int head;
    int father;
};

struct edge
{
    int u;
    int v;
    int w;
};

struct comp_edge
{
    inline bool operator()(const edge *l, const edge *r) const { return l->w > r->w; };
};

void update_father(node g[], int k)
{
    if(k != g[k].father)
    {
        update_father(g, g[k].father);
        g[k].father = g[g[k].father].father;
    }

}

node g[MAX];
edge e[MAX*MAX];

int main()
{
    int T;
    scanf("%d", &T);
    for(int iter = 0; iter < T; ++iter)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        for(int i = 1; i <= n; ++i)
        {
            g[i].father = i;
        }

        priority_queue<edge*, vector<edge*>, comp_edge> heap;
        for(int i = 1; i <= m; ++i)
        {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            e[i].u = x;
            e[i].v = y;
            e[i].w = w;
            heap.push(e + i);
        }

        int min_tree = 0;
        while(!heap.empty())
        {
            edge *ed = heap.top();
            heap.pop();
            update_father(g, ed->u);
            update_father(g, ed->v);
            if(g[ed->u].father != g[ed->v].father)
            {
                g[g[ed->u].father].father = g[ed->v].father;
                min_tree += ed->w;
            }
        }

        printf("%d\n", min_tree);
    }
    #ifndef ONLINE_JUDGE
    system("pause");
    #endif
}
