#include <iostream>

using namespace std;

#define MAX 5

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
            g[x-1][y-1] = 1;
        }
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < n; ++k) printf("%d ", g[j][k]);
            printf("\n");
        }
    }
    system("pause");
}
