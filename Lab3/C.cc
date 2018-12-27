#include <iostream>
#include <list>

using namespace std;

struct cust
{
    char c;
    bool b;
};

int main()
{
    while(true)
    {
        int n, sum = 0;
        scanf("%d", &n);
        if(n == 0)
            break;
        getchar();
        char c;
        list<cust> l;
        while((c = getchar()) != '\n')
        {
            list<cust>::iterator it;
            for(it = l.begin(); it != l.end(); ++it)
                if(it -> c == c) break;
            if(it != l.end())
            {
                if(it -> b)
                    ++n;
                else
                    ++sum;
                l.erase(it);
            }
            else
            {
                cust t;
                t.c = c;
                if(n == 0)
                    t.b = false;
                else
                {
                    t.b = true;
                    --n;
                }
                l.push_back(t);
            }
        }
        printf("%d\n", sum);
    }
}
