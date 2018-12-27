#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define MAX 10

struct node
{
    int id;
    int dist;
};

struct edge
{
    int to;
    int next;
    int w;
};

struct compare_dist
{
    inline bool operator()(const node & l, const node & r) const { return l.dist > r.dist; };
};

inline bool operator>(node &l, node &r) { return l.dist > r.dist; }

void dijsktra(int dist[], int n, int src, int head[]);

edge e[200001];

int main()
{
    int T;
    scanf("%d", &T);
    for(int iter = 0; iter < T; ++iter)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int head[MAX] = {0};
        for(int i = 1; i <= 2*m; ++i)
        {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            e[i].to = y;
            e[i].w = w;
            e[i].next = head[x];
            head[x] = i;
            ++i;
            e[i].to = x;
            e[i].w = w;
            e[i].next = head[y];
            head[y] = i;
        }

        int a, b;
        scanf("%d%d", &a, &b);

        int dist_a[MAX];
        dijsktra(dist_a, n, a, head);
        int dist_b[MAX];
        dijsktra(dist_b, n, b, head);

        int min_dist = INT_MAX;
        for(int i = 1; i < n; ++i)
        {
            int max_dist = max(dist_a[i], dist_b[i]);
            if(max_dist < min_dist) min_dist = max_dist;
        }
        printf("%d\n", min_dist);
    }
    #ifndef ONLINE_JUDGE
    system("pause");
    #endif
}

void dijsktra(int dist[], int n, int src, int head[])
{
    fill(dist, dist + n + 1, INT_MAX / 10);
    priority_queue<node, vector<node>, compare_dist> que;
    for(int i = 1; i <= n; ++i) que.push({i, INT_MAX / 10});
    que.push({src, 0});
    dist[src] = 0;

    while(!que.empty())
    {
        node k = que.top();
        que.pop();
        if(dist[k.id] < k.dist) continue;
        int nb = head[k.id];
        while(nb != 0)
        {
            int to = e[nb].to;
            int w = e[nb].w;
            if(dist[to] > dist[k.id] + w)
            {
                dist[to] = dist[k.id] + w;
                que.push({to, dist[to]});
            }
            nb = e[nb].next;
        }
    }
}
