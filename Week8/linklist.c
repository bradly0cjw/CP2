#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* node) {
    while (node != NULL) {
        printf(" ->%d", node->data);
        node = node->next;
    }
    printf(" ->@\n");
}

void insertAtFront(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

void deleteAtFront(struct Node** headRef) {
    if (*headRef == NULL)
        return;
    struct Node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
}

int main() {
    struct Node* head = NULL;
    printList(head);

    insertAtFront(&head, 3);
    insertAtFront(&head, 2);
    insertAtFront(&head, 1);

    printList(head);

    deleteAtFront(&head);

    printList(head); 

    return 0;
}