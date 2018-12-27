#include <iostream>

using namespace std;

void pre(int N, int *l, int *r)
{
    printf("%d", N);
    if(l[N] != 0)
        pre(l[N], l, r);
    if(r[N] != 0)
        pre(r[N], l, r);
}

void in(int N, int *l, int *r)
{
    if(l[N] != 0)
        in(l[N], l, r);
    printf("%d", N);
    if(r[N] != 0)
        in(r[N], l, r);
}

void post(int N, int *l, int *r)
{
    if(l[N] != 0)
        post(l[N], l, r);
    printf("%d", N);
    if(r[N] != 0)
        post(r[N], l, r);
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int N;
        scanf("%d", &N);

        int l[10001] = {0};
        int r[10001] = {0};
        
        for(int j = 0; j < N - 1; ++j)
        {
            int f, a;
            scanf("%d%d", &f, &a);
            if(l[f] == 0)
                l[f] = a;
            else
                r[f] = a;
        }
        pre(1, l, r);
        printf("\n");
        in(1, l, r);
        printf("\n");
        post(1, l, r);
        printf("\n");
    }
    system("pause");
}
