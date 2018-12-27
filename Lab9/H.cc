// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define MAX 102
#define D(a, b) sqrt(((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z)))

struct hole
{
    int x;
    int y;
    int z;
    int r;
};

inline double distance(hole a, hole b)
{
    double d = D(a, b);
    d -= a.r;
    d -= b.r;
    return d > 0 ? d : 0;
}

inline int min_node(double dist[], bool fg[], int n)
{
    double min = DBL_MAX;
    int k = -1;
    for(int i = 0; i < n; ++i)
    {
        if(fg[i] && min > dist[i])
        {
            min = dist[i];
            k = i;
        }
    }
    return k;
}

void dijsktra(double dist[], int n, int src, int dst, double (*g)[MAX])
{
    fill(dist, dist + n, INT_MAX / 10);
    bool fg[MAX];
    fill(fg, fg + n, true);
    dist[src] = 0;

    while(true)
    {
        int k = min_node(dist, fg, n);
        fg[k] = false;
        
        if(k == dst) return;
        for(int i = 0; i < n; ++i)
        {
            if(fg[i] && dist[i] > dist[k] + g[k][i])
                dist[i] = dist[k] + g[k][i];
        }
    }
}

hole h[MAX];
double g[MAX][MAX];

int main()
{
    int T;
    scanf("%d", &T);
    for(int iter = 0; iter < T; ++iter)
    {
        int n;
        scanf("%d", &n);

        for(int i = 1; i <= n; ++i) scanf("%d%d%d%d", &h[i].x, &h[i].y, &h[i].z, &h[i].r);
        
        hole a, b;
        scanf("%d%d%d%d%d%d", &a.x, &a.y, &a.z, &b.x, &b.y, &b.z);
        a.r = b.r = 0;

        for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; ++j)
            g[i][j] = g[j][i] = distance(h[i], h[j]);
        for(int i = 1; i <= n; ++i)
        {
            g[0][i] = g[i][0] = distance(a, h[i]);
            g[n+1][i] = g[i][n+1] = distance(b, h[i]);
        }
        g[0][0] = g[n+1][n+1] = 0;
        g[0][n+1] = g[n+1][0] = distance(a, b);

        double dist[MAX];
        dijsktra(dist, n+2, 0, n+1, g);

        printf("%d\n", (int) round(dist[n+1] * 100));
    }
    #ifndef ONLINE_JUDGE
    system("pause");
    #endif
}
