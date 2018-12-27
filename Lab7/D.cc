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

inline void add_max(int *T, int n, int k)
{
    int ind = n;
    T[ind] = k;
    while(true)
    {
        int father = int ((float)ind/2 - 0.1);
        if(T[father] < T[ind])
        {
            swap(T, ind, father);
            ind = father;
        }
        else break;
        if(father == 0) break;
    }
}

inline void pop_max(int *T, int n)
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
        int t = T[cl] >= T[cr] ? cl : cr;
        if(T[ind] < T[t])
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
        int A[MAX] = {0};
        if(K >= int(0.8*n))
        {
            K = n - K;
            for(int j = 0; j < n; ++j)
            {
                int k;
                scanf("%d", &k);
                add_min(A, j, k);
            }
            for(int j = 0; j < K; ++j) pop_min(A, n - j);
            printf("%d\n", A[0]);
        }
        else
        {
            for(int j = 0; j < n; ++j)
            {
                int k;
                scanf("%d", &k);
                add_max(A, j, k);
            }
            for(int j = 0; j < K - 1; ++j) pop_max(A, n - j);
            printf("%d\n", A[0]);
        }
    }
    system("pause");
}
