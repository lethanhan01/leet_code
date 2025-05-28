#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct _contact
{
    char name[32];
    char tel[32];
    char email[32];
    struct _contact* next;
}CONTACT;
CONTACT* pListContacts = NULL;
CONTACT* pPrevious = NULL;

void HuyDS()
{
    if (pListContacts != NULL)
    {
        CONTACT* tmp = pListContacts;
        while (tmp != NULL)
        {
            CONTACT* next = tmp->next;
            free(tmp);
            tmp = next;
        }
    }
}

void HienDS()
{
    if (pListContacts != NULL)
    {
        CONTACT* tmp = pListContacts;
        while (tmp != NULL)
        {
            printf("%s\n%s\n%s\n", tmp->name, tmp->tel, tmp->email);
            tmp = tmp->next;
        }
    }
}

void ThemPT()
{
    char tmpName[32] = { 0 };
    char tmpTel[32] = { 0 };
    char tmpEmail[32] = { 0 };
    printf("Name: "); 
    fgets(tmpName, sizeof(tmpName), stdin);
    tmpName[strcspn(tmpName, "\n")] = 0; // Remove newline character
    printf("Tel: "); 
    fgets(tmpTel, sizeof(tmpTel), stdin);
    tmpTel[strcspn(tmpTel, "\n")] = 0; // Remove newline character
    printf("Email: ");
    fgets(tmpEmail, sizeof(tmpEmail), stdin);
    tmpEmail[strcspn(tmpEmail, "\n")] = 0; // Remove newline character

    CONTACT* newNode = calloc(1, sizeof(CONTACT));
    strcpy(newNode->name, tmpName);
    strcpy(newNode->tel, tmpTel);
    strcpy(newNode->email, tmpEmail);
    newNode->next = NULL;

    if (pListContacts == NULL)
        pListContacts = newNode;
    else
    {
        newNode->next = pListContacts;
        pListContacts = newNode;
    }
}

CONTACT* TimTel(const char* tel)
{
    pPrevious = NULL;
    if (pListContacts != NULL)
    {
        CONTACT* tmp = pListContacts;
        while (tmp != NULL)
        {
            if (strcmp(tmp->tel, tel) == 0)
                return tmp;
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

void ChenPT()
{
    char tmpName[32] = { 0 };
    char tmpTel[32] = { 0 };
    char tmpEmail[32] = { 0 };
    printf("Name: "); 
    fgets(tmpName, sizeof(tmpName), stdin);
    tmpName[strcspn(tmpName, "\n")] = 0; // Remove newline character
    printf("Tel: "); 
    fgets(tmpTel, sizeof(tmpTel), stdin);
    tmpTel[strcspn(tmpTel, "\n")] = 0; // Remove newline character
    printf("Email: "); 
    fgets(tmpEmail, sizeof(tmpEmail), stdin);
    tmpEmail[strcspn(tmpEmail, "\n")] = 0; // Remove newline character

    CONTACT* newNode = calloc(1, sizeof(CONTACT));
    strcpy(newNode->name, tmpName);
    strcpy(newNode->tel, tmpTel);
    strcpy(newNode->email, tmpEmail);
    newNode->next = NULL;

    memset(tmpTel, 0, sizeof(tmpTel));
    printf("After Tel: "); 
    fgets(tmpTel, sizeof(tmpTel), stdin);
    tmpTel[strcspn(tmpTel, "\n")] = 0; // Remove newline character
    CONTACT* tmp = TimTel(tmpTel);
    if (tmp != NULL)
    {
        if (tmp->next == NULL)
        {
            tmp->next = newNode;
        }else
        {
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
    }else
    {
        printf("Tel not found!\n");
        free(newNode);
        newNode = NULL;
    }
}

void XoaPT()
{
    char tmpTel[32] = { 0 };
    printf("Tel to remove: "); 
    fgets(tmpTel, sizeof(tmpTel), stdin);
    tmpTel[strcspn(tmpTel, "\n")] = 0; // Remove newline character
    CONTACT* tmp = TimTel(tmpTel);
    if (tmp != NULL)
    {
        if (pPrevious == NULL)
        {
            pListContacts = tmp->next;
            free(tmp);
            tmp = NULL;
        }else
        {
            pPrevious->next = tmp->next;
            free(tmp);
            tmp = NULL;
        }
    }else
        printf("Tel not found!\n");
}

void DaoDS()
{
    CONTACT* p1 = pListContacts;
    if (p1 != NULL)
    {
        CONTACT* p2 = p1->next;
        while (p2 != NULL)
        {
            CONTACT* p3 = p2->next;
            p2->next = p1;
            if (p1 == pListContacts)
            {
                p1->next = NULL;
            }
            p1 = p2;
            p2 = p3;
        }
        pListContacts = p1;
    }
}

int main()
{
    int menu = 0;
    while (0 == 0)
    {
        printf("1. Them phan tu vao dau\n");
        printf("2. Them phan tu vao sau mot so hien tai\n");
        printf("3. Hien danh sach\n");
        printf("4. Xoa mot so lien lac\n");
        printf("5. Dao nguoc danh sach\n");
        printf("6. Thoat\n");
        scanf("%d", &menu);
        if (menu == 1)
            ThemPT();
        else if (menu == 2)
            ChenPT();
        else if (menu == 3)
            HienDS();
        else if (menu == 4)
            XoaPT();
        else if (menu == 5)
            DaoDS();
        else if (menu == 6)
        {
            HuyDS();
            break;
        }
        else
            printf("Chon sai menu.\n");

    }
}
