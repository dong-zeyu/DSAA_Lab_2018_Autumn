#include <iostream>
#include <cstring>
#include <stack>
 
using namespace std;

void _print_s(stack<int> s)
{
    if(!s.empty())
    {
        int c = s.top();
        s.pop();
        cout << c << " ";
        _print_s(s);
    }
}

void print_s(stack<int> s)
{
    _print_s(s);
    cout << endl;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n;
        scanf("%d", &n);
        stack<int> sk;
        sk.push(n + 1);
        int *a = new int[n], *m = new int[n];
        for(int i = 0; i < n; ++i)
            scanf("%d", a + i);
        m[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; --i)
        {
            if(a[i] < m[i + 1])
                m[i] = a[i];
            else
                m[i] = m[i + 1];
        }
        int j = 0;
        while(j < n)
        {
            if(sk.top() <= m[j])
            {
                printf("%d ", sk.top());
                sk.pop();
            }
            else
            {
                sk.push(a[j]);
                ++j;
            }
        }
        while(sk.size() > 1)
        {
            printf("%d ", sk.top());
            sk.pop();
        }
        printf("\n");
        delete[] a;
        delete[] m;
    }
}