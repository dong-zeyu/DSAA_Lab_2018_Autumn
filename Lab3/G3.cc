#include <iostream>
 
using namespace std;
 
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n;
        scanf("%d", &n);
        int a[300001] = {0};
        int a0;
        scanf("%d", &a0);
        printf("%d", a0);
        ++a[a0];
        int mid = a0;
        float pt = 1;
        for(int j = 0; j < int(n / 2); ++j)
        {
            int a1, a2;
            scanf("%d%d", &a1, &a2);
            ++a[a1];
            ++a[a2];
            if(a1 > mid)
                pt += 0.5;
            else if(a1 < mid)
                pt -= 0.5;
            if(a2 > mid)
                pt += 0.5;
            else if(a2 < mid)
                pt -= 0.5;
            pt = int(pt);
            while(pt <= 0)
            {
                --mid;
                pt = pt + a[mid];
            }
            while(pt > a[mid])
            {
                pt = pt - a[mid];
                ++mid;
            }
            printf(" %d", mid);
        }
        printf("\n");
    }
}