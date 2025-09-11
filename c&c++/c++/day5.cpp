#include<iostream>
using namespace std;

class Stack{
    private:
        int top;
        int stack[7];
        int capacity;

    public:
        Stack(){
            top=-1;
            capacity=7;
        }

        bool isFull(){
            return top==capacity-1;
        }

        bool isEmpty(){
            return top==-1;
        }

        void push(int value){
            if(isFull()){
                cout<<"Stack overflow"<<endl;
            }
            else{
                top++;
                stack[top]=value;
                cout<<value<<" pushed into stack"<<endl;
            }
        }

        void peek(){
            cout<<stack[top]<<endl;
        }

        void pop(){
            if(isEmpty()){
                cout<<"Stack underflow"<<endl;
            }
            else{
                cout<<stack[top]<<" popped from stack"<<endl;
                top--;
            }
        }

        void displayStack(){
            if(isEmpty()){
                cout<<"Stack underflow"<<endl;
            }
            else{
                for(int i=top;i>=0;i--){
                    cout<<stack[i]<<" ";
                }
            }
        }
};

int main(){
    Stack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);
    stk.push(70);

    stk.push(80);

    stk.displayStack();
    stk.isEmpty();
    stk.isFull();
    stk.peek();
    stk.pop();
    stk.displayStack();

    return 0;
};