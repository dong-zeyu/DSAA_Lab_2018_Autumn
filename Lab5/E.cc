#include <iostream>

using namespace std;

char s[200002];
int ne[200002];

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n, m, l;
        scanf("%d%d", &n, &m);
        l = m + n;

        scanf("%s", s);
        scanf("%s", s + n);

        register int j = 0, k = -1;
        ne[0] = k;
        while(j < l)
        {
            if(k == -1 || s[j] == s[k])
                ne[++j] = ++k;
            else
                k = ne[k];
        }
        while(k > n || k > m)
            k = ne[k];

        s[k] = '\0';
        printf("%d %s\n", k, s);
    }
    system("pause");
}
