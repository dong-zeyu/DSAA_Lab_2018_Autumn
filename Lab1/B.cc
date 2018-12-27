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
        int a = n / 21, b = n % 21;
        long long unsigned int r = 1;
        for(int j = 0; j < a; ++j)
        {
            r = r * 460353133;
            r = r % 1000000007;
        }
        for(int j = 0; j < b; ++j)
        {
            r = r * 3;
            r = r % 1000000007;
        }
        cout << r - 1 << endl;
    }
}