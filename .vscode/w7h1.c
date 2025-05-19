#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong danh sách liên kết
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addFirst(Node** head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
    } else {
        Node* newNode = createNode(data);
        newNode->next = *head;
        *head = newNode;
    }
}

void addLast(Node** head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createNode(data);
    }
}

void addAfter(Node* head, int u, int v) {
    Node* temp = head;
    while (temp != NULL && temp->data != v) {
        temp = temp->next;
    }
    if (temp != NULL) {
        Node* newNode = createNode(u);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void addBefore(Node** head, int u, int v) {
    if (*head == NULL) return;
    if ((*head)->data == v) {
        addFirst(head, u);
        return;
    }
    Node* prev = NULL;
    Node* curr = *head;
    while (curr != NULL && curr->data != v) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) {
        Node* newNode = createNode(u);
        prev->next = newNode;
        newNode->next = curr;
    }
}

void removeNode(Node** head, int k) {
    if (*head == NULL) return;
    if ((*head)->data == k) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL && temp->next->data != k) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

void reverse(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value;
    scanf("%d", &n);
    Node* head = NULL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        addLast(&head, value);
    }

    char command[20];
    int u, v;
    while (scanf("%s", command) && command[0] != '#') {
        if (strcmp(command, "addlast") == 0) {
            scanf("%d", &u);
            addLast(&head, u);
        } else if (strcmp(command, "addfirst") == 0) {
            scanf("%d", &u);
            addFirst(&head, u);
        } else if (strcmp(command, "addafter") == 0) {
            scanf("%d %d", &u, &v);
            addAfter(head, u, v);
        } else if (strcmp(command, "addbefore") == 0) {
            scanf("%d %d", &u, &v);
            addBefore(&head, u, v);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%d", &u);
            removeNode(&head, u);
        } else if (strcmp(command, "reverse") == 0) {
            reverse(&head);
        }
    }

    printList(head);
    return 0;
}
