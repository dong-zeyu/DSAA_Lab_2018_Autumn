#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d\n", &T);
    for(int i = 0; i < T; ++i)
    {
        int n;
        scanf("%d\n", &n);
        char s[30000], a;
        a = getchar();
        if(a == '{' || a == '(' || a == '[')
            s[0] = a;
        else
        {
            printf("NO\n");
            while((a = getchar()) != '\n' && a != EOF);
            continue;
        }
        int t = 0;
        for(int j = 1; j < n; ++j)
        {
            a = getchar();
            if(a == '{' || a == '(' || a == '[')
            {
                ++t;
                s[t] = a;
            }
            else if((a == '}' && s[t] == '{') || (a == ']' && s[t] == '[') || (a == ')' && s[t] == '('))
                --t;
            else
                break;
        }
        if(t == -1)
            printf("YES\n");
        else
        {
            printf("NO\n");
            while((a = getchar()) != '\n' && a != EOF);
        }
    }
}
