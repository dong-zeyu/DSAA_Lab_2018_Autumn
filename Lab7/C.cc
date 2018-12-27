#include <iostream>

using namespace std;

#define MAX 10

struct node
{
    int k = 0;
    node *l = nullptr, *r = nullptr , *f = nullptr;
};

struct re
{
    int dep;
    bool avl;
};

re check(node *root, int arr[], int &n)
{
    if(root->k == -1) return {0, true};
    re l = check(root->l, arr, n);
    if(l.avl && arr[n-1] < root->k)
    {
        arr[n] = root->k;
        n++;
    }
    else return {-1, false};
    re r = check(root->r, arr, n);
    if(r.avl && abs(l.dep - r.dep) <= 1) return {max(r.dep, l.dep) + 1, true};
    else return {-1, false};
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
        t[0].k = -1;
        for(register int j = 1; j <= n; ++j) scanf("%d", &t[j].k);
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
        int arr[MAX] = {-1};
        int j = 1;
        if(check(root, arr, j).avl) printf("Yes\n");
        else printf("No\n");
    }
    system("pause");
}
