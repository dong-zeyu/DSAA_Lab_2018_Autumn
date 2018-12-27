#include <iostream>
#include <vector>

using namespace std;

#define MAX 100001

struct node
{
    vector<int> nb;
    bool fg = false;
    int l;
};

// node g[MAX];
// int q[MAX];

node* g = (node *) malloc(sizeof(node) * MAX);
int * q = (int *) malloc(sizeof(int) * 100 * MAX);

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
        int rq = 0;
        int fq = 0;
        q[rq] = s;
        ++rq;
        g[s].l = 0;
        g[s].fg = true;
        while(rq != fq)
        {
            int c = q[fq];
            ++fq;
            g[c].fg = true;
            for(vector<int>::iterator it = g[c].nb.begin(); it != g[c].nb.end(); it++)
            {
                int t = *it;
                if(!g[t].fg)
                {
                    g[t].l = g[c].l + 1;
                    q[rq] = t;
                    ++rq;
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
