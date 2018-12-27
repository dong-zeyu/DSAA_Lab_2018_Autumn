#include <iostream>

using namespace std;

inline void swap(int *T, int a, int b)
{
    int tmp = T[a];
    T[a] = T[b];
    T[b] = tmp;
}

inline void add(int *T, int n, int k)
{
    int ind = n;
    T[ind] = k;
    while(true)
    {
        int father = int ((float)ind/2 - 0.1);
        if(T[father] > T[ind])
        {
            swap(T, ind, father);
            ind = father;
        }
        else break;
        if(father == 0) break;
    }
}

inline void pop(int *T, int n)
{
    n = n - 1;
    T[0] = T[n];
    int ind = 0;
    while(true)
    {
        int cl = ind * 2 + 1;
        int cr = ind * 2 + 2;
        if(cl >= n) break;
        cr = cr >= n ? cl : cr;
        int t = T[cl] <= T[cr] ? cl : cr;
        if(T[ind] > T[t])
        {
            swap(T, ind, t);
            ind = t;
        }
        else break;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n;
        scanf("%d", &n);
        int A[200000];
        for(register int j = 0; j < n; j++)
        {
            int k;
            scanf("%d", &k);
            add(A, j, k);
        }
        int q;
        scanf("%d", &q);
        for(register int j = 0; j < q; j++)
        {
            int o;
            scanf("%d", &o);
            if(o == 1)
            {
                int k;
                scanf("%d", &k);
                add(A, n, k);
                ++n;
            }
            else if(o == 2)
            {
                pop(A, n);
                --n;
            }
            else printf("%d\n", A[0]);
        }
    }
    system("pause");
}
