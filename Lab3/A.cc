#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int l1[100000], l2[100000];
        for(int j = 0; j < n; ++j)
            scanf("%d", l1 + j);
        for(int j = 0; j < m; ++j)
            scanf("%d", l2 + j);
        int ans[200000], p1 = 0, p2 = 0;
        for(int j = 0; j < n + m; ++j)
        {
            if(p1 == n)
            {
                memcpy(ans + j, l2 + p2, 4 * (m - p2));
                break;
            }
            if(p2 == m)
            {
                memcpy(ans + j, l1 + p1, 4 * (n - p1));
                break;
            }
            if(l1[p1] <= l2[p2])
            {
                ans[j] = l1[p1];
                ++p1;
            }
            else
            {
                ans[j] = l2[p2];
                ++p2;
            }
        }
        for(int j = 0; j < n + m - 1; ++j)
            printf("%d ", ans[j]);
        printf("%d\n", ans[m + n -1]);
    }
}
