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

typedef struct _info
{
    int h;
    int h1;
    int h2;
}INFO;

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

INFO Height(NODE* tmp)
{
    INFO result;
    if (tmp == NULL)
    {
        result.h = 0;
        result.h1 = 0;
        result.h2 = 0;
        return result;
    }
    else
    {
        NODE* leftMostChild = tmp->leftMostChild;
        if (leftMostChild != NULL)
        {
            int maxD1 = -1;
            int maxD2 = -1;
            while (leftMostChild != NULL)
            {
                INFO tmpD = Height(leftMostChild);
                if (tmpD.h > maxD1)
                {
                    maxD2 = maxD1;
                    maxD1 = tmpD.h;
                }
                leftMostChild = leftMostChild->rightSibling;
            }
            result.h = maxD1 + 1;
            result.h1 = maxD1;
            result.h2 = maxD2;
            return result;
        }else
        {
            result.h = 1;
            result.h1 = 0;
            result.h2 = 0;
            return result;
        }
    }
}

void DrawTree(NODE* tmpRoot, char* prefix)
{
    if (tmpRoot != NULL)
    {
        printf("%s+---%d\n", prefix, tmpRoot->v);

        char newPrefix[1024] = { 0 };
        if (tmpRoot->rightSibling == NULL)
            sprintf(newPrefix,"%s    ", prefix);
        else
            sprintf(newPrefix,"%s|   ", prefix);

        NODE* tmpChild = tmpRoot->leftMostChild;
        while (tmpChild != NULL)
        {
            DrawTree(tmpChild, newPrefix);
            tmpChild = tmpChild->rightSibling;
        }
    }
}

int Diameter(NODE* tmpRoot)
{
    if (tmpRoot != NULL)
    {
        INFO result = Height(tmpRoot);
        int d = result.h1 + result.h2 + 1;
        NODE* tmpChild = tmpRoot->leftMostChild;
        while (tmpChild != NULL)
        {
            int tmpD = Diameter(tmpChild);
            if (tmpD > d)
                d = tmpD;
        }
        return d;
    }else
        return 0;
}

int main()
{
    int k = 0;
    char line[1024] = { 0 };
    fgets(line, sizeof(line) - 1, stdin);
    sscanf(line,"%d", &k);
    while (0 == 0)
    {
        fgets(line, sizeof(line) - 1, stdin);
        if (strstr(line,"$$") != NULL)
            break;
        else
        {
            char* tmp = line;
            int v = 0;
            sscanf(tmp, "%d", &v);
            tmp = strstr(tmp," ") + 1;
            if (pRoot == NULL)
            {
                pRoot = CreateNode(v);
            }
            while (tmp[0] != '$')
            {
                int u = 0;
                sscanf(tmp, "%d", &u);
                tmp = strstr(tmp," ") + 1;
                Insert(u, v);
            }
        }
    }

    if (pRoot != NULL)
    {
        printf("%d\n", pRoot->v);
        NODE* pChild = pRoot->leftMostChild;
        while (pChild != NULL)
        {
            DrawTree(pChild, "");
            pChild = pChild->rightSibling;
        }

        printf("\n%d\n", Diameter(pRoot));
        DestroyTree(pRoot);
    }
}
