#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    char id[7];
    char name[20];
    char lv[10];
    struct node* next;
} node;

node *head = NULL;
node *tail = NULL;

node *makeNode(char id[7], char name[20], char lv[10]){
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->id, id);
    strcpy(newNode->name, name);
    strcpy(newNode->lv, lv);
    newNode->next = NULL;
    return newNode;
}

void CreatQ(){
    head = NULL;
    tail = NULL;
}

void insert(char id[7], char name[20], char lv[10]){
    node *newNode = makeNode(id, name, lv);
    if(tail == NULL){
        tail = newNode;
        head = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

void print(){
    if(head == NULL){
        printf("EMPTY\n");
        return;
    }

    node *tmp = head;
    while(tmp != NULL){
        printf("%s %s %s\n", tmp->id, tmp->name, tmp->lv);
        tmp = tmp -> next;
    }
}

node *findNode(char lv[]){
    node *tmp = head;
    while(tmp != NULL){
        if(strcmp(tmp->lv, "VIP") == 0)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}


void vip(){
    while(1){
        node *tmp = findNode("VIP");
        if(tmp == NULL){
            break;
        }
        if(tmp == head){
            head = head->next;
        }else{
            node *pr = head;
            while(pr->next != tmp){
                pr = pr->next;
            }
            pr->next = tmp->next;
            if(tmp == tail){
                tail = pr;
            }
        }
        free(tmp);
    }
}


int gold(){
    int cnt = 0;
    node *tmp = head;
    while(tmp != NULL){
        if(strcmp(tmp->lv, "GOLD") == 0){
            ++cnt;
        }
        tmp = tmp->next;
    }
    return cnt;
}

void serve(){
    node *tmp = head;
    if(head == NULL)
        return;
    head = head->next;
    if(head == NULL)
        tail = NULL;
    printf("%s %s %s\n", tmp->id, tmp->name, tmp->lv);
    free(tmp);
}

int main(){
    char s[50];
    char id[7];
    char name[20];
    char lv[10];
    while(1){
        scanf("%s", s);
        if(strcmp(s, "#") == 0)
            break;

        if(strcmp(s, "CreatQueue") == 0){
            CreatQ();
        }else if(strcmp(s, "Print") == 0){
            print();
        }else if(strcmp(s, "Insert") == 0){
            scanf("%s %s %s", id, name, lv);
            insert(id, name, lv);
        }else if(strcmp(s, "Vip") == 0){
            vip();
        }else if(strcmp(s, "Gold") == 0){

            int tmp = gold();
            if(tmp == 0){
                printf("NO GOLD\n");
            }
            else{
                printf("%d\n", tmp);
            }

        }else if(strcmp(s, "Serve") == 0){
            serve();
        }

    }
    return 0;
}
