#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct db{
    char name[21];
    char tel[16];
    char email[25];
}db;
struct list{
    db el;
    struct list *next;
};
typedef struct list node;
node *root;
node *cur;
node *prev;
node *makenewnode(){
    node *new= (node*) malloc(sizeof(node));
    strcpy((new->el).name, "Le Thanh An");
    strcpy((new->el).email,"lethanhan2005@gmail.com");
    strcpy((new->el).tel,"0865797312");
    new-> next =NULL;
    return new;
}
node *makenewnode(db a){
    node *new= (node*) malloc(sizeof(node));
    new->el =a;
    new-> next =NULL;
    return new;
}
db readnote(){
    db tmp;
    printf("input");
    gets(tmp.name);
    gets(tmp.email);
    gets(tmp.tel);
    return tmp;
}
void displaynode(node* p){
    if(p == NULL){printf("error");
    return;}
    db tmp = p->el;
    printf("%-20s\t%-15s\t%-25s%-p\n",tmp.name,tmp.email,tmp.tel,p->next);
}
void main(){
    db tmp = readnote();
    root = makenewnode(tmp);
    displaynode(root);
}
