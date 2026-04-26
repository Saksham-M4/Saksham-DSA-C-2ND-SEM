// 5. Singly Linked List Operations
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int val) {
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int val) {
    struct Node *newNode = createNode(val);
    struct Node *temp = *head;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void deleteBeg(struct Node **head) {
    struct Node *temp;

    if(*head == NULL)
        return;

    temp = *head;
    *head = (*head)->next;
    free(temp);
}

void search(struct Node *head, int key) {
    while(head != NULL) {
        if(head->data == key) {
            printf("Found\n");
            return;
        }
        head = head->next;
    }
    printf("Not Found\n");
}

void display(struct Node *head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    display(head);

    deleteBeg(&head);
    display(head);

    search(head, 20);

    return 0;
}