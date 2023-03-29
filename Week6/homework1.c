//
// Created by LINBEI on 3/29/2023.
//
#include <stdio.h>


//int main(){
//    int a=10,b=20,swap;
//    int *p,*q;
//    int sum,diff,product,quotient;
//    p=&a;
//    q=&b;
//    swap=*p;
//    *p=*q;
//    *q=swap;
//    sum=*p+*q;
//    diff=*p-*q;
//    product=*p*(*q);
//    quotient=*p/(*q);
//    printf("%d %d %d %d %d %d",*p,*q,sum,diff,product,quotient);
//}

int main() {
    int arr[10],sum=0;
    for (int i = 0, j = 2; i < 10; i++, j += 2) {
        if (i % 2 == 0)
            arr[i] = j;
        else
            arr[i] = -j;
    }
    int* p=&arr[0];
    for (int i = 0;i<10;i++) {
        sum += *(p + i);
    }
    int max=arr[0],min=arr[0];
    for (int i = 0;i<10;i++) {
        if (*(p + i)>max){
            max=*(p+i);
        }else if(*(p + i)<min){
            min=*(p+i);
        }
    }
    printf("%d %d %d",sum,min,max);
}