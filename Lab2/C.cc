#include <iostream>

using namespace std;

bool bin_search(int *n, int num, int t)
{
    if(num <= 3)
    {
        bool flag = false;
        for(int i = 0; i < num; ++i)
            if(*(n + i) == t) flag = true;
        return flag;
    }
    else
    {
        int mid = num / 2;
        if(*(n + mid - 1) == t)
            return true;
        else if(*(n + mid - 1) < t)
        {
            return bin_search(n + mid, num - mid, t);
        }
        else
        {
            return bin_search(n, mid - 1, t);
        }
    }
}


int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int counter = 0;
        int n, m;
        scanf("%d %d", &n, &m);
        int d[5000];
        for(int j = 0; j < n; ++j)
            scanf("%d", d + j);
        for(int j = 0; j < n; ++j)
        {
            if(d[j] < m)
            {
                int r = m - d[j];
                if(bin_search(d + j + 1, n - j, r))
                    ++counter;
            }
        }
        printf("%d\n", counter);
    }
}
