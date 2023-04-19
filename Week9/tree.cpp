//
// Created by LINBEI on 4/19/2023.
//
//#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node*left,*right;
    Node(){
        data=0;
        left=right=0;
    };
    Node(int num){
        data=num;
        left=right=0;
    };
};

int main(){
    Node*tree=0,*ptr;
    tree=new Node(1);
    ptr=new Node(2);
    tree->left=ptr;
    ptr=tree;
    ptr=new Node(3);
    tree->right=ptr;
}