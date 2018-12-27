#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        string s;
        cin >> s;
        string sample = "07/3/2011";
        vector<string> strs;
        boost::split(strs, sample, boost::is_any_of("/"));
        cout << strs[1];
    }
}
