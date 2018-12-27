// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define MAX 500

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

void dijsktra(int dist[], int n, int src, int dst, int head[], edge e[])
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
        if(k.id == dst) return;
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

void find_min(int (*a)[7], int k, list<int> l, int &min, int dist, int prev)
{
    if(l.empty())
    {
        dist += a[prev][k+1];
        if(dist < min) min = dist;
        return;
    }
    for(list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        list<int> ln = l;
        ln.remove(*it);
        find_min(a, k, ln, min, dist + a[prev][*it], *it);
    }
}

edge e[2 * (MAX * MAX + 1)];

int main()
{
    int T;
    scanf("%d", &T);
    for(int iter = 0; iter < T; ++iter)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);

        int head[MAX+1] = {0};
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

        int fix[6];
        for(int i = 1; i <= k; ++i) scanf("%d", fix + i);
        
        int a[7][7];
        int dist[MAX+1];
        for(int i = 1; i <= k; ++i)
        for(int j = 1; j <= k; ++j)
        {
            dijsktra(dist, n, fix[i], fix[j], head, e);
            a[i][j] = dist[fix[j]];
        }
        for(int i = 1; i <= k; ++i)
        {
            dijsktra(dist, n, 1, fix[i], head, e);
            a[0][i] = dist[fix[i]];
            dijsktra(dist, n, fix[i], n, head, e);
            a[i][k+1] = dist[n];
        }

        int min = INT_MAX;
        list<int> l;
        for(int i = 1; i <= k; ++i) l.push_back(i);
        find_min(a, k, l, min, 0, 0);

        printf("%d\n", min);
    }
    #ifndef ONLINE_JUDGE
    system("pause");
    #endif
}
