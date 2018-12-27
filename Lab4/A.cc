#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d\n", &T);
    for(int i = 0; i < T; ++i)
    {
        char s[7] = {'l', 'a', 'n', 'r', 'a', 'n', '\0'};
        int t = 0;
        char a;
        while((a = getchar()) != '\n' && a != EOF)
        {
            if(a == s[t])
                ++t;
        }
        if(t == 6)  printf("YES\n");
        if(t != 6)  printf("NO\n");
    }
}
