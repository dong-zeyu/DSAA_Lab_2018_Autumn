#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 10

struct node
{
    node *l = nullptr, *r = nullptr , *f = nullptr;
};

struct re
{
    int dep;
    bool comp;
    bool full;
};

re check(node *root)
{
    if (root == nullptr) return {-1, true ,true};
    re l = check(root->l);
    re r = check(root->r);
    if(l.comp && r.comp)
    {
        if(l.dep == r.dep)
        {
            if(l.full) return {l.dep + 1, true, r.full};
            else return {0, false, false};
        }
        else if(l.dep == r.dep + 1)
        {
            if(r.full) return {l.dep + 1, true, false};
            else return {0, false, false};
        }
        else return {0, false, false};
    }
    else return {0, false, false};
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n;
        scanf("%d", &n);
        node t[MAX];
        for(register int j = 1; j <= n; ++j)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            t[j].l = t + a;
            t[j].r = t + b;
            t[j].l->f = t + j;
            t[j].r->f = t + j;
        }
        node *root;
        for(register int j = 1; j <= n; ++j) if(t[j].f == nullptr) root = t + j;
        if(check(root).comp) printf("Yes\n");
        else printf("No\n");
    }
    system("pause");
}
