#include <iostream>
#include <cstring>
#include <stack>
 
using namespace std;
 
int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n;
        scanf("%d", &n);
        stack<int> sk, max, min;
        for(int j = 0; j < n; ++j)
        {
            char s[5];
            scanf("%s", s);
            int k;
            if(strcmp(s, "push") == 0)
            {
                scanf("%d", &k);
                sk.push(k);
                if(min.empty() || k <= min.top())
                    min.push(k);
                else
                    min.push(min.top());
                if(max.empty() || k >= max.top())
                    max.push(k);
                else
                    max.push(max.top());
            }
            else
            {
                k = sk.top();
                sk.pop();
                min.pop();
                max.pop();
                if(!sk.empty())
                    printf("%d\n", max.top() - min.top());
                else
                    printf("0\n");
            }
        }
    }
}