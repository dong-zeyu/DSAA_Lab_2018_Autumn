#include <iostream>

using namespace std;

bool strstr(const char *t, int tl, const char *p, int pl)
{
    if(tl < pl) return false;
    int ne[20];
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
        
        char str[1000][201];
        for(register int j = 0; j < N; ++j)
            scanf("%s", str[j]);

        int l;
        for(l = 0; str[0][l] != '\0'; ++l);


        for(int j = l; l >= 0; --l)
        {
            for(int k = 0; k < l - j; ++j)
            {
                int r = 1;
                for(; r < N; ++r)
                {
                    if(!strstr(str[r], 1000, str[0] + k, j))
                        break;
                }
                if(r == N)
                    
            }
        }
    }
    system("pause");
}
