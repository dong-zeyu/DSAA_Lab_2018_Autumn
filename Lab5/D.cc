#include <iostream>

using namespace std;

bool strstr(const char *t, int tl, const char *p, int pl)
{
    if(tl < pl) return false;
    int ne[100001];
    register int j = 0, l = -1;
    ne[0] = l;
    while(j < pl)
    {
        if(l == -1 || p[j] == p[l])
            ne[++j] = ++l;  
        else
            l = ne[l];
    }

    j = 0; l = 0;
    while(j < tl && l < pl)
    {
        if(l == -1 || t[j] == p[l])
        {
            ++j; ++l;
        }
        else
            l = ne[l];
    }
    if(l == pl) return true;
    else return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int N;
        scanf("%d", &N);
        if(N < 3)
            printf("0\n");
        char s[100001];
        int ne[100001];
        scanf("%s", s);
        register int j = 0, k = -1;
        ne[0] = k;
        while(j < N)
        {
            if(k == -1 || (s[j] == s[k] && strstr(s + k + 1, N - 2 * (k + 1), s, k + 1)))
                ne[++j] = ++k;
            else
                k = ne[k];
        }

        printf("%d\n", ne[N]);
    }
    system("pause");
}
