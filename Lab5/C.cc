#include <iostream>

using namespace std;

char t[1000001];
char p[1000001];
int ne[1000001];

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n, m;
        scanf("%d", &n);
        scanf("%s", t);

        scanf("%d", &m);
        scanf("%s", p);

        register int j = 0, k = -1;
        ne[0] = k;
        while(j < m)
        {
            if(k == -1 || p[j] == p[k])
                ne[++j] = ++k;
            else
                k = ne[k];
        }

        int count = 0;
        j = 0; k = 0;
        while(j < n && k <= m)
        {
            if(k == -1 || t[j] == p[k])
            {
                if(k == m - 1)
                    ++count;
                ++j; ++k;
            }
            else
                k = ne[k];
        }

        printf("%d\n", count);
    }
    system("pause");
}
