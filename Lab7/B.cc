#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 10

struct node
{
    int k = 0;
    node *l = nullptr, *r = nullptr , *f = nullptr;
};

bool ravel(node *root, int arr[], int &n)
{
    if(root->l != nullptr && !ravel(root->l, arr, n)) return false;
    if(arr[n-1] <= root->k)
    {
        arr[n] = root->k;
        n++;
    }
    else return false;
    if(root->r != nullptr) return ravel(root->r, arr, n);
    return true;
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
        for(int j = 1; j <= n; ++j) scanf("%d", &t[j].k);
        int j;
        int f, c;
        for(j = 1; j < n; ++j)
        {
            scanf("%d%d", &f, &c);
            if(t[c].k > t[f].k)
            {
                if(t[f].r == nullptr) t[f].r = t + c;
                else break;
            }
            else
            {
                if(t[f].l == nullptr) t[f].l = t + c;
                else break;
            }
            t[c].f = t + f;
        }
        if(j < n)
        {
            for(++j; j < n; ++j) scanf("%d%d", &f, &c);
            printf("Case #%d: NO\n", i + 1);
            continue;
        }
        node *root;
        for(int j = 1; j <= n; ++j) if(t[j].f == nullptr) root = t + j;
        int arr[MAX] = {0};
        j = 1;
        if(ravel(root, arr, j)) printf("Case #%d: YES\n", i + 1);
        else printf("Case #%d: NO\n", i + 1);
    }
    system("pause");
}
