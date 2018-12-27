#include <iostream>
#include <list>

using namespace std;

struct node
{
    bool flag;
    list<int> c;
};

void inter_tree(int root, int father, int layer, node t[], int layers[])
{
    if(t[root].flag) layers[layer]++;
    for(list<int>::iterator it = t[root].c.begin(); it != t[root].c.end(); it++)
    {
        if(*it != father) inter_tree(*it, root, layer + 1, t, layers);
    }
}

node t[10001];

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int N;
        scanf("%d", &N);
        for(int j = 1; j <= N; ++j)
        {
            int f;
            scanf("%d", &f);
            t[j].flag = f;
            t[j].c.clear();
        }
        for(int j = 0; j < N - 1; ++j)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            t[a].c.push_back(b);
            t[b].c.push_back(a);
        }
        int layers[10000] = {0};
        inter_tree(1, 0, 0, t, layers);
        int j = 0;
        for(j = 0; j < N; ++j) if(layers[j] % 2 == 1) break;
        if(j == N) printf("NO\n"); else printf("YES\n");
    }
    system("pause");
}
