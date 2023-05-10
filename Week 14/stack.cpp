//
// Created by LINBEI on 5/10/2023.
//
#include <iostream>
using namespace std;
#define DEFAULT_STACK_SIZE 10
class Stack{
private:
    int top;
    int *arr;
public:
    Stack() : top(-1) {
        arr=new int[DEFAULT_STACK_SIZE];
    }
    Stack(int size) : top(-1) {
        if (size<=0){
            cout<<"Invalid stack size\n";
            exit(EXIT_FAILURE);
        }
        arr=new int[size];
    }
    Stack(const Stack& s): top(s.top){
        arr=new int[DEFAULT_STACK_SIZE];
        for (int i=0;i<=top;i++){
            arr[i]=s.arr[i];
        }

    }
    // Function to check if the stack is empty
    bool is_empty() { // function member, operation, method
        return top == -1;
    }
    // Function to check if the stack is full
    bool is_full() {
        return top == DEFAULT_STACK_SIZE - 1;
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
    friend Stack& operator+=(Stack& s, const Stack& t);
};
    Stack& operator<<(Stack&s,int data){
        s.push(data);
        return s;
    }
    ostream& operator<<(ostream&os,Stack&s){
        s.print_stack();
        return os;
    }
    Stack& operator~(Stack&s){
        s.peek();
        return s;
    }
    Stack& operator-(Stack&s){
        s.pop();
        return s;
    }
    Stack& operator+=(Stack& s, const Stack& t) {
    int newSize = s.top + t.top + 2;
    int* newArr = new int[newSize];
    int i;

    for (i = 0; i <= s.top; i++) {
        newArr[i] = s.arr[i];
    }

    for (int j = 0; j <= t.top; j++) {
        newArr[i++] = t.arr[j];
    }

    delete[] s.arr;
    s.arr = newArr;
    s.top = newSize - 2;

    return s;
}
    Stack& operator!(Stack&s){
        while(!s.is_empty()){
            s.pop();
        }
        cout<<"Stack is empty\n";
        return s;
    }
    Stack& operator<<(Stack&t,Stack&s){
        int popitem;
        while(!s.is_empty()){
            popitem=s.pop();
            t.push(popitem);
        }
        return t;
    }

int main(){
    int m=5;
    Stack s1,s2(m),s3(s1);  //overloading constructors
    cout<<s1<<s2<<s3;       //display the stack element
    s1<<1<<2<<3;            //<<:  push element
    s2<<8<<9;               // overloading <<
    s3=s2+=s1<<4;           //+=: copy content to other stack
    cout<<s1<<s2<<s3;
    cout<<-s1<<-s2<<-s3;    // -:pop
    cout<<s1<<s2<<s3;
    cout<<~s1<<~s2<<5;       // ~: peek
    !s1;                    // empty stack
    s1<<0<<s2;              // overloading <<
    cout<<s1<<(s2<<-1)<<s3;
    return 0;

}
