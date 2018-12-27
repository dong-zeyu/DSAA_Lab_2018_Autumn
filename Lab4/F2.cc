#include <iostream>
#include <stack>
#include <queue>

#define MOD 1000000007
#define M 50

using namespace std;

inline int oadd(int x, int y) { return (x + y) % MOD; }

inline int osub(int x, int y) { return (x - y + MOD) % MOD; }

inline int omul(int x, int y) { return static_cast<int>((long long) x * y % MOD); }

inline void add(int m, int (*l)[M], int (*r)[M], int (*re)[M])
{
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            re[i][j] = oadd(l[i][j], r[i][j]);
}

inline void sub(int m, int (*l)[M], int (*r)[M], int (*re)[M])
{
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            re[i][j] = osub(l[i][j], r[i][j]);
}

inline void mul(int m, int (*l)[M], int (*r)[M], int (*re)[M])
{
    int result[M][M];
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            for(int k = 0; k < m; ++k)
                result[i][j] += omul(l[i][k], r[k][j]);
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            re[i][j] = result[i][j];
}

void _print_s(stack<char> s)
{
    if(!s.empty())
    {
        char c = s.top();
        s.pop();
        _print_s(s);
        if(c > '9')
            cout << ' ' << (int)(c - '0') << ' ';
        else if(c == '\n')
            cout << '#';
        else
            cout << c;
    }
}

void print_s(stack<char> s)
{
    _print_s(s);
    cout << endl;
}

void print_q(queue<char> q)
{
    if(!q.empty())
    {
        for(unsigned int i = 0; i < q.size(); ++i)
        {
            char c = q.front();
            q.pop();
            if(c == '\n')
                cout << '#';
            else
                cout << c;
            q.push(c);
        }
    }
    cout << endl;
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
                    scanf("%d ", &(mat[j][k][l]));
        char exp[51];
        scanf("%s", exp);
        queue<char> q(exp);
        char a;
        // Preprocessing the input
        while(true)
        {
            a = q.front();
            q.pop();
            if(a == '1' && q.front() == '0') // process number '10'
            {
                a = 10 + '0';
                q.pop();
            }
            if(a == '\n' || a == EOF)
                a = '\n';
            q.push(a);
            if(a == '\n')
                break;
        }
        // convert to postfix
        stack<char> s;
        while(true)
        {
            a = q.front();
            q.pop();
            if(a < '0')
            {
                if(a == ')') // if meet ')':  output to queue until '
                    while(true)
                    {
                        char k = s.top();
                        s.pop();
                        if(k == '(')
                            break;
                        q.push(k);
                    }
                else if(a == '\n') // if meet '\n': output remain
                {
                    while(!s.empty())
                    {
                        char k = s.top();
                        s.pop();
                        q.push(k);
                    }
                    q.push(a);
                    break;
                }
                else
                {
                    while(!s.empty() && s.top() <= a) // output until meet a lower priority operator
                    {
                        char k = s.top();
                        if(k == '(')
                            break;
                        s.pop();
                        q.push(k);
                    }
                    s.push(a);
                }
            }
            else
                q.push(a);
        }
        int top = n;
        while(true)
        {
            print_s(s);
            a = q.front();
            q.pop();
            if(a == '\n')
                break;
            else if(a < '0')
            {
                char r = s.top();
                s.pop();
                char l = s.top();
                s.pop();
                if(a == '+')
                    add(m, mat[l - '1'], mat[r - '1'], mat[top]);
                else if(a == '-')
                    sub(m, mat[l - '1'], mat[r - '1'], mat[top]);
                else if(a == '*')
                    mul(m, mat[l - '1'], mat[r - '1'], mat[top]);
                s.push(top + '1');
                ++top;
            }
            else
                s.push(a);
        }
        int re = s.top() - '1';
        for(int k = 0; k <= re; ++k)
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < m - 1; ++j)
                    printf("%d ", mat[k][i][j]);
                printf("%d\n", mat[k][i][m-1]);
            }
    }
}
