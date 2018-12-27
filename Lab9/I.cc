// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define MAX 501
#define D(a, b) (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b])

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

inline void update_father(vector<int> &prev, int k)
{
    if(k != prev[k])
    {
        update_father(prev, prev[k]);
        prev[k] = prev[prev[k]];
    }
}

inline int find_father(vector<int> &prev, int k)
{
    update_father(prev, k);
    return prev[k];
}

inline void join(vector<int> &prev, int x, int y)
{
    update_father(prev, x);
    update_father(prev, y);
    if(prev[x] != prev[y])
    {
        prev[prev[x]] = prev[y];
    }
}

int check_spanning_tree(vector<int> prev, edge e[], int m, int init_cost)
{
    int min_tree = init_cost;
    int i = 1;
    while(i <= m)
    {
        edge ed = e[i];
        ++i;
        update_father(prev, ed.u);
        update_father(prev, ed.v);
        if(prev[ed.u] != prev[ed.v])
        {
            prev[prev[ed.u]] = prev[ed.v];
            min_tree += ed.w;
        }
    }
    return min_tree;
}

void brute_force(vector<int> prev, int cost[], vector<int> set[], int total_cost, int m, edge e[], int n, int &min_cost, int depth)
{   
    if(depth == 1)
    {
        int cost_tmp = check_spanning_tree(prev, e, n*n, total_cost + cost[1]);
        if(cost_tmp < min_cost) min_cost = cost_tmp;
    }
    else brute_force(prev, cost, set, total_cost, m, e, n, min_cost, depth - 1);
    
    int father = *set[depth].begin();
    for(vector<int>::iterator it = set[depth].begin(); it != set[depth].end(); it++) join(prev, father, *it);

    if(depth == 1)
    {
        int cost_tmp = check_spanning_tree(prev, e, n*n, total_cost + cost[1]);
        if(cost_tmp < min_cost) min_cost = cost_tmp;
    }
    else brute_force(prev, cost, set, total_cost + cost[depth], m, e, n, min_cost, depth - 1);
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int iter = 0; iter < T; ++iter)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        
        int x[MAX];
        int y[MAX];
        for(int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);

        int k = 1;
        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            e[k].u = i;
            e[k].v = j;
            e[k].w = D(i, j);
            ++k;
        }
        sort(e, e+n*n+1, comp_edge_obj);

        int cost[9];
        vector<int> set[9];
        for(int i = 1; i <= m; ++i)
        {
            int t;
            scanf("%d%d", &t, cost + i);
            for(int j = 0; j < t; ++j)
            {
                int s;
                scanf("%d", &s);
                set[i].push_back(s);
            }
        }

        int min_cost = INT_MAX;
        vector<int> prev;
        prev.push_back(0);
        for(int i = 1; i <= n; ++i) prev.push_back(i);
        brute_force(prev, cost, set, 0, m, e, n, min_cost, m);

        printf("%d\n", min_cost);
    }
    #ifndef ONLINE_JUDGE
    system("pause");
    #endif
}
