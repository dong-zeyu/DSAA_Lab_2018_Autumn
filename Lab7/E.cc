#include <iostream>

using namespace std;

#define MAX 20

inline void swap(int *T, int a, int b)
{
    int tmp = T[a];
    T[a] = T[b];
    T[b] = tmp;
}

inline void add_min(int *T, int n, int k)
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

inline void pop_min(int *T, int n)
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
        int n, K;
        scanf("%d%d", &n, &K);
        ++K;
        int A[MAX];
        for(int j = 0; j < n; ++j) scanf("%d", A + j);
        int Q[MAX];
        int j;
        for(j = 0; j < K; ++j) add_min(Q, j, A[j]);
        for(; j < n; ++j)
        {
            printf("%d ", Q[0]);
            pop_min(Q, K);
            add_min(Q, K - 1, A[j]);
        }
        for(j = K; j > 0; --j)
        {
            printf("%d ", Q[0]);
            pop_min(Q, j);
        }
        printf("\n");
    }
    system("pause");
}
