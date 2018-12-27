#include <iostream>
#include <cstring>

using namespace std;


int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        char t[200001];
        char p[200001];
        scanf("%s", t);
        scanf("%s", p);

        register int j = 0;
        for(register int k = 0; t[k] != '*' && t[k] == p[j] && k < n; ++k) ++j;

        if(j == m)
        {
            printf("YES\n");
            continue;
        }

        register int l = m - 1;
        for(register int k = n - 1; t[k] != '*' && t[k] == p[l]; --k) --l;

        if(t[j] == '*' && t[n - m + l] == '*' && l - j >= -1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    system("pause");
}
