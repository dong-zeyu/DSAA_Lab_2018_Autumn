#include <iostream>
#include <list>
#include <stack>

using namespace std;

list<int> t[100001];

void farnode(int root, int father, int layer, list<int> t[], int &the_farnode, int &the_layer)
{
    if(t[root].size() == 1)
    {
        if(layer > the_layer)
        {
            the_farnode = root;
            the_layer = layer;
            return;
        }
    }
    for(list<int>::iterator it = t[root].begin(); it != t[root].end(); it++)
    {
        if(*it != father) farnode(*it, root, layer + 1, t, the_farnode, the_layer);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int N;
        scanf("%d", &N);
        for(register int j = 0; j < N; ++j) t[j].clear();
        for(register int j = 0; j < N - 1; ++j)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            t[a].push_back(b);
            t[b].push_back(a);
        }
        int node;
        int max_l = 0;
        farnode(1, 0, 0, t, node, max_l);
        max_l = 0;
        int node2;
        farnode(node, 0, 0, t, node2, max_l);
        printf("%d\n", max_l);
    }
    system("pause");
}
