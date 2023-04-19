//
// Created by LINBEI on 4/19/2023.
//
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*left,*right;
};
int main(){
    struct Node*tree=0;
    tree=(struct Node*)malloc(sizeof(struct Node));
    tree->data=1;
    tree->left=tree->right=0;
    tree->left=(struct Node*)malloc(sizeof(struct Node));
    tree->left->data=2;
    tree->left=tree->left=tree->right=0;
}