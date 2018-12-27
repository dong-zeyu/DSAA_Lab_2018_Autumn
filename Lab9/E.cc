#include <bits/stdc++.h>

using namespace std;

#define MAX 6001

inline void fastscan(int &number)
{
    register int c;
  
    number = 0; 

    while(c <= 47 || c > 58) c = getchar();
    for (; (c > 47 && c < 58); c = getchar()) 
        number = number *10 + c - 48;
}

struct edge
{
    int to;
    int next;
};

edge e[100001];

int main()
{
    int T;
    fastscan(T);
    for(int iter = 0; iter < T; ++iter)
    {
        int n, m;
        fastscan(n);
        fastscan(m);
        int head[MAX] = {0};
        int i_d[MAX] = {0};
        for(int i = 1; i <= m; ++i)
        {
            int x, y;
            fastscan(x);
            fastscan(y);

            e[i].to = y;
            e[i].next = head[x];
            head[x] = i;

            ++i_d[y];
        }

        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 1; i <= n; ++i) if(i_d[i] == 0) q.push(i);

        queue<int> result;
        while(!q.empty())
        {
            int k = q.top();
            q.pop();
            result.push(k);
            int i = head[k];
            while(i != 0)
            {
                --i_d[e[i].to];
                if(i_d[e[i].to] == 0) q.push(e[i].to);
                i = e[i].next;
            }
        }

        bool is_impossible = true;
        for(int i = 1; i <= n; ++i)
        {
            if(i_d[i] > 0)
            {
                is_impossible = false;
                break;
            }
        }

        if(is_impossible)
        {
            while(!result.empty())
            {
                printf("%d ", result.front());
                result.pop();
            }
            printf("\n");
        }
        else printf("impossible\n");
    }
    #ifndef ONLINE_JUDGE
    system("pause");
    #endif
}
