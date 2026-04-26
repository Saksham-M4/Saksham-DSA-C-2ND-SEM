// C program for double linked list 
#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *prev;
struct node *next;
};
struct node *head = NULL;
// Insert at end
void insert(int data) {
struct node *newNode, *temp;
newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = data;
newNode->next = NULL;
newNode->prev = NULL;

if (head == NULL) {
head = newNode;
} else {
temp = head;
while (temp->next != NULL)
temp = temp->next;

temp->next = newNode;
newNode->prev = temp;
}
}
// Display list
void display() {
struct node *temp = head;
while (temp != NULL) {
printf("%d <-> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}
int main() {
insert(10);
insert(20);
insert(30);
display();
return 0;
}