#include <iostream>
#include <list>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n;
        scanf("%d", &n);
        int a0;
        scanf("%d", &a0);
        printf("%d", a0);
        list<int> l = {a0};
        for(int j = 0; j < int(n / 2); ++j)
        {
            int a1, a2;
            scanf("%d%d", &a1, &a2);
            if(a1 > a2)
            {
                int tmp = a1;
                a1 = a2;
                a2 = tmp;
            }
            list<int>::iterator it;
            for(it = l.begin(); it != l.end(); ++it)
            {
                if(*it >= a1)
                {
                    l.insert(it, a1);
                    break;
                }
            }
            if(it == l.end())
                l.push_back(a1);
            for(++it; it != l.end(); ++it)
            {
                if(*it >= a2)
                {
                    l.insert(it, a2);
                    break;
                }
            }
            if(it == l.end())
                l.push_back(a2);
            it = l.begin();
            for(int k = 0; k < j + 1; ++k)
                ++it;
            printf(" %d", *it);
        }
        printf("\n");
    }
}
