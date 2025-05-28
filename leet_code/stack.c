#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct _node
{
    unsigned int v;
    struct _node* next;
}NODE;

NODE* pTop = NULL;

NODE* CreateNode(int k)
{
    NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
    newNode->v = k;
    newNode->next = NULL;
    return newNode;
}

void DestroyNode(NODE* node)
{
    free(node);
    node = NULL;
}

void Push(int k)
{
    NODE* newNode = CreateNode(k);
    newNode->next = pTop;
    pTop = newNode;
}

NODE* Pop()
{
    if (pTop != NULL)
    {
        NODE* tmp = pTop;
        pTop = pTop->next;
        return tmp;
    }else
        return NULL;
}

int IsEmpty()
{
    return pTop == NULL;
}

int main()
{
    while (0 == 0)
    {
        char line[1024] = { 0 };
        fgets(line, sizeof(line) - 1, stdin);
        if (strstr(line,"#") != NULL)
            break;
        else
        {
            char command[1024] = { 0 };
            sscanf(line,"%s", command);
            if (strcmp(command, "PUSH") == 0)
            {
                int k = 0;
                sscanf(line,"%s%d",command, &k);
                Push(k);
            }else if (strcmp(command, "POP") == 0)
            {
                NODE* tmp = Pop();
                if (tmp == NULL)
                    printf("NULL\n");
                else
                    printf("%d\n", tmp->v);
                DestroyNode(tmp);
            }
        }
    }
}