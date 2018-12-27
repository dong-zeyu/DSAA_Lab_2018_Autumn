#include <iostream>

using namespace std;

struct node {
    int coef;
    int exp;
    node* next;
};

void add_poly(node* h, int coef, int exp)
{
    if(exp == 0)
        h -> coef += coef;
    else
    {
        node* k = new node;
        node* p = h;
        k -> coef = coef;
        k -> exp = exp;
        k -> next = NULL;
        while(p -> next != NULL)
        {
            if(p -> next -> exp > k -> exp)
            {
                k -> next = p -> next;
                p -> next = k;
                break;
            }
            else if(p -> next -> exp == k -> exp)
            {
                p -> next -> coef += coef;
                delete k;
                break;
            }
            else
                p = p -> next;
        }
        if(p -> next == NULL)
            p -> next = k;
    }
}

void remove_poly(node* h)
{
    while(h != NULL)
    {
        node* tmp = h -> next;
        delete h;
        h = tmp;
    }
}

void print_poly(node* h)
{
    while(h -> coef == 0)
    {
        h = h -> next;
        if(h == NULL)
        {
            printf("0\n");
            return;
        }
    }
    if(h -> exp != 0)
    {
        if(h -> coef == 1)
            printf("x");
        else if(h -> coef == -1)
            printf("-x");
        else
            printf("%dx", h -> coef);
        if(h -> exp != 1)
            printf("^%d", h -> exp);
    }
    else
        printf("%d", h -> coef);
    h = h -> next;
    while(h != NULL)
    {
        if(h -> coef != 0)
        {
            if(h -> coef < 0 && h -> coef != -1)
                printf("%dx", h -> coef);
            else if(h -> coef > 0 && h -> coef != 1)
                printf("+%dx", h -> coef);
            else if(h -> coef == 1)
                printf("+x");
            else
                printf("-x");
            if(h -> exp != 1)
                printf("^%d", h -> exp);
        }
        h = h -> next;
    }
    printf("\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n, m, coef, exp;
        node* h = new node;
        h -> coef = 0;
        h -> exp = 0;
        h -> next = NULL;
        scanf("%d", &n);
        for(int j = 0; j < n; ++j)
        {
            scanf("%d%d", &coef, &exp);
            add_poly(h, coef, exp);
        }
        scanf("%d", &m);
        for(int j = 0; j < m; ++j)
        {
            scanf("%d%d", &coef, &exp);
            add_poly(h, coef, exp);
        }
        print_poly(h);
        remove_poly(h);
    }
}
