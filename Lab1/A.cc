#include <iostream>
#include <strings.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        string w[10];
        for(int j = 0; j < n; j++)
        {
            cin >> w[j];    
        }
        int m;
        cin >> m;
        string t[1000];
        for(int j = 0; j < m; j++)
        {
            cin >> t[j];
        }
        bool isIn = false;
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
                if(strcasecmp(w[j].c_str(), t[k].c_str()) == 0) 
                {
                    isIn = true;
                    goto print;
                }
        }
print:
        if(isIn) cout << "Appeared" << endl;
        else cout << "Not appeared" << endl;
    }
}
