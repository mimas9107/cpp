#include <iostream>

using namespace std;
/// 以 Array來實作 Stack內的儲存結構.
#define MaxStackSize 100

class stack{
private:
    int stackarray[MaxStackSize];
    int top;

    bool isEmpty(){
        if(top<0){
            return true;
        }else{
            return false;
        }
    }
    bool isFull(){
        if(top>MaxStackSize-1){
            return true;
        }else{
            return false;
        }
    }
public:
    stack(){
        top=-1;
    }

    void push(int item){
        if(isFull()){
            cout << "Stack is full! " << '\n';
            return;
        }else{
            // top會從 -1開始 每次 push 就+1.
            stackarray[++top] = item;
        }
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack is Empty! " << '\n';
            return -1;
        }else{
            return stackarray[top--];
        }
    }
};

int main(){

    stack mystack;

    int result;
    for(int i=1; i<23; i++)
    {
        mystack.push(i);
    }

    for(int i=1; i<3; i++)
    {
        result = mystack.pop();
        cout << "pop out data= " << result << '\n';
    }
    return 0L;
}