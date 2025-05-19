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
    struct _node* next;
}NODE;

NODE* pRoot = NULL;
NODE* pHead = NULL;
NODE* pTail = NULL;
int QUEUE_LENGTH = 0;

void Enqueue(NODE* newNode)
{
    QUEUE_LENGTH += 1;
    if (pTail != NULL)
    {
        pTail->next = newNode;
        pTail = newNode;
    }else
    {
        pHead = newNode;
        pTail = newNode;
    }
}

NODE* Dequeue()
{
    if (pHead != NULL)
    {
        QUEUE_LENGTH -= 1;
        NODE* tmp = pHead;
        pHead = pHead->next;
        if (pHead == NULL)
        {
            pTail = NULL;
        }
        return tmp;
    }else
        return NULL;
}

int IsQueueEmpty()
{
    return pHead == NULL;
}

NODE* CreateNode(int k)
{
    NODE* newNode = (NODE*)calloc(1, sizeof(NODE));
    newNode->v = k;
    newNode->leftMostChild = NULL;
    newNode->rightSibling = NULL;
    newNode->parent = NULL;
    newNode->next = NULL;
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

        Enqueue(pRoot);
        int stop = 0;
        while (stop == 0)
        {
            int n = QUEUE_LENGTH;
            while (n > 0)
            {
                NODE* tmpNode = Dequeue();
                n--;
                NODE* tmpChild = tmpNode->leftMostChild;
                int found = 0;
                while (tmpChild != NULL)
                {
                    if (tmpChild->v == k)
                    {
                        stop = 1;
                        found = 1;
                        break;
                    }
                    tmpChild = tmpChild->rightSibling;
                }
                if (found == 0)
                {
                    NODE* tmpChild = tmpNode->leftMostChild;
                    while (tmpChild != NULL)
                    {
                        Enqueue(tmpChild);
                        tmpChild = tmpChild->rightSibling;
                    }
                }
            }
        }

        while (!IsQueueEmpty())
        {
            NODE* tmpNode = Dequeue();
            printf("%d ", tmpNode->v);
        }

        DestroyTree(pRoot);
    }
}
