//
// Created by LINBEI on 3/29/2023.
//

// Problem 1
#include <stdio.h>
int main(){
    // A
    int a = 10, b = 20, swap; 
    int *p, *q;
    int sum, diff, product, quotient;
    // B
    *p = &a; 
    *q = &b;
    // C
    swap = *p; 
    *p = *q;
    *q = swap;
    // D
    sum = *p + *q; 
    diff = *p - *q;
    product = *p * (*q);
    quotient = *p / (*q);
    // E
    printf("a = %d b = %d\nSum = %d Diff = %d Product = %d Quotient = %d\n", *p, *q, sum, diff, product, quotient); 
}

// Problem 2
#include <stdio.h>
int main(){
    // A
    int arr[10], sum = 0; 
    for (int i = 0, j = 2; i < 10; i++, j += 2){
        if (i % 2 == 0){
            arr[i] = j;
        }
        else{
        arr[i] = -j;
        }
    }
    // B
    int *p = &arr[0]; 
    // C
    for (int i = 0; i < 10; i++){ 
        sum += *(p + i);
    }
    int max = arr[0], min = arr[0];
    // D
    for (int i = 0; i < 10; i++){ 
        if (*(p + i) > max){
            max = *(p + i);
        }
        else if (*(p + i) < min){
            min = *(p + i);
        }
    }
    // E
    printf("Sum = %d min = %d max = %d\n", sum, min, max); 
}

// Problem 3
#include <stdio.h>
#include <stdlib.h>

// A
struct Node{ 
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    // B
    head = (struct Node *)malloc(sizeof(struct Node)); 
    second = (struct Node *)malloc(sizeof(struct Node));
    // C
    head->data = 1; 
    second->data = 2;
    // D
    head->next = second; 
    second->next = NULL;
    struct Node *temp = head;
    // E
    while (temp != NULL){ 
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    // F
    temp = head; 
    head = head->next;
    free(temp);
    temp = head;
    // G
    while (temp != NULL){ 
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    free(head);
    return 0;
}