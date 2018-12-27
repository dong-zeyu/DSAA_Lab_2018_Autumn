#include <iostream>

using namespace std;


bool bin_search(int *n, int num, int t)
{
    if(num <= 3)
    {
        bool flag = false;
        for(int i = 0; i < num; ++i)
            if(*(n + i) == t) flag = true;
        return flag;
    }
    else
    {
        int mid = num / 2;
        if(*(n + mid - 1) == t)
            return true;
        else if(*(n + mid - 1) < t)
        {
            return bin_search(n + mid, num - mid, t);
        }
        else
        {
            return bin_search(n, mid - 1, t);
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        int m, n;
        int* d = new int[1000000];
        cin >> n >> m;
        for(int j = 0; j < n; ++j)
        {
            cin >> d[j];
        }
        if(bin_search(d, n, m)) cout << "YES" << endl;
        else cout << "NO" << endl;
        delete d;
    }
}
