#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX_STACK_SIZE = 10; // Maximum size of each stack
class Stack {
private: //access modifier
    int *arr; // field, data member, member data, attribute 
    int top; // Index of the top element in the stack
public:
    int getSize(){ //getter
        return top+1;
    }
    Stack() : top(-1) {
        arr = new int[MAX_STACK_SIZE];
    }
    Stack(int size) {
        arr=new int[size];
        top=-1;    
    }
    Stack(Stack& s) {
        arr = new int[MAX_STACK_SIZE];
        top = -1;
        push(s.peek());
    }
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
            cout << "Stack is empty!";
            return;
        }
        cout << "Elements in the stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        //cout << "\n";
    }
    Stack& operator << (int data) {
        (*this).push(data);
        (*this).push(data*2);
        return *this;
    }
    //this part is unfinished
    //  ------------------------
    int operator << (Stack& s) {
        top = -1;
        s.top=-1;
    //    (*this).push(s);
    //    //(*this).push(data*2);
        return top;
    }
    //--------------------------
    Stack& operator -() {
        if (!is_empty()) {
            arr[top] = -arr[top];
            //(*this).pop();
        }
        return *this;
    }
};
ostream& operator<<(ostream &os, Stack &s) {
    cout <<s.getSize() << " elements [";
    s.print_stack();
    cout << "]\n";
    return os;
}
//Stack& operator<<(Stack& s, int data) {
//    s.push(data);
//    return s;
//}
int main() {
    // Create three stacks
    Stack s1, s2(500);
    s1 << 1 << 2 << 3 << 4;
    s2 << 5;
    cout << s1 << s2;
    s1 << s2 << 3;
    cout << s1 << s2;
   /* -s1;
    Stack s3(s1);
    cout << s3;*/
    return 0;
}