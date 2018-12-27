#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n;
        scanf("%d", &n);
        double x[50000], w[50000];
        for(int i = 0; i < n; ++i)
            scanf("%lf%lf", x + i, w + i);
        double a = x[0], b = x[n - 1];
        double mid, midmid, summ, summm;
        while(b - a >= 1e-3)
        {
            mid = (b + a) / 2;
            summ = 0;
            for(int j = 0; j < n; ++j)
            {
                double tmp = abs(x[j] - mid);
                summ += tmp * tmp * tmp * w[j];
            }
            midmid = (mid + b) / 2;
            summm = 0;
            for(int j = 0; j < n; ++j)
            {
                double tmp = abs(x[j] - midmid);
                summm += tmp * tmp * tmp * w[j];
            }
            if(summ < summm)
                b = midmid;
            else
                a = mid;
        }
        printf("Case #%d: %.0f\n", i + 1, summ);
    }
}
