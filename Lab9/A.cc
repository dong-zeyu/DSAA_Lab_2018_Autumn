#include <iostream>

using namespace std;

#define MAX 1001

int main()
{
    int T;
    scanf("%d", &T);
    for(int iter = 0; iter < T; ++iter)
    {
        int x[MAX], y[MAX];
        int N;
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i) scanf("%d%d", x + i, y + i);
        int Q;
        scanf("%d", &Q);
        for(int i = 0; i < Q; ++i)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%d\n", abs(x[a] - x[b]) + abs(y[a] - y[b]));
        }
    }
    #ifndef ONLINE_JUDGE
    system("pause");
    #endif
}
