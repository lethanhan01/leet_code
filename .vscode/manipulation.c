#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct _node
{
    unsigned int v;
    struct _node* next;
}NODE;

typedef struct _fresult
{
    NODE* result;
    NODE* previous;
}FRESULT;

NODE* pListHead = NULL;
NODE* pListTail = NULL;

FRESULT* Find(const int v)
{
    NODE* pPrevious = NULL;
    if (pListHead != NULL)
    {
        NODE* tmp = pListHead;
        while (tmp != NULL)
        {
            if (tmp->v == v)
            {
                FRESULT* r = (FRESULT*)calloc(1, sizeof(FRESULT));
                r->result = tmp;
                r->previous = pPrevious;
                return r;
            }
            else
            {
                pPrevious = tmp;
                tmp = tmp->next;
            }
        }
        return NULL;
    }else
        return NULL;
}

void destroy()
{
    if (pListHead != NULL)
    {
        NODE* tmp = pListHead;
        while (tmp != NULL)
        {
            NODE* next = tmp->next;
            free(tmp);
            tmp = next;
        }
    }
    pListHead = NULL;
    pListTail = NULL;
}

void display()
{
    if (pListHead != NULL)
    {
        NODE* tmp = pListHead;
        while (tmp != NULL)
        {
            printf("%d ", tmp->v);
            tmp = tmp->next;
        }
    }
}

void addlast(int k)
{
    FRESULT* r = Find(k);
    if (r == NULL)
    {
        NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
        newNode->v = k;
        newNode->next = NULL;
        if (pListTail != NULL)
        {
            pListTail->next = newNode;
            pListTail = newNode;
        }else
        {
            pListHead = newNode;
            pListTail = newNode;
        }
    }else
    {
        free(r);
        r = NULL;
    }
}

void addfirst(int k)
{
    FRESULT* r = Find(k);
    if (r == NULL)
    {
        NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
        newNode->v = k;
        newNode->next = NULL;
        if (pListHead == NULL)
        {
            pListHead = newNode;
            pListTail = newNode;
        }else
        {
            newNode->next = pListHead;
            pListHead = newNode;
        }
    }else
    {
        free(r);
        r = NULL;
    }
}

void addafter(int u, int v)
{
    FRESULT* fv = Find(v);
    if (fv != NULL)
    {
        FRESULT* fu = Find(u);
        if (fu == NULL)
        {
            NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
            newNode->v = u;
            newNode->next = NULL;
            NODE* tmp = fv->result;
            NODE* tmpNext = tmp->next;
            tmp->next = newNode;
            newNode->next = tmpNext;
            if (tmp == pListTail)
            {
                pListTail = newNode;
            }
        }else
        {
            free(fu);
            fu = NULL;
        }
        free(fv);
        fv = NULL;
    }
}

void addbefore(int u, int v)
{
    FRESULT* fv = Find(v);
    if (fv != NULL)
    {
        FRESULT* fu = Find(u);
        if (fu == NULL)
        {
            NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
            newNode->v = u;
            newNode->next = NULL;
            NODE* tmp = fv->result;
            NODE* tmpPrev = fv->previous;
            newNode->next = tmp;
            if (tmpPrev != NULL)
            {
                tmpPrev->next = newNode;
            }
            if (tmp == pListHead)
            {
                pListHead = newNode;
            }
        }else
        {
            free(fu);
            fu = NULL;
        }
        free(fv);
        fv = NULL;
    }
}

void rmv(int k)
{
    FRESULT* fk = Find(k);
    if (fk != NULL)
    {
        NODE* tmp = fk->result;
        NODE* tmpPrev = fk->previous;
        NODE* tmpNext = tmp->next;
        if (tmpPrev != NULL)
        {
            tmpPrev->next = tmpNext;
        }
        if (tmp == pListHead)
        {
            pListHead = tmpNext;
        }
        if (tmp == pListTail)
        {
            pListTail = tmpPrev;
        }
        free(tmp);
        tmp = NULL;
        free(fk);
        fk = NULL;
    }
}

void reverse()
{
    pListTail = pListHead;
    NODE* p1 = pListHead;
    if (p1 != NULL)
    {
        NODE* p2 = p1->next;
        while (p2 != NULL)
        {
            NODE* p3 = p2->next;
            p2->next = p1;
            if (p1 == pListHead)
            {
                p1->next = NULL;
            }
            p1 = p2;
            p2 = p3;
        }
        pListHead= p1;
    }
}

int main()
{
    int n, k, u, v;
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
    {
        scanf("%d", &k);
        addlast(k);
    }
    while (0 == 0)
    {
        char line[1024] = { 0 };
        fgets(line, sizeof(line) - 1, stdin);
        if (strstr(line,"#") != NULL)
            break;
        else
        {
            char command[1024] = { 0 };
            sscanf(line, "%s", command);
            if (strcmp(command,"addlast") == 0)
            {
                sscanf(line, "%s%d", command, &k);
                addlast(k);
            }else if (strcmp(command,"addfirst") == 0)
            {
                sscanf(line, "%s%d", command, &k);
                addfirst(k);
            }else if (strcmp(command,"addafter") == 0)
            {
                sscanf(line, "%s%d%d", command, &u, &v);
                addafter(u, v);
            }else if (strcmp(command,"addbefore") == 0)
            {
                sscanf(line, "%s%d%d", command, &u, &v);
                addbefore(u, v);
            }else if (strcmp(command,"remove") == 0)
            {
                sscanf(line, "%s%d", command, &k);
                rmv(k);
            }else if (strcmp(command,"reverse") == 0)
            {
                reverse();
            }
        }
    }

    display();
}
