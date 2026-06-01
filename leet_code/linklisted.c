#include <stdio>

typedef struct Node
{
    int key;
    struct Node *next;
} Node;

Node *h = NULL;

Node *makeNode(int v)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = v;
    p->next = NULL;
    return p;
}

Node *addfirst(Node *h, int v)
{
    Node *p = makeNode(v);
    p->next = h;
    return p;
}

Node *addlast(Node *h, int v)
{
    if (h == NULL)
    {
        return makeNode(v);
    }
    h->next = addlast(h->next, v);
    return h;
}

Node *addbefore(Node *h, int u, int v)
{
    if (h == NULL)
    {
        return NULL;
    }
    if (h->key == v)
    {
        Node *q = makeNode(u);
        q->next = h;
        return q;
    }
    h->next = addbefore(h->next, u, v);
    return h;
}

Node *addafter(Node *h, int u, int v)
{
    if (h == NULL)
        return NULL;
    if (h->key == v)
    {
        Node *q = makeNode(u);
        q->next = h->next;
        h->next = q;
        return h;
    }
    h->next = addafter(h->next, u, v);
    return h;
}

Node *removenode(Node *h, int v)
{
    if (h == NULL)
    {
        return NULL;
    }
    if (h->key == v)
    {
        Node *tmp = h;
        h = h->next;
        free(tmp);
        return h;
    }
    h->next = removenode(h->next, v);
    return h;
}

Node *reverse(Node *h)
{
    Node *p = h;
    Node *pp = NULL;
    Node *np = NULL;
    while (p != NULL)
    {
        np = p->next;
        pp = p;
        p->next = pp;
        p = np;
    }
    return pp;
}

Node *find(Node *h, int k)
{
    for (Node *p = h; p != NULL; p = p->next)
    {
        if (p->key == k)
            return p;
    }
    return NULL;
}
void processAddLast()
{
    int k;
    scanf("%d", &k);
    if (find(h, k) == NULL)
        h = addlast(h, k);
}
void processAddFirst()
{
    int k;
    scanf("%d", &k);
    if (find(h, k) == NULL)
        h = addfirst(h, k);
}
void processAddAfter()
{
    int u, v;
    scanf("%d%d", &u, &v);
    if (find(h, u) == NULL)
        h = addafter(h, u, v);
}
void processAddBefore()
{
    int u, v;
    scanf("%d%d", &u, &v);
    if (find(h, u) == NULL)
        h = addbefore(h, u, v);
}
void processRemove()
{
    int k;
    scanf("%d", &k);
    h = removenode(h, k);
}
void processReverse()
{
    h = reverse(h);
}
void print(Node *h)
{
    for (Node *p = h; p != NULL; p = p->next)
        printf("%d ", p->key);
    printf("\n");
}
void processInitList()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        h = addlast(h, k);
    }
}

void solve()
{
    processInitList();
    while (1)
    {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0)
            break;
        if (strcmp(cmd, "addlast") == 0)
            processAddLast();
        else if (strcmp(cmd, "addfirst") == 0)
            processAddFirst();
        else if (strcmp(cmd, "addafter") == 0)
            processAddAfter();
        else if (strcmp(cmd, "addbefore") == 0)
            processAddBefore();
        else if (strcmp(cmd, "remove") == 0)
            processRemove();
        else if (strcmp(cmd, "reverse") == 0)
            processReverse();
    }
}
int main()
{
    solve();
    print(h);
}
