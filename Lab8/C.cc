#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100001

struct node
{
    vector<int> nb;
    bool fg = false;
    int l = -1;
};

node g[MAX];

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int m, n, s;
        scanf("%d%d%d", &n, &m, &s);
        for(int j = 1; j <= n; ++j)
        {
            g[j].nb.clear();
            g[j].fg = false;
        }
        for(int j = 0; j < m; ++j)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].nb.push_back(y);
            g[y].nb.push_back(x);
        }
        queue<int> q;
        q.push(s);
        g[s].l = 0;
        g[s].fg = true;
        while(!q.empty())
        {
            int c = q.front();
            q.pop();
            for(vector<int>::iterator it = g[c].nb.begin(); it != g[c].nb.end(); it++)
            {
                int t = *it;
                if(!g[t].fg)
                {
                    g[t].l = g[c].l + 1;
                    g[t].fg = true;
                    q.push(t);
                }
            }
        }
        for(int j = 1; j <= n; ++j) printf("%d ", g[j].l);
        printf("\n");
    }
    #ifdef DEBUG
    system("pause");
    #endif
}
