#include <iostream>
 
using namespace std;
 
int t[10001];
 
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int N;
        scanf("%d", &N);
        for(int j = 1; j <= N; ++j)
            t[j] = 0;
        for(int j = 0; j < N-1; ++j)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            t[a]++; t[b]++;
        }
        for(int j = 2; j <= N; ++j)
        {
            if(t[j] == 1)
                printf("%d ", j);
        }
        printf("\n");
    }
}
