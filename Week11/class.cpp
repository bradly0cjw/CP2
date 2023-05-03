//
// Created by LINBEI on 5/3/2023.
//
#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX_STACK_SIZE = 5; // Maximum size of each stack
class Stack {
private: //access modifier
    int arr[MAX_STACK_SIZE]; // field, data member, member data, attribute
    int top; // Index of the top element in the stack
public:
    Stack() : top(-1) {}
    // Function to check if the stack is empty
    bool is_empty() { // function member, operation, method
        return top == -1;
    }
    // Function to check if the stack is full
    bool is_full() {
        return top == MAX_STACK_SIZE - 1;
    }
    // Function to push an element onto the stack
    void push(int element) {
        if (is_full()) {
            cout << "Stack overflow error!\n";
            exit(EXIT_FAILURE);
        }
        arr[++top] = element;
    }
    // Function to pop an element from the stack
    int pop() {
        if (is_empty()) {
            cout << "Stack underflow error!\n";
            exit(EXIT_FAILURE);
        }
        return arr[top--];
    }
    // Function to peek at the top element in the stack
    int peek() {
        if (is_empty()) {
            cout << "Stack is empty!\n";
            exit(EXIT_FAILURE);
        }
        return arr[top];
    }
    // Function to print the elements in the stack
    void print_stack() {
        if (is_empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Elements in the stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};
int main() {
    // Create three stacks
    Stack s1, s2, s3;


    // Push elements onto the first stack
    s1.push(1);
    s1.push(2);
    s1.push(3);
    return 0;
}