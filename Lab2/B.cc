#include <iostream>
#include <iomanip>

#define df(x) (x*(x*((35*x + 36)*x*x*x + 9) + 8) - 2*y)
#define f(x) x*(x*(x*((5*x + 6)*x*x*x + 3) + 4) - 2*y)

using namespace std;

double root(double a, double b, double y)
{
    double mid = (a + b)/2;
    // cout << mid << endl;
    if(b - a < 1e-6)
        return mid;
    else
    {
        double fmid = df(mid);
        if(fmid < 0)
            return root(mid, b, y);
        else
            return root(a, mid, y);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        double y;
        scanf("%lf", &y);
        double x0 = root(0, 100, y);
        printf("Case %d: %.4f\n", i + 1, f(x0));
        // cout << "Case " << i + 1 << ": " << fixed << setprecision(4) << f(x0) << endl;
    }
}
