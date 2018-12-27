#include <iostream>

using namespace std;

#define MAX 1001

int g[MAX][MAX];

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int g_n[MAX] = {0};
        int m, n;
        scanf("%d%d", &n, &m);
        for(int j = 0; j < m; ++j)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x][g_n[x]] = y;
            ++g_n[x];
        }
        int Q;
        scanf("%d", &Q);
        for(int j = 0; j < Q; ++j)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            bool fl[MAX] = {0};
            int q[MAX];
            int qr = 0;
            int qf = 0;
            q[qr] = x;
            ++qr;
            fl[x] = true;
            while(qr - qf != 0)
            {
                int c = q[qf];
                ++qf;
                for(int k = 0; k < g_n[c]; ++k)
                {
                    if(!fl[g[c][k]])
                    {
                        q[qr] = g[c][k];
                        ++qr;
                        fl[g[c][k]] = true;
                    }
                }
            }
            if(fl[y]) printf("YES\n");
            else printf("NO\n");
        }
    }
    #ifdef DEBUG
    system("pause");
    #endif
}
