#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct _node
{
    int v;
    struct _node* leftChild;
    struct _node* rightChild;
}NODE;

NODE* pRoot = NULL;

NODE* CreateNode(int u)
{
    NODE* tmp = (NODE*)calloc(1, sizeof(NODE));
    tmp->v = u;
    tmp->leftChild = NULL;
    tmp->rightChild = NULL;
    return tmp;
}

void MakeRoot(int u)
{
    pRoot = CreateNode(u);
}

NODE* Find(NODE* tmpRoot, int u)
{
    if (tmpRoot == NULL)
        return NULL;
    else
    {
        if (tmpRoot->v == u)
            return tmpRoot;
        else
        {
            NODE* leftResult = Find(tmpRoot->leftChild, u);
            if (leftResult == NULL)
            {
                NODE* rightResult = Find(tmpRoot->rightChild, u);
                if (rightResult == NULL)
                    return NULL;
                else
                    return rightResult;
            }else
                return leftResult;
        }
    }
}

void AddLeft(int u, int v)
{
    NODE* nodeV = Find(pRoot, v);
    if (nodeV != NULL && nodeV->leftChild == NULL)
    {
        NODE* nodeU = Find(pRoot, u);
        if (nodeU == NULL)
        {
            NODE* newNode = CreateNode(u);
            nodeV->leftChild = newNode;
        }
    }
}

void AddRight(int u, int v)
{
    NODE* nodeV = Find(pRoot, v);
    if (nodeV != NULL && nodeV->rightChild == NULL)
    {
        NODE* nodeU = Find(pRoot, u);
        if (nodeU == NULL)
        {
            NODE* newNode = CreateNode(u);
            nodeV->rightChild = newNode;
        }
    }
}

void PreOrder(NODE* tmpRoot)
{
    if (tmpRoot != NULL)
    {
        printf("%d ", tmpRoot->v);
        PreOrder(tmpRoot->leftChild);
        PreOrder(tmpRoot->rightChild);
    }
}

void InOrder(NODE* tmpRoot)
{
    if (tmpRoot != NULL)
    {
        InOrder(tmpRoot->leftChild);
        printf("%d ", tmpRoot->v);
        InOrder(tmpRoot->rightChild);
    }
}

void PostOrder(NODE* tmpRoot)
{
    if (tmpRoot != NULL)
    {
        PostOrder(tmpRoot->leftChild);
        PostOrder(tmpRoot->rightChild);
        printf("%d ", tmpRoot->v);
    }
}

void DestroyTree(NODE* tmpRoot)
{
    if (tmpRoot != NULL)
    {
        NODE* leftChild = tmpRoot->leftChild;
        NODE* rightChild = tmpRoot->rightChild;
        free(tmpRoot);
        tmpRoot = NULL;
        DestroyTree(leftChild);
        DestroyTree(rightChild);
    }
}

int main()
{
    while (0 == 0)
    {
        char line[1024] = { 0 };
        char command[1024] = { 0 };
        int u = 0, v = 0;
        fgets(line, sizeof(line) - 1, stdin);
        if (strstr(line,"*") != NULL)
            break;
        else
        {
            if (strstr(line,"MakeRoot"))
            {
                sscanf(line,"%s%d",command, &u);
                MakeRoot(u);
            }else if (strstr(line,"AddLeft"))
            {
                sscanf(line,"%s%d%d",command, &u, &v);
                AddLeft(u, v);
            }else if (strstr(line,"AddRight"))
            {
                sscanf(line,"%s%d%d",command, &u, &v);
                AddRight(u, v);
            }else if (strstr(line,"PreOrder"))
            {
                PreOrder(pRoot);
                printf("\n");
            }else if (strstr(line,"InOrder"))
            {
                InOrder(pRoot);
                printf("\n");
            }else if (strstr(line,"PostOrder"))
            {
                PostOrder(pRoot);
                printf("\n");
            }
        }
    }
}
