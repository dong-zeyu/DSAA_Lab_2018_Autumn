#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int s[100000], c[100000];
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", s + i);
    }
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", c + i);
    }
    double a = 0;
    double b = 1000;
    while(b - a >= 1e-9)
    {
        double mid = (a + b) / 2;
        double r[100000];
        for(int j = 0; j < n; ++j)
            r[j] = (c[j] - mid) * s[j];
        partial_sort(r, r + k, r + n);
        for(int i = 0; i < n; ++i)
            printf("%f\n", r[i]);
        double max = 0;
        for(int i = k; i < n; ++i)
            max += r[i];
        if(max >= 0)
            a = mid;
        else
            b = mid;
    }
    printf("%.3f", (a + b) / 2);
}
