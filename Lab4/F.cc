#include <iostream>
#include <stdio.h>
#include <stack>

#define MOD 1000000007;
#define M 50

using namespace std;

inline void add(int m, int (*l)[M], int (*r)[M], int (*re)[M])
{
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            re[i][j] = (l[i][j] + r[i][j]) % MOD;
}

inline void sub(int m, int (*l)[M], int (*r)[M], int (*re)[M])
{
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            re[i][j] = (l[i][j] - r[i][j]) % MOD;
}

inline void mul(int m, int (*l)[M], int (*r)[M], int (*re)[M])
{
    int sum[M][M], adds[M][M];
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < m; ++j)
            for(int k = 0; k < m; ++k)
                adds[j][k] = l[j][i] * r[i][k];
        add(m, sum, adds, sum);
    }
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            re[i][j] = sum[i][j];
}

void print_s(stack<char> s)
{
    if(!s.empty())
    {
        char c = s.top();
        s.pop();
        print_s(s);
        if(c > '9')
            cout << (int)(c - '0');
        else
            cout << c;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int mat[50][M][M];
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < m; ++k)
                for(int l = 0; l < m; ++l)
                    scanf("%d", mat[j][k] + l);
        char a, b;
        int top = n;
        stack<char> s;
        getchar();
        b = getchar();
        while(true)
        {
            a = b;
            if(b != '\n' && b != EOF)
            {
                b = getchar();
                if(a == '1' && b == '0')
                {
                    a = '9' + 1;
                    b = getchar();
                }
            }
            if(a == ')' || a == '\n' || a == EOF)
            {
                stack<char> t;
                while(true)
                {
                    char o, r, l;
                    r = s.top();
                    s.pop();
                    if(s.empty())
                        o = 0;
                    else
                    {
                        o = s.top();
                        s.pop();
                    }
                    if(o == '*')
                    {
                        l = s.top();
                        s.pop();
                        mul(m, mat[l - '1'], mat[r - '1'], mat[top]);
                        s.push(top + '1');
                        ++top;
                    }
                    else
                    {
                        t.push(r);
                        t.push(o);
                        if(o == 0 || o == '(')
                        {
                            t.pop();
                            while(t.size() > 1)
                            {
                                l = t.top();
                                t.pop();
                                o = t.top();
                                t.pop();
                                r = t.top();
                                t.pop();
                                if(o == '+')
                                    add(m, mat[l - '1'], mat[r - '1'], mat[top]);
                                else if(o == '-')
                                    sub(m, mat[l - '1'], mat[r - '1'], mat[top]);
                                t.push(top + '1');
                                ++top;
                            }
                            s.push(t.top());
                            break;
                        }
                    }
                }
                if(a != ')')
                    break;
            }
            else
                s.push(a);
        }
        int re = s.top() - '1';
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < m - 1; ++j)
            {
                if(mat[re][i][j] < 0)
                    mat[re][i][j] += MOD;
                printf("%d ", mat[re][i][j]);
            }
            if(mat[re][i][m-1] < 0)
                mat[re][i][m-1] += MOD;
            printf("%d\n", mat[re][i][m-1]);
        }
    }
}
