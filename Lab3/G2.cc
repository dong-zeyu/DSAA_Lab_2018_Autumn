#include <iostream>
#include <list>

using namespace std;

struct node
{
    int a;
    int n;
};

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
        list<node> l = {{a0, 1}};
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
            list<node>::iterator it;
            for(it = l.begin(); it != l.end(); ++it)
            {
                if(it -> a == a1)
                    ++it -> n;
                else if(it -> a > a1)
                    l.insert(it, {a1, 1});
                else
                    continue;
                break;
            }
            if(it == l.end())
                l.push_back({a1, 1});
            for(; it != l.end(); ++it)
            {
                if(it -> a == a2)
                    ++it -> n;
                else if(it -> a > a2)
                    l.insert(it, {a2, 1});
                else
                    continue;
                break;
            }
            if(it == l.end())
                l.push_back({a2, 1});
            int cum = 0;
            for(it = l.begin(); it != l.end(); ++it)
            {
                cum += it -> n;
                if(cum >= j + 2)
                    break;
            }
            printf(" %d", it -> a);
        }
        printf("\n");
    }
}
