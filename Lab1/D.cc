#include <iostream>

using namespace std;

void print1(int l, const char* item)
{
    for(int k = 0; k < l; ++k)
    {
        cout << item;
    }
}

void print2(int l, const char* item1, const char* item2)
{
    bool flag = true;
    for(int k = 0; k < l; ++k)
    {
        if(flag)
        {
            cout << item1;
            flag = false;
        }
        else
        {
            cout << item2;
            flag = true;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int a2 = 2 * a, b2 = 2 * b, c2 = 2 * c;
        bool flag = true;
        int j;
        // Part I
        for(j = 0; j < b2; ++j)
        {
            print1(b2 - j, ".");
            if(flag)
            {
                print2(a2 + 1, "+", "-");
                print2(j > c2 ? c2 : j, ".", "+");
                flag = false;
            }
            else
            {
                print2(a2 + 1, "/", ".");
                print2(j > c2 ? c2 : j, "|", "/");
                flag = true;
            }
            print1(j - c2, ".");
            cout << endl;
        }
        // Part II
        for(int k = 0; k <= c2 - b2; ++k)
        {
            if(flag)
            {
                print2(a2 + 1, "+", "-");
                print2(b2, ".", "+");
                cout << endl;
                flag = false;
            }
            else
            {
                print2(a2 + 1, "|", ".");
                print2(b2, "/", "|");
                cout << endl;
                flag = true;
            }
        }
        // Part III
        j = j - c2;
        for(j = j <= 0 ? b2 - 1 : b2 - j; j >= 0; --j)
        {
            if(flag)
            {
                print2(a2 + 1, "+", "-");
                print2(j > c2 ? c2 : j, ".", "+");
                flag = false;
            }
            else
            {
                print2(a2 + 1, "|", ".");
                print2(j > c2 ? c2 : j, "/", "|");
                flag = true;
            }
            print1(b2 - j, ".");
            cout << endl;
        }
    }
}
