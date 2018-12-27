#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d\n", &T);
    for(int i = 0; i < T; ++i)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int q[100000];
        for(int j = 0; j < n; ++j)
            scanf("%d", q + j);
        int h = 0;
        unsigned long long int s = 0;
        for(int r = 0; r < n; ++r)
        {
            while(h != n - 1 && q[h + 1] - q[r] <= m)   ++h;
            s += ((h - r) * (h - r - 1)) / 2;
        }
        printf("%llu\n", s);
    }
}
