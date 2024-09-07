#include <iostream>
/* 用單向鏈結串列實作 堆疊 */
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

class stack{
private:
    int n_height; // 定義目前堆疊高度

public:
    Node *top;
    Node *bottom;

    int MAX_ITEMS; // 定義最大堆疊數目

    // 宣告建構函數：
    stack(int MAX_HEIGHT){
        // USER指定堆疊物件高度 MAX_HEIGHT
        // 初始化：
        this->top = NULL;
        this->bottom = NULL;
        this->MAX_ITEMS = MAX_HEIGHT;
        this->n_height = 0;
        return;
    }

    void push(int);
    Node *pop();
    void printstack();
    int getsize();
    int peek(); // 不 pop out堆疊, 取 top的值.
};
void stack::push(int item){
    // stack01.cpp中的串列 top相當於是串列尾巴... 反而造成 stack的 pop操作麻煩:
    Node *current = new Node;
    current->data = item;
    current->next = NULL;
    // 若高度已經 > MAX_ITEMS
    if(this->n_height >= this->MAX_ITEMS){
        cout << "[push] Warning! STACK is full! The item [ " <<  current->data << "] u inputed will be discard!" << '\n';
        delete current;
        return;
    }
    // 堆疊高度為 0且 bottom為空, 將 top, bottom皆指定為新節點：
    if(this->bottom == NULL && this->n_height == 0){
        this->bottom = current;
        this->top = current;
        this->n_height = this->n_height + 1; 
        return;
    }
    // 高度<MAX_ITEMS, 新節點可以插入 top後：
    if(this->n_height < MAX_ITEMS){
        current->next = this->top;
        this->top = current;
    }
    // 節點推入動作結束, 高度+1：
    this->n_height = this->n_height + 1; 
    return;
}
Node* stack::pop(){
    Node *pop_ptr=NULL;
    // 若堆疊高度已經為 0 或 top已經為空的就跳出.
    if(this->n_height == 0 || this->top == NULL){
        cout << "[pop] Warning! STACK is empty!" << '\n';
        return pop_ptr;
    }
    // 判斷若已經到最底 top->next為 NULL, 直接刪掉 top指向的節點, 並把串列指標 top指向 NULL
    if(this->top->next==NULL){
        pop_ptr = this->top;
        delete this->top;
        this->top=NULL;
    }else
    {
        Node *current;
        current = this->top;

        pop_ptr = current;
        this->top = current->next;
        delete current;
    }
    this->n_height = this->n_height - 1;
    return pop_ptr;
}
void stack::printstack(){
    if(this->n_height == 0){
        cout << "[pop] Warning! STACK is empty!" << '\n';
        return;
    }
    int i=0;
    Node *current;
    current = this->top;
    cout << "top= " << this->top << '\n';
    while(current != NULL){

        cout << this->n_height - i << ", addr= " << &current->data << ", data= " << current->data << ", next= " << current->next << '\n';
        current = current->next;
        i=i+1; 
    }
    cout << "bottom= " << this->bottom <<'\n';
    return;
}
int stack::getsize(){
    return this->n_height;
}
int stack::peek(){
    return this->top->data;
}

int main(){
    stack mystack01(10);
    
    for(int i=1; i<11; i++){
        mystack01.push(i);
        mystack01.printstack();
    }
    cout << "STACK height= "<< mystack01.getsize() << '\n';
    cout << "peek the top value= " << mystack01.peek() << '\n';
    cout << "=====" << '\n';
    Node *result=NULL;
    for(int i=1; i<4; i++){
        result = mystack01.pop();
        cout << "pop out= " << result<< '\n';
        cout << "peek the top value= " << mystack01.peek() << '\n';
    }
    
    mystack01.printstack();
    cout << "STACK height= "<< mystack01.getsize() << '\n';

    return 0L;
}