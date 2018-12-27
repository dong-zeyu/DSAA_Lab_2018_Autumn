#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        int n;
        cin >> n;
        int a, b, m;
        cin >> a >> b;
        m = a - b;
        if(a < b)
        {
            int c;
            c = b; b = a; a = c;
        }
        for(int j = 0; j < n - 2; ++j)
        {
            int c;
            cin >> c;
            int t = a - c;
            if(t > m)
            {
                m = t;
            }
            if(c > a)
            {
                b = a;
                a = c;
            }
            else
            {
                b = c;
            }
        }
        cout << m << endl;
    }
}
