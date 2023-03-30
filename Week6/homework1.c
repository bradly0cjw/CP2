//
// Created by LINBEI on 3/29/2023.
//

//#include <stdio.h>
//int main(){
//    int a=10,b=20,swap; //A
//    int *p,*q;
//    int sum,diff,product,quotient;
//    p=&a; //B
//    q=&b;
//    swap=*p; //C
//    *p=*q;
//    *q=swap;
//    sum=*p+*q; //D
//    diff=*p-*q;
//    product=*p*(*q);
//    quotient=*p/(*q);
//    printf("%d %d %d %d %d %d",*p,*q,sum,diff,product,quotient); //E
//}

//#include <stdio.h>
//int main() {
//    int arr[10],sum=0; //A
//    for (int i = 0, j = 2; i < 10; i++, j += 2) {
//        if (i % 2 == 0)
//            arr[i] = j;
//        else
//            arr[i] = -j;
//    }
//    int* p=&arr[0]; //B
//    for (int i = 0;i<10;i++) { //C
//        sum += *(p + i);
//    }
//    int max=arr[0],min=arr[0];
//    for (int i = 0;i<10;i++) { //D
//        if (*(p + i)>max){
//            max=*(p+i);
//        }else if(*(p + i)<min){
//            min=*(p+i);
//        }
//    }
//    printf("%d %d %d",sum,min,max); // E
//}

#include <stdio.h>
#include <stdlib.h>

struct Node{ //A
    int data;
    struct Node *next;
};
int main(){
    struct Node* head=NULL;
    struct Node* second=NULL;
    head=(struct Node*)malloc(sizeof (struct Node)); //B
    second=(struct Node*)malloc(sizeof(struct Node));
    head->data=1; //C
    second->data=2;
    head->next=second; //D
    second->next=NULL;
    struct Node* temp = head;
    while (temp != NULL) { //E
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    temp=head; //F
    head=head->next;
    free(temp);
    temp=head;
    while(temp!=NULL){ //G
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    free(head);
    return 0;
}