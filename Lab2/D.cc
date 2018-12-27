#include <iostream>

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int *r = new int[1000000];
    for(int i = 0; i < n; ++i)
        scanf("%d", r + i);
    int *d = new int[1000000], *s = new int[1000000], *t = new int[1000000], *h = new int[1000000];
    for(int i = 0; i < m; ++i)
        scanf("%d%d%d", d + i, s + i, t + i);
    for(int i = 0; i < m; ++i)
    {
        int l = t[i] - s[i] + 1;
        bool flag = true;
        int start = s[i] - 1;
        for(int j = 0; j < l; ++j)
        {
            h[j] = r[start + j] - d[i];
            if(h[j] < 0)
            {
                flag = false;
                printf("-1\n%d", i + 1);
                goto END;
            }
        }
        if(flag)
            for(int j = 0; j < l; ++j)
            {
                r[start + j] = h[j];
            }
        for(int j = 0; j < n; ++j)
        {
            printf("%d ", r[j]);
        }
        printf("\n");
    }
    printf("0");
END:;
}
