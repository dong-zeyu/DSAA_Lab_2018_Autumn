#include <iostream>
#include <list>
#include <queue>

using namespace std;

#define MAX 1001

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int m, n;
        scanf("%d%d", &n, &m);
        list<int> g[MAX];
        for(int j = 0; j < m; ++j)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
        }
        int Q;
        scanf("%d", &Q);
        for(int j = 0; j < Q; ++j)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            int fl[MAX] = {0};
            queue<int> q;
            q.push(x);
            fl[x] = 1;
            while(!q.empty())
            {
                int c = q.front();
                q.pop();
                for(list<int>::iterator it = g[c].begin(); it != g[c].end(); it++)
                {
                    if(!fl[*it])
                    {
                        q.push(*it);
                        fl[*it] = 1;
                    }
                }
            }
            if(fl[y]) printf("YES\n");
            else printf("NO\n");
        }
    }
    #ifdef DEBUG
    system("pause");
    #endif
}
