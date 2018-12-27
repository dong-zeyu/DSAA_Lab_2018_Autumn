#include <bits/stdc++.h>
#include <list>

using namespace std;

#define MAX 3   

struct node
{
    list<int> chd;
    int f = 0;
    int i;
    int o;
};



void intr_tree(node tree[], int root, int &sp)
{
    ++sp;
    tree[root].i = sp;
    for(list<int>::iterator it = tree[root].chd.begin(); it != tree[root].chd.end(); it++)
        intr_tree(tree, *it, sp);
    ++sp;
    tree[root].o = sp;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int iter = 0; iter < T; ++iter)
    {
        int n, m;
        scanf("%d%d", &n, &m);

        node tree[MAX];
        for(int i = 0; i < n - 1; ++i)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            tree[x].f = y;
            tree[y].chd.push_back(x);
        }

        int root;
        for(int i = 1; i <= n; ++i)
            if(tree[i].f == 0)
            {
                root = i;
                break;
            }

        int sp = 0;
        intr_tree(tree, root, sp);

        for(int i = 0; i < m; ++i)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if(tree[y].i <= tree[x].i && tree[y].o >= tree[x].o) printf("Yes\n");
            else printf("No\n");
        }
    }
    #ifdef DEBUG
    system("pause");
    #endif
}
