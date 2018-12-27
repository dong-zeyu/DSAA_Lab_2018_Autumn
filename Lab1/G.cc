#include <iostream>

using namespace std;

bool put(int d, int e, int m, int n)
{
    if((d <= m && e <= n) || (d <= n && e <= m))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool check(int a, int b, int c, int m, int n)
{
    if(put(2 * c + a, 2 * c + 2 * b, m, n) ||
       put(b + c + a, 2 * c + 2 * b, m, n) ||
       put(b + c + a, a + b + 2 * c, m, n) ||
       put(2 * c + a, a + c + 2 * b, m, n) ||
       put(c + a, 3 * b + a + c, m, n))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        int a, b, c;
        int m, n;
        cin >> a >> b >> c;
        cin >> m >> n;
        if(check(a, b, c, m, n) ||
           check(a, c, b, m, n) ||
           check(b, a, c, m, n) ||
           check(b, c, a, m, n) ||
           check(c, b, a, m, n) ||
           check(c, a, b, m, n))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}