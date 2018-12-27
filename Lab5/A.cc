#include <iostream>
#include <cstring>

using namespace std;


int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int N;
        scanf("%d", &N);
        char s[10000][101];
        for(int j = 0; j < N; ++j)
            scanf("%s", s[j]);
        char e[10000];
        for(int j = 0; j < N; ++j)
            e[j] = s[j][strlen(s[j]) - 1];
        int m = 0, l = 1;
        for(int j = 1; j < N; ++j)
        {
            if(e[j] == e[j - 1])
                ++l;
            else if(l > m)
            {
                m = l;
                l = 1;
            }
            else
                l = 1;
        }
        if(l > m)
            m = l;
        printf("%d\n", m);
    }
    system("pause");
}
