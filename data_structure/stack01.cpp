#include <iostream>
/* 用單向鏈結串列實作 堆疊 */
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

class stack{

public:
    Node *top;
    Node *bottom;

    int MAX_ITEMS; // 定義最大堆疊數目
    int n_height; // 定義目前堆疊高度

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
    void pop();
    void printstack();


};
void stack::push(int item){
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
    }
    // 高度<MAX_ITEMS, 新節點可以插入 top後：
    if(this->n_height < MAX_ITEMS){
        this->top->next = current; // 這邊 n_height=1時有邏輯問題!
        
        this->top = current;
    }
    // 節點推入動作結束, 高度+1：
    this->n_height = this->n_height + 1; 
    return;
}
void stack::pop(){
    if(this->n_height == 0){
        cout << "[pop] Warning! STACK is empty!" << '\n';
        return;
    }


    this->n_height = this->n_height - 1;
    return;
}
void stack::printstack(){
    if(this->n_height == 0){
        cout << "[pop] Warning! STACK is empty!" << '\n';
        return;
    }
    // int i=0;
    // Node *current;
    // current = this->bottom;
    cout << "bottom= " << this->bottom << ",bottom.data= " << this->bottom->data << ",bottom.next= " << this->bottom->next << '\n';
    // while(current->next != NULL){

    //     cout << i << ", addr= " << &current->data << ", data= " << current->data << ", next= " << current->next << '\n';
    //     current = current->next;
    //     i=i+1; 
    // }
    cout << "top= " << this->top << ", top.data= " << this->top->data << ", top.next= " << this->top->next << '\n';
    cout << "STACK height= "<< this->n_height << '\n';
    return;
}

int main(){
    stack mystack01(10);
    
    for(int i=1; i<11; i++){
        mystack01.push(i);
        mystack01.printstack();
    }
    return 0L;
}