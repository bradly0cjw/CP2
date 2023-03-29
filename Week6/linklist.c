//
// Created by LINBEI on 3/29/2023.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next;
};

int main() {
    //  Step 1
    struct Node *head = 0;
    //  Step 2
    head = (struct Node *) malloc(sizeof(struct Node));
    //  head = new Node;
    head->data = '1';
    head->next = 0;
    //  Step 3
    struct Node *t = head;
    head = (struct Node *) malloc(sizeof(struct Node));
    head->data = '2';
    head->next = t;
    //  Step 4
    t = head->next;
    free(t);
    head = t;
}