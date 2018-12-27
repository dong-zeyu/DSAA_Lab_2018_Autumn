#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);
        int max = 0;
        for(register int j = 0; j < N; ++j)
        {
            int a;
            scanf("%d", &a);
            if(a >= max)
                max = a;
        }
        printf("%d\n", max);
    }
    system("pause");
}
