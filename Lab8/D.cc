#include <iostream>

using namespace std;

#define MAX 76

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int m, n;
        scanf("%d%d", &n, &m);
        int g[MAX][MAX] = {0};
        for(int j = 0; j < m; ++j)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x][y] = 1;
            g[y][x] = 1;
        }
        
        int c = 0;
        for(int j = 1; j <= n; ++j)
            for(int k = j + 1; k <= n; ++k)
                for(int l = k + 1; l <= n; ++l)
                    for(int t = l + 1; t <= n; ++t)
                        if(g[j][k] == 1 && g[j][l] == 1 && g[j][t] == 1 && g[k][l] == 1 && g[k][t] == 1 && g[l][t] == 1)
                            ++c;
        
        printf("%d\n", c);
    }
    #ifdef DEBUG
    system("pause");
    #endif
}
