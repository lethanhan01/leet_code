#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct _node
{
    unsigned int v;
    struct _node* leftMostChild;
    struct _node* rightSibling;
    struct _node* parent;
}NODE;

NODE* pRoot = NULL;

NODE* CreateNode(int k)
{
    NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
    newNode->v = k;
    newNode->leftMostChild = NULL;
    newNode->rightSibling = NULL;
    newNode->parent = NULL;
    return newNode;
}

void DestroyNode(NODE* node)
{
    free(node);
    node = NULL;
}

void DestroyTree(NODE* tmpRoot)
{
    if (tmpRoot != NULL)
    {
        NODE* pLeftMostChild = tmpRoot->leftMostChild;
        DestroyNode(tmpRoot);
        while (pLeftMostChild != NULL)
        {
            NODE* pNext = pLeftMostChild->rightSibling;
            DestroyTree(pLeftMostChild);
            pLeftMostChild = pNext;
        }
    }
}

NODE* Find(NODE* tmpRoot, int x)
{
    if (tmpRoot == NULL)
        return NULL;
    else
    {
        if (tmpRoot->v == x)
            return tmpRoot;
        else
        {
            NODE* pLeftMostChild = tmpRoot->leftMostChild;
            while (pLeftMostChild != NULL)
            {
                NODE* result = Find(pLeftMostChild, x);
                if (result != NULL)
                    return result;
                else
                    pLeftMostChild = pLeftMostChild->rightSibling;
            }
            return NULL;
        }
    }
}

void Insert(int u, int v)
{
    NODE* tmp = Find(pRoot, v);
    if (tmp != NULL)
    {
        NODE* newNode = CreateNode(u);
        newNode->parent = tmp;
        NODE* pLeftMostChild = tmp->leftMostChild;
        if (pLeftMostChild == NULL)
        {
            tmp->leftMostChild = newNode;
        }else
        {
            while (pLeftMostChild->rightSibling != NULL)
            {
                pLeftMostChild = pLeftMostChild->rightSibling;
            }
            pLeftMostChild->rightSibling = newNode;
        }
    }
}

int Depth(NODE* tmp)
{
    int h = 0;
    while (tmp != NULL)
    {
        tmp = tmp->parent;
        h++;
    }
    return h;
}

int Height(NODE* tmp)
{
    if (tmp == NULL)
        return 0;
    else
    {
        NODE* leftMostChild = tmp->leftMostChild;
        if (leftMostChild != NULL)
        {
            int maxD = -1;
            while (leftMostChild != NULL)
            {
                int tmpD = Height(leftMostChild);
                if (tmpD > maxD)
                {
                    maxD = tmpD;
                }
                leftMostChild = leftMostChild->rightSibling;
            }
            return maxD + 1;
        }else
            return 1;
    }
}

int main()
{
    while (0 == 0)
    {
        char line[1024] = { 0 };
        fgets(line, sizeof(line) - 1, stdin);
        if (strstr(line,"*") != NULL)
            break;
        else
        {
            char command[1024] = { 0 };
            if (strstr(line,"MakeRoot") != NULL)
            {
                int param = 0;
                sscanf(line,"%s%d", command, &param);
                pRoot = CreateNode(param);
            }else if (strstr(line,"Insert") != NULL)
            {
                int u = 0, v = 0;
                sscanf(line,"%s%d%d", command, &u, &v);
                Insert(u, v);
            }else if (strstr(line,"Depth") != NULL)
            {
                int u = 0;
                sscanf(line,"%s%d", command, &u);
                NODE* tmp = Find(pRoot, u);
                printf("%d\n", Depth(tmp));
            }else if (strstr(line,"Height") != NULL)
            {
                int u = 0;
                sscanf(line,"%s%d", command, &u);
                NODE* tmp = Find(pRoot, u);
                printf("%d\n", Height(tmp));
            }
        }
    }
	DestroyTree(pRoot);
    return 0;
}
