//
// Created by LINBEI on 4/19/2023.
//
//#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node*left,*right;
    Node(int num){
        data=num;
        left=right=0;
    };
};

int main(){
    Node*tree=0;
    tree=new Node(1);
    tree->left=new Node(2);
    tree->right=new Node(3);
}